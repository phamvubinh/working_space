#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PVBINH");
/* Init function is called when insmod kernel module */
static int hello_init(void)
{
	printk(KERN_ERR "Hello beautiful world\n");
	return 0;
}

/* Exit function is called when rmmod kernel module */
static void hello_exit(void)
{
	printk(KERN_ERR "Goodbye cruel world\n");
}

/* Init and exit function need to be register by init and exit function */
module_init(hello_init);
module_exit(hello_exit);


