/* This is the first version of skeleton character device driver */
/* In this version, device file is created automatically in init module,
   that means we don't need to use mknod command to create device file */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>       /* Header for file_operation struct */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PVBINH");

/* Define class name and device name pointer */
static struct class *class_name;
static struct device *device_name;

static dev_t dev;
static struct cdev my_cdev;

/* Define prototype function to add to file_operations struct */
static int my_cdev_open(struct inode *, struct file *);
static int my_cdev_close(struct inode *, struct file *);
static ssize_t my_cdev_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t my_cdev_write(struct file *, const char __user *, size_t, loff_t *);

/* Define file_operation srtuct */
static struct file_operations fops = {
	.open 		= my_cdev_open,
	.release 	= my_cdev_close,
	.read 		= my_cdev_read,
	.write 		= my_cdev_write,
};

/* Init function is called when insmod kernel module */
static int __init my_cdev_init(void)
{
	int ret = 0;
	printk(KERN_ALERT "my_cdev_init\n");

	/*  Register a range of char device numbers

		dev: output parameter for first assigned number
		baseminor: first of the requested range of minor numbers
		count: the number of minor numbers required
		name: the name of the associated device or driver
	*/
	ret = alloc_chrdev_region(&dev, 0, 1, "skeleton_module");
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
	class_name = class_create(THIS_MODULE, "skeleton_module");
	if(IS_ERR(class_name))
	{
		printk(KERN_ERR "Create class failed\n");
		return -ENODEV;
	}

	/* A struct device will be created in sysfs, registered to the specified class. */
	/* A “dev” file will be created */
	device_name = device_create(class_name, NULL, dev, NULL, "skeleton");
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
static void __exit my_cdev_exit(void)
{
	printk(KERN_ALERT "my_cdev_exit\n");
	/* Do the exit step by reverting init step */
	cdev_del(&my_cdev);
	device_destroy(class_name, dev);
	class_destroy(class_name);
	unregister_chrdev_region(dev, 1);
}

/* Called by application by open system call */
static int my_cdev_open(struct inode *inodep, struct file *filep)
{
	printk(KERN_ALERT "my_cdev_open\n");
	return 0;
}

/* Called by application by close system call */
static int my_cdev_close(struct inode *inodep, struct file *filep)
{
	printk(KERN_ALERT "my_cdev_close\n");
	return 0;
}

/* Called by application by read system call */
static ssize_t my_cdev_read(struct file *filep, char __user *buff, size_t len, loff_t *offset)
{
	printk(KERN_ALERT "my_cdev_read\n");
	return 0;
}

/* Called by application by write system call */
static ssize_t my_cdev_write(struct file *filep, const char __user *buff, size_t len, loff_t *offset)
{
	printk(KERN_ALERT "my_cdev_write\n");
	return 0;
}

/* Init and exit function need to be register by init and exit function */
module_init(my_cdev_init);
module_exit(my_cdev_exit);


