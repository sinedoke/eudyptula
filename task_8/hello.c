#include <linux/debugfs.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/string.h>

struct dentry * ret;

static ssize_t id_read(struct file *file, char __user *buf,
	size_t count, loff_t *ppos)
{
	char *hello_str = "5c39dda5ea83";

	return simple_read_from_buffer(buf, count, ppos, hello_str,
		strlen(hello_str));
}

static ssize_t id_write(struct file *file, char const __user *buf,
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

static const struct file_operations id_fops = {
	.owner = THIS_MODULE,
	.read = id_read,
	.write = id_write
};

static int hello_init(void)
{
	/*
	 * Take the kernel module you wrote for task 01, and modify
	 * it to create a debugfs subdirectory called "eudyptula".
	 */
	ret = debugfs_create_dir("eudyptula", NULL); /* /sys/kernel/debug */

	/*
	 * In that directory, create the virtual file called "id".
	 * 666 -> rw
	 */
	if (!debugfs_create_file("id", 0666, ret, NULL,
		&id_fops))
		return -ENODEV;

	pr_debug("Hello, world\n");

	return 0;
}

static void hello_exit(void)
{
	debugfs_remove_recursive(ret);

	pr_debug("Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("5c39dda5ea83");
