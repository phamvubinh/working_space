/* This is the second version of skeleton character device driver */
/* In this version, device file need to be created by using mknod command,
   then we don't need to create device file in module code C.
   Instead I created insmod.sh file for mknod command */
#include <linux/module.h>
#include <linux/init.h>

#include <linux/sched.h>  /* current and everything */
#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/types.h>  /* size_t */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PVBINH");

static int my_cdev_major = 0;

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
	int result = 0;

	printk(KERN_ALERT "my_cdev_init\n");
	/* Register the MAJOR, and accept a dynamic number */
	result = register_chrdev(my_cdev_major, "skeleton_module_2", &fops);
	if(result < 0)
	{
		return result;
	}
	if(my_cdev_major == 0)
	{
		my_cdev_major = result; /* dynamic */
	}
	return 0;
}

/* Exit function is called when rmmod kernel module */
static void __exit my_cdev_exit(void)
{
	printk(KERN_ALERT "my_cdev_exit\n");
	unregister_chrdev(my_cdev_major, "skeleton_module_2");
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
	/* Return 0 to avoid retrial */
	return 0;
}

/* Called by application by write system call */
static ssize_t my_cdev_write(struct file *filep, const char __user *buff, size_t len, loff_t *offset)
{
	printk(KERN_ALERT "my_cdev_write\n");
	/* Return 1 to avoid retrial */
	return 1;
}

/* Init and exit function need to be register by init and exit function */
module_init(my_cdev_init);
module_exit(my_cdev_exit);


