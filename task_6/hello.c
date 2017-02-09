#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include <linux/slab.h>

/*
 * struct miscdevice {
 * int minor; 	minor is the minor number being registered. Every misc
 * 		device must feature a different minor number, because
 * 		such a number is the only link between the file in /dev
 * 		and the driver.
 * 
 * const char *name; 	is the name for this device, meant for human
 * 			consumption: users will find the name in the
 * 			/proc/misc file.
 * 
 * struct file_operations *fops; 	is a pointer to the file operations
 * 					which must be used to act on the 
 * 					device. 
 * 
 * struct miscdevice *next, *prev;	next and prev are used to manage a
 * 					circularly-linked list of registered
 * 					drivers.
 * };
 */

static ssize_t hello_read(struct file * file, char * buf,
                          size_t count, loff_t *ppos)
{
	char *hello_str = "5c39dda5ea83";

	return simple_read_from_buffer(buf, count, ppos, hello_str,
		strlen(hello_str));
}

static ssize_t hello_write(struct file * file, const char * buf,
                          size_t count, loff_t *ppos)
{
	ssize_t len;
	char *hello_str = "5c39dda5ea83";
	char *msg = kmalloc (count + 1, GFP_KERNEL);

	if (!msg)
		return -ENOMEM;

	if (strlen(hello_str) != count-1)
		return -EINVAL;

	len = simple_write_to_buffer(msg, count, ppos, buf,
		count);

	if (strncmp(msg, hello_str, strlen(hello_str)) != 0)
		return -EINVAL;

	return len;
}

static const struct file_operations hello_fops = {
	.owner	= THIS_MODULE,
	.read	= hello_read,
	.write	= hello_write,
};

static struct miscdevice hello_misc = {

	 /*
         * We don't care what minor number we end up with, so tell the
         * kernel to just pick one.
         */
        MISC_DYNAMIC_MINOR,
        /*
         * Name ourselves /dev/eudyptula.
         */
        "eudyptula",
        /*
         * What functions to call when a program performs file
         * operations on the device.
         */
        &hello_fops
};
 
static int hello_init(void)
{
	pr_debug("Hello, world\n");
	return misc_register(&hello_misc);
}

static void hello_exit(void)
{
	pr_debug("Goodbye, cruel world\n");
	misc_deregister(&hello_misc);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("5c39dda5ea83");
