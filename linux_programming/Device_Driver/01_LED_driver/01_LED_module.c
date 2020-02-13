/* This is the first version of LED character device driver */
/* In this version, device file is created automatically in init module,
   that means we don't need to use mknod command to create device file */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>       /* Header for file_operation struct */

#include <linux/sched.h>  	/* current and everything */
#include <linux/types.h>  	/* size_t */
#include <linux/delay.h>  	/* for delay function */

#include <linux/uaccess.h>  /* For copy to user function */

#include <linux/string.h>	/* Header for string function */

#include <linux/gpio.h> 	/* For the GPIO function */
#include <linux/gpio.h> 	/* For the IRQ code */

#include "ioctl_LED.h"		/* For ioctl definition */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PVBINH");

/* Define LED pin number */
#define LED_USR0_PIN	53U		/* GPIO1_21 => 1*32 + 24 = 53 */
#define LED_USR1_PIN	54U		/* GPIO1_22 => 1*32 + 24 = 54 */
#define LED_USR2_PIN	55U		/* GPIO1_23 => 1*32 + 24 = 55 */
#define LED_USR3_PIN	56U		/* GPIO1_24 => 1*32 + 24 = 56 */

#define LED_MAX_NUM		4

/* Define struct to control LED */
typedef struct
{
	unsigned int ledIndex;
	unsigned int ledPin;
	unsigned int ledState;
}LED_CONTROL_ST;

/* Define class name and device name pointer */
static struct class *class_name;
static struct device *device_name;

static dev_t dev;
static struct cdev my_cdev;

/* Define prototype function to add to file_operations struct */
static int my_led_open(struct inode *, struct file *);
static int my_led_close(struct inode *, struct file *);
static ssize_t my_led_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t my_led_write(struct file *, const char __user *, size_t, loff_t *);
static long my_led_ioctl(struct file *filep, unsigned int cmd, unsigned long arg);

static LED_CONTROL_ST st_arrLED[LED_MAX_NUM] =
{
	{0, LED_USR0_PIN, 0},
	{1, LED_USR1_PIN, 0},
	{2, LED_USR2_PIN, 0},
	{3, LED_USR3_PIN, 0},
};

/* Define file_operation srtuct */
static struct file_operations fops = {
	.open 		= my_led_open,
	.release 	= my_led_close,
	.read 		= my_led_read,
	.write 		= my_led_write,
	.unlocked_ioctl = my_led_ioctl
};

/* Init function is called when insmod kernel module */
static int __init my_led_init(void)
{
	int ret = 0;
	printk(KERN_ALERT "my_led_init\n");

	/*  Register a range of char device numbers

		dev: output parameter for first assigned number
		baseminor: first of the requested range of minor numbers
		count: the number of minor numbers required
		name: the name of the associated device or driver
	*/
	ret = alloc_chrdev_region(&dev, 0, 1, "gpio_module");
	if(ret != 0)
	{
		printk(KERN_ERR "Cannot alloc_chrdev_region\n");
		return ret;
	}

	/* After alloc successfully, we can get the major number */
	printk(KERN_ALERT "Major number is: %d\n", MAJOR(dev));

	/* Allocate a cdev structure  */
	cdev_init(&my_cdev, &fops);
	my_cdev.owner 	= THIS_MODULE;
	my_cdev.dev 	= dev;

	/* Add a char device to the system */
	ret = cdev_add(&my_cdev, dev, 1);
	if(ret < 0)
	{
		printk(KERN_ERR "cdev_add error\n");
		return ret;
	}

	/* Create a struct class pointer
	   That can then be used in calls to class_device_create. */
	class_name = class_create(THIS_MODULE, "gpio_module");
	if(IS_ERR(class_name))
	{
		printk(KERN_ERR "Create class failed\n");
		return -ENODEV;
	}

	/* A struct device will be created in sysfs, registered to the specified class. */
	/* A “dev” file will be created */
	device_name = device_create(class_name, NULL, dev, NULL, "led");
	if(IS_ERR(device_name))
	{
		printk(KERN_ERR "device_create failed\n");
		/* Clean the data when device create error */
		cdev_del(&my_cdev);
		class_destroy(class_name);
	}

	return 0;
}

/* Exit function is called when rmmod kernel module */
static void __exit my_led_exit(void)
{
	int i = 0;
	printk(KERN_ALERT "my_led_exit\n");
	/* Do the exit step by reverting init step */
	cdev_del(&my_cdev);
	device_destroy(class_name, dev);
	class_destroy(class_name);
	unregister_chrdev_region(dev, 1);

	for(i = 0; i < LED_MAX_NUM; ++i)
	{
		/* Deinit gpio for LED */
		gpio_set_value(st_arrLED[i].ledPin, 0); 	 /* Turn the LED off */
		gpio_unexport(st_arrLED[i].ledPin); 		 /* Unexport the LED GPIO */
	}
}

