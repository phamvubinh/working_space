/* This is the second version power state control  */

#include <linux/module.h>
#include <linux/init.h>

#include <linux/sched.h>  /* current and everything */
#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/types.h>  /* size_t */

#include <linux/reboot.h> /* for kernel power function */
#include <linux/delay.h>  /* for delay function */

#include "ioctl_control.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PVBINH");

static int power_control_major = 0;
static int argument_setup_time = 0;

/* Define prototype function to add to file_operations struct */
static int power_control_open(struct inode *, struct file *);
static int power_control_close(struct inode *, struct file *);
static ssize_t power_control_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t power_control_write(struct file *, const char __user *, size_t, loff_t *);
static long power_control_ioctl(struct file *, unsigned int, unsigned long);

/* Define file_operation srtuct */
static struct file_operations fops = {
	.open 			= power_control_open,
	.release 		= power_control_close,
	.read 			= power_control_read,
	.write 			= power_control_write,
	.unlocked_ioctl = power_control_ioctl,
};

/* Init function is called when insmod kernel module */
static int __init power_control_init(void)
{
	int result = 0;

	printk(KERN_ALERT "power_control_init\n");
	/* Register the MAJOR, and accept a dynamic number */
	result = register_chrdev(power_control_major, "power_state", &fops);
	if(result < 0)
	{
		return result;
	}
	if(power_control_major == 0)
	{
		power_control_major = result; /* dynamic */
	}
	return 0;
}

/* Exit function is called when rmmod kernel module */
static void __exit power_control_exit(void)
{
	printk(KERN_ALERT "power_control_exit\n");
	unregister_chrdev(power_control_major, "power_state");
}

/* Called by application by open system call */
static int power_control_open(struct inode *inodep, struct file *filep)
{
	printk(KERN_ALERT "power_control_open\n");
	return 0;
}

/* Called by application by close system call */
static int power_control_close(struct inode *inodep, struct file *filep)
{
	printk(KERN_ALERT "power_control_close\n");
	return 0;
}

/* Called by application by read system call */
static ssize_t power_control_read(struct file *filep, char __user *buff, size_t len, loff_t *offset)
{
	printk(KERN_ALERT "power_control_read\n");
	/* Return 0 to avoid retrial */
	return 0;
}

/* Called by application by write system call */
static ssize_t power_control_write(struct file *filep, const char __user *buff, size_t len, loff_t *offset)
{
	printk(KERN_ALERT "power_control_write\n");
	/* Return 1 to avoid retrial */
	return 1;
}

/* Function is called when ioctl is called from application */
static long power_control_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
	int result = 0;
	/*
	 * Extract the type and number bitfields, and don't decode wrong command
	 * Return ENOTTY (inappropriate ioctl) before access_ok()
	 */
	printk(KERN_ALERT "power_control_ioctl\n");
	if(_IOC_TYPE(cmd) != POWER_IOC_MAGIC)
	{
		printk(KERN_ALERT "POWER_IOC_MAGIC\n");
		return -ENOTTY;
	}
	if(_IOC_NR(cmd) > POWER_IOC_MAX_NUM)
	{
		printk(KERN_ALERT "POWER_IOC_MAX_NUM\n");
		return -ENOTTY;
	}

	/*
	 * The direction is a bitmask, and VERIFY_WRITE catches R/W transfers.
	 * 'Type' is user-oriented, while access_ok is kernel oriented,
	 * so the concept of "read" and "write" is reversed.
	 */
	if(_IOC_DIR(cmd) & _IOC_READ)
	{
		result = !access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd));
	}
	else if(_IOC_DIR(cmd) & _IOC_WRITE)
	{
		result = !access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd));
	}
	if(result)
	{
		return -EFAULT;
	}

	/* Check the command ioctl number to control */
	switch(cmd)
	{
		case POWER_SHUTDOWN:
			printk(KERN_ALERT "POWER_SHUTDOWN\n");
			result = __get_user(argument_setup_time, (int __user *)arg);
			printk("POWER_SHUTDOWN argument_setup_time: %d\n", argument_setup_time);
			msleep(argument_setup_time * 1000);
			kernel_power_off();
			break;
		case POWER_RESTART:
			printk(KERN_ALERT "POWER_RESTART\n");
			result = __get_user(argument_setup_time, (int __user *)arg);
			printk(KERN_ALERT "POWER_RESTART argument_setup_time: %d\n", argument_setup_time);
			msleep(argument_setup_time * 1000);
			kernel_restart(NULL);
			break;
		default:
			return -ENOTTY;
	}
	return 0;
}

/* Init and exit function need to be register by init and exit function */
module_init(power_control_init);
module_exit(power_control_exit);


