#include <linux/export.h>
#include <linux/hid.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/usb.h>

static const struct usb_device_id id_table[] = {
	/*
	 * USB_INTERFACE_INFO(class, subclass, protocol)
	 */
	{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{}
};

MODULE_DEVICE_TABLE(usb, id_table);

static int hello_init(void)
{
	pr_debug("Hello, world\n");
	return 0;
}

static void hello_exit(void)
{
	pr_debug("Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("5c39dda5ea83");