/* Called by application by open system call */
static int my_led_open(struct inode *inodep, struct file *filep)
{
	int i = 0;
	printk(KERN_ALERT "my_led_open\n");

	for(i = 0; i < LED_MAX_NUM; ++i)
	{
		/* Check GPIO pin valid or not */
		if(!gpio_is_valid(st_arrLED[i].ledPin))
		{
			printk(KERN_ALERT "GPIO: invalid LED GPIO\n");
			return -ENODEV;
		}

		/* Init gpio for LED */
		gpio_request(st_arrLED[i].ledPin, "sysfs");
		gpio_direction_output(st_arrLED[i].ledPin, 1);
		gpio_export(st_arrLED[i].ledPin, false);
	}

	return 0;
}

/* Called by application by close system call */
static int my_led_close(struct inode *inodep, struct file *filep)
{
	int i = 0;
	printk(KERN_ALERT "my_led_close\n");
	return 0;
}

/* Called by application by read system call */
static ssize_t my_led_read(struct file *filep, char __user *buff, size_t len, loff_t *offset)
{
	int i = 0;
	char ledStateStr[128] = "";
	char temp[32] = "";
	printk(KERN_ALERT "my_led_read\n");

	for (i = 0; i < LED_MAX_NUM; ++i)
	{
		snprintf(temp, sizeof(temp), "LED[%d] state[%d]\n", i, st_arrLED[i].ledState);
		strcat(ledStateStr, temp);
	}

	printk(KERN_ALERT "ledStateStr %s\n", ledStateStr);
	copy_to_user(buff, ledStateStr, sizeof(ledStateStr));
	return 0;
}

/* Called by application by write system call */
static ssize_t my_led_write(struct file *filep, const char __user *buff, size_t len, loff_t *offset)
{
	printk(KERN_ALERT "my_led_write\n");
	return 0;
}

static long my_led_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
	LED_CONTROL_ST ledControlArg = {0};

	int i = 0;
	int result = 0;

	printk(KERN_ALERT "my_led_ioctl\n");

	if(_IOC_TYPE(cmd) != LED_IOC_MAGIC)
	{
		printk(KERN_ALERT "LED_IOC_MAGIC\n");
		return -ENOTTY;
	}
	if(_IOC_NR(cmd) > LED_IOC_MAX_NUM)
	{
		printk(KERN_ALERT "LED_IOC_MAX_NUM\n");
		return -ENOTTY;
	}

	/* Check the command ioctl number to control */
	switch(cmd)
	{
		case LED_ON_OFF:
			printk(KERN_ALERT "LED_ON_OFF\n");

			/* Control by index and state, then we need to get it from user */
			result = copy_from_user(&ledControlArg, (LED_CONTROL_ST *)arg, sizeof(LED_CONTROL_ST));
			printk(KERN_ALERT "LED_ON_OFF argument pin-state: %d-%d\n", ledControlArg.ledIndex, ledControlArg.ledState);

			if((ledControlArg.ledIndex <= LED_MAX_NUM) && (ledControlArg.ledState <= 1))
			{
				/* Set LED index to state */
				gpio_set_value(st_arrLED[ledControlArg.ledIndex].ledPin, ledControlArg.ledState);
				st_arrLED[ledControlArg.ledIndex].ledState = gpio_get_value(st_arrLED[ledControlArg.ledIndex].ledPin);
			}
			break;
		case LED_BLINK:
			/* Control by index and state, then we need to get it from user */
			result = copy_from_user(&ledControlArg, (LED_CONTROL_ST *)arg, sizeof(LED_CONTROL_ST));
			printk("LED_ON_OFF argument pin-state: %d-%d\n", ledControlArg.ledPin, ledControlArg.ledState);

			if((ledControlArg.ledIndex <= LED_MAX_NUM) && (ledControlArg.ledState <= 1))
			{
				for (i = 0; i < 3; i++)
				{
					/* Set LED index to state */
					gpio_set_value(st_arrLED[ledControlArg.ledIndex].ledPin, 0);
					msleep(1000);
					gpio_set_value(st_arrLED[ledControlArg.ledIndex].ledPin, 1);
					msleep(1000);
				}
			}
			break;
		default:
			return -ENOTTY;
	}
	return 0;
}

/* Init and exit function need to be register by init and exit function */
module_init(my_led_init);
module_exit(my_led_exit);
