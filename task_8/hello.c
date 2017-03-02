#include <linux/debugfs.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/string.h>

static DEFINE_MUTEX(foo_sem);
struct dentry * ret;
char msg[PAGE_SIZE];

static ssize_t foo_read(struct file *file, char __user *buf,
	size_t count, loff_t *ppos)
{
	int ret = -EINVAL;

	mutex_lock(&foo_sem);

	ret = simple_read_from_buffer(buf, count, ppos, msg,
		strlen(msg));

	mutex_unlock(&foo_sem);

	return ret;
}

static ssize_t foo_write(struct file *file, char const __user *buf,
	size_t count, loff_t *ppos)
{
	ssize_t len;

	mutex_lock(&foo_sem);

	len = simple_write_to_buffer(msg, PAGE_SIZE, ppos, buf,
		count);

	mutex_unlock(&foo_sem);

	return len;
}

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

static const struct file_operations foo_fops = {
	.owner = THIS_MODULE,
	.read = foo_read,
	.write = foo_write
};

static const struct file_operations id_fops = {
	.owner = THIS_MODULE,
	.read = id_read,
	.write = id_write
};

static int hello_init(void)
{
	unsigned long t = jiffies;
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
	/*
	 * This "jiffies" file is to be read-only by any user, and when
	 * read,should return the current value of the jiffies kernel
	 * timer. 444 -> read-only
	 */
	if (!debugfs_create_u32("jiffies", 0444, ret, (u32 *)&t))
		return -ENODEV;

	/*
	 * The file "foo" needs to be writable only by root, but readable by
	 * anyone.  When writing to it, the value must be stored, up to one
	 * page of data.  When read, which can be done by any user, the value
	 * that is stored in it must be returned.  Properly handle the fact
	 * that someone could be reading from the file while someone else is
	 * writing to it (oh, a locking hint!)
	 */
	if (!debugfs_create_file("foo", 0644, ret, NULL,
		&foo_fops))
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
