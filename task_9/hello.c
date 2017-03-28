#include <linux/errno.h>
#include <linux/init.h>
#include <linux/jiffies.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/poll.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/semaphore.h>
#include <linux/slab.h>
#include <linux/string.h>

static DEFINE_MUTEX(foo_sem);
struct dentry * ret;
static char msg[PAGE_SIZE];

/*
 * This module shows how to create a simple subdirectory in sysfs called
 * /sys/kernel/eudyptula  In that directory, 3 files are created:
 * "foo", "id", and "jiffies".
 */

/*
 * The "foo" file where a static variable is read from and written to.
 */
static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr,
			char *buf)
{
	ssize_t len;

	len = strlen(msg);
	mutex_lock(&foo_sem);
	strncpy(buf, msg, len);
	mutex_unlock(&foo_sem);

	return len;
}

static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
	if (count > PAGE_SIZE)
		return -EINVAL;

	mutex_lock(&foo_sem);
	strncpy(msg, buf, count);
	mutex_unlock(&foo_sem);

	return count;
}

/* Sysfs attributes cannot be world-writable. */
static struct kobj_attribute foo_attribute =
__ATTR_RW(foo);

static ssize_t id_show(struct kobject *kobj, struct kobj_attribute *attr,
			    char *buf)
{
	ssize_t	len;
	char *hello_str = "5c39dda5ea83";

	len = strlen(hello_str);
	strncpy(buf, hello_str, len);

	return len;
}

static ssize_t id_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
	char *hello_str = "5c39dda5ea83";

	if (strlen(hello_str) != count-1)
		return -EINVAL;

	if (strncmp(buf, hello_str, strlen(hello_str)) != 0)
		return -EINVAL;

	strncpy(hello_str, buf, count);

	return count;
}

static struct kobj_attribute id_attribute =
__ATTR(id, 0664, id_show, id_store);

static ssize_t jiffies_show(struct kobject *kobj, struct kobj_attribute *attr,
			 char *buf)
{
	return sprintf(buf, "%lu\n", jiffies);
}

static struct kobj_attribute jiffies_attribute = __ATTR_RO(jiffies);

/*
 * Create a group of attributes so that we can create and destroy them all
 * at once.
 *
 * An attribute definition is simply:
 *
 * struct attribute {
 *      char		* name;
 *      struct module	*owner;
 *      umode_t		mode;
 * };
 */

static struct attribute *attrs[] = {
	&foo_attribute.attr,
	&id_attribute.attr,
	&jiffies_attribute.attr,
	NULL, /* need to NULL terminate the list of attributes */
};

static struct attribute_group hello_group = {
	.attrs = attrs,
};

static struct kobject *hello_kobj;

static int hello_init(void)
{
	int ret;
	
	/*
	 * Create a simple kobject with the name of "eudyptula",
	 * located under /sys/kernel/
	 *
	 * As this is a simple directory, no uevent will be sent to
	 * userspace.  That is why this function should not be used for
	 * any type of dynamic kobjects, where the name and number are
	 * not known ahead of time.
	 */
	hello_kobj = kobject_create_and_add("eudyptula", kernel_kobj);
	if (!hello_kobj)
		return -ENOMEM;

	/* Create the files associated with this kobject */
	ret = sysfs_create_group(hello_kobj, &hello_group);
	if (ret)
		kobject_put(hello_kobj);

	pr_debug("Hello, world\n");

	return ret;
}

static void hello_exit(void)
{
	kobject_put(hello_kobj);
	pr_debug("Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("5c39dda5ea83");
