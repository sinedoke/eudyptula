#include <linux/init.h>
#include <linux/module.h>

#define DEBUG

static int hello_init(void)
{
    printk(KERN_DEBUG "Hello, world\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_DEBUG "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("5c39dda5ea83");
