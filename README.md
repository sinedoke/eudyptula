# Eudyptula Challenge

#Task 1
This is Task 01 of the Eudyptula Challenge
------------------------------------------

Write a Linux kernel module, and stand-alone Makefile, that when loaded
prints to the kernel debug log level, "Hello World!"  Be sure to make
the module able to be unloaded as well.

The Makefile should be able to build the kernel module against the
source of the currently-running kernel as well as being able to accept
an arbitrary kernel sources directory from an environment variable.

Please show proof of this module being built, and running, in your
kernel.  What this proof is is up to you.  I'm sure you can come up with
something.  Also be sure to send the kernel module you wrote, along with
the Makefile you created to build the module.

Remember to use your ID assigned in the Subject: line when responding to
this task, so that I can figure out who to attribute it to.  You can
just respond to the task with the answers and all should be fine.

If you forgot, your id is "5c39dda5ea83".  But of course you have not
forgotten that yet, you are better than that.

#Task 2

Subject: Task 02 of the Eudyptula Challenge


This is Task 02 of the Eudyptula Challenge
------------------------------------------

Now that you have written your first kernel module, it's time to take
off the training wheels and move on to building a custom kernel.  No
more distro kernels for you.  For this task you must run your own
kernel.  And use git!  Exciting, isn't it?  No?  Oh, ok...

The tasks for this round are:
  - Download Linus's latest git tree from git.kernel.org (you have to
    figure out which one is his.  It's not that hard, just remember what
    his last name is and you should be fine.)
  - Build it, install it, and boot it.  You can use whatever kernel
    configuration options you wish to use, but you must enable
    CONFIG_LOCALVERSION_AUTO=y.
  - Show proof of booting this kernel.  Bonus points if you do it on a
    "real" machine, and not a virtual machine (virtual machines are
    acceptable, but come on, real kernel developers don't mess around
    with virtual machines, they are too slow.  Oh yeah, we aren't real
    kernel developers just yet.  Well, I'm not anyway, I'm just a
    script...)  Again, proof of running this kernel is up to you, I'm
    sure you can do well.

Hint, you should look into the 'make localmodconfig' option, and base
your kernel configuration on a working distro kernel configuration.
Don't sit there and answer all 1625 different kernel configuration
options by hand, even I, a foolish script, know better than to do that!

After doing this, don't throw away that kernel, git tree, and
configuration file.  You'll be using it for later tasks.  A working
kernel configuration file is a precious thing, all kernel developers
have one they have grown and tended to over the years.  This is the
start of a long journey with yours.  Don't discard it like was a broken
umbrella, it deserves better than that.

Remember to use your ID assigned in the subject line when responding to
this task, so that I can figure out who to attribute it to.

If you forgot, your id is "5c39dda5ea83".  But why do I repeat myself?
Of course you know your id, you made it through the first task just fine
with it.

#Task 3

This is Task 03 of the Eudyptula Challenge
------------------------------------------

Now that you have your custom kernel up and running, it's time to modify
it!

The tasks for this round are:
  - Take the kernel git tree from Task 02 and change the Makefile to
    modify the EXTRAVERSION field.  Do this in a way that the
    running kernel (after modifying the Makefile, rebuilding, and
    rebooting) has the characters "-eudyptula" in the version string.
  - Show proof of booting this kernel.  Extra cookies when you provide
    creative examples, especially if done in interpretive dance at your
    local pub.
  - Send a patch that shows the Makefile modified.  Do this in a manner
    that would be acceptable for merging in the kernel source tree.
    (Hint, read the file Documentation/SubmittingPatches and follow the
    steps there.)

Remember to use your ID assigned in the subject line when responding to
this task, so that I can figure out who to attribute it to.

If you forgot, your id is "5c39dda5ea83".  Surely I don't need to keep
saying this right?  I know, _you_ wouldn't forget, but someone else, of
course they would, so I'll just leave it here for those "others."

#Task 4

This is Task 04 of the Eudyptula Challenge
------------------------------------------

Wonderful job in making it this far.  I hope you have been having fun.
Oh, you're getting bored, just booting and installing kernels?  Well,
time for some pedantic things to make you feel that those kernel builds
are actually fun!

Part of the job of being a kernel developer is recognizing the proper
Linux kernel coding style.  The full description of this coding style
can be found in the kernel itself, in the Documentation/CodingStyle
file.  I'd recommend going and reading that right now.  It's pretty
simple stuff, and something that you are going to need to know and
understand.  There is also a tool in the kernel source tree in the
scripts/ directory called checkpatch.pl that can be used to test for
adhering to the coding style rules, as kernel programmers are lazy and
prefer to let scripts do their work for them...

Why a coding standard at all?  Because of your brain (yes, yours, not
mine, remember, I'm just some dumb shell scripts).  Once your brain
learns the patterns, the information contained really starts to sink in
better.  So it's important that everyone follow the same standard so
that the patterns become consistent.  In other words, you want to make
it really easy for other people to find the bugs in your code, and not
be confused and distracted by the fact that you happen to prefer 5
spaces instead of tabs for indentation.  Of course you would never
prefer such a thing, I'd never accuse you of that, it was just an
example, please forgive my impertinence!

Anyway, the tasks for this round all deal with the Linux kernel coding
style.  Attached to this message are is one kernel module that does not
follow the proper Linux kernel coding style rules.  Fix this file up,
AND fix up the final submission you did for Task 01, and send them back
to me as attachments in your response email.

Yes, the logic in attached second module is crazy, and probably wrong,
but don't focus on that, just look at the patterns here, and fix up the
coding style, do not remove lines of code.

Oh, and before you think "Ah, but I got the coding style right for Task
01, I already know this stuff!", remember that so far only 10 people,
out of over 4000, have gotten the coding style exactly right for their
Task 01 module.  Yes, you could be one of those people, but the odds are
not in your favor.  You should look at it again just to be sure.

So again, attach 2 files, this one fixed up, and your Task 01
submission.  Don't use base64 either, the scripts will instantly reject
it, you don't want to get on their bad side.

As always, please remember to use your ID in the subject line when
responding to this task, so that I can figure out who to attribute it
to.  And if you forgot (which of course you have not, we've been through
all of this before), your id is "5c39dda5ea83".

<body>
<pre class = 'brush: cpp' >
<code>

coding_style.c

#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/delay.h>
#include <linux/slab.h>

int do_work( int * my_int, int retval ) {
	int x;
	int y=*my_int;
	int z;
	
	for(x=0;x< * my_int;++x) {
		udelay(10);
	}

	if (y < 10 )
		// That was a long sleep, tell userspace about it
		printk("We slept a long time!");

	z = x * y;

	return z;
}

int
my_init (void)
{
	int x = 10;

	x = do_work(&x, x);

	return x;
}

void my_exit( void )
{
	return;
}

module_init(my_init);
module_exit(my_exit);

</code>
</pre>
</body>

This is Task 05 of the Eudyptula Challenge
------------------------------------------

Yeah, you survived the coding style mess!  Now, on to some "real"
things, as I know you are getting bored by these so far.

So, two simple tasks this time around:
  - Take the kernel module you wrote for task 01, and modify it so that
    when any USB keyboard is plugged in, the module will be
    automatically loaded by the correct userspace hotplug tools (which
    are implemented by depmod / kmod / udev / mdev / systemd, depending
    on what distro you are using.)
  - Again, provide "proof" this all works.

Yes, so simple, and yet, it's a bit tricky.  As a hint, go read chapter
14 of the book, "Linux Device Drivers, 3rd edition."  Don't worry, it's
free, and online, no need to go buy anything.

As always, please remember to use your ID, yadda yadda yadda...
It's "5c39dda5ea83" of course.

This is Task 06 of the Eudyptula Challenge
------------------------------------------

Nice job with the module loading macros.  Those are tricky, but a very
valuable skill to know about, especially when running across them in
real kernel code.

Speaking of real kernel code, let's write some!

The tasks this time are:
  - Take the kernel module you wrote for task 01, and modify it to be a
    misc char device driver.  The misc interface is a very simple way to
    be able to create a character device, without having to worry about
    all of the sysfs and character device registration mess.  And what a
    mess it is, so stick to the simple interfaces wherever possible.
  - The misc device should be created with a dynamic minor number, no
    need running off and trying to reserve a real minor number for your
    test module, that would be crazy.
  - The misc device should implement the read and write functions.
  - The misc device node should show up in /dev/eudyptula.
  - When the character device node is read from, your assigned id is
    returned to the caller.
  - When the character device node is written to, the data sent to the
    kernel needs to be checked.  If it matches your assigned id, then
    return a correct write return value.  If the value does not match
    your assigned id, return the "invalid value" error value.
  - The misc device should be registered when your module is loaded, and
    unregistered when it is unloaded.
  - Provide some "proof" this all works properly.

As you will be putting your id into the kernel module, of course you
haven't forgotten it, but just to be safe, it's "5c39dda5ea83".

This is Task 07 of the Eudyptula Challenge
------------------------------------------

Great work with that misc device driver.  Isn't that a nice and simple
way to write a character driver?

Just when you think this challenge is all about writing kernel code,
this task is a throwback to your second one.  Yes, that's right,
building kernels.  Turns out that's what most developers end up doing:
tons and tons of rebuilds, not writing new code.  Sad, but it is a good
skill to know.

The task this round is:
  - Download the linux-next kernel for today.  Or tomorrow, just use
    the latest one.  It changes every day so there is no specific one
    you need to pick.  Build it.  Boot it.  Provide proof that you built
    and booted it.

What is the linux-next kernel?  Ah, that's part of the challenge.

For a hint, you should read the excellent documentation about how the
Linux kernel is developed in Documentation/development-process/ in the
kernel source itself.  It's a great read, and should tell you all you
never wanted to know about what Linux kernel developers do and how they
do it.

As always, please respond to this challenge with your id.  I know you
know what it is.  I'll not even include it this time, I trust you.
Don't make me feel that is a mistake.

This is Task 08 of the Eudyptula Challenge
------------------------------------------

We will come back to the linux-next kernel in a later exercise, so don't
go and delete that directory, you'll want it around.  But enough of
building kernels, let's write more code!

This task is much like the 06 task with the misc device, but this time
we are going to focus on another user/kernel interface, debugfs.  It is
rumored that the creator of debugfs said that there is only one rule for
debugfs use": "There are no rules when using debugfs."  So let's take
them up on that offer and see how to use it.

debugfs should be mounted by your distro in /sys/kernel/debug/.  If it
isn't, then you can mount it with the line:
	mount -t debugfs none /sys/kernel/debug/

Make sure it is enabled in your kernel, with the CONFIG_DEBUG_FS option,
you will need it for this task.

The tasks, in specifics are:

  - Take the kernel module you wrote for task 01, and modify it to
    create a debugfs subdirectory called "eudyptula".  In that
    directory, create the virtual file called "id".
  - This "id" file, operates just like it did for example 06, and uses
    the same logic there, the file is to be readable and writable by any
    user.
  - Submit this task as the first email.
  - Base your work on this submission, and create a new debugfs file
    called "jiffies".
  - This "jiffies" file is to be read-only by any user, and when read,
    should return the current value of the jiffies kernel timer.
  - Submit this result as a patch against the first email.
  - Base your work again on that submission, and create a final debugfs
    file called "foo".
  - The file "foo" needs to be writable only by root, but readable by
    anyone.  When writing to it, the value must be stored, up to one
    page of data.  When read, which can be done by any user, the value
    that is stored in it must be returned.  Properly handle the fact
    that someone could be reading from the file while someone else is
    writing to it (oh, a locking hint!)
  - Submit this result as a patch against the second email.
  - When the module is unloaded, all of the debugfs files are cleaned
    up, and any memory allocated is freed, for all submissions.
  - Provide some "proof" this all works in the first email.

Again, you are using your id in the code, so you know what it is by now,
no need to repeat it again.

So, for this task, I expect to see 3 emails, all "linked" somehow, in my
mailbox.  They should look something like this:

	[5c39dda5ea83] Task 08 results
	├─>[5c39dda5ea83] [PATCH 01/02] Task 08: add jiffies file
	└─>[5c39dda5ea83] [PATCH 02/02] Task 08: add foo file

Or, even better:
	[5c39dda5ea83] Task 08 results
	└─>[5c39dda5ea83] [PATCH 01/02] Task 08: add jiffies file
	  └─>[5c39dda5ea83] [PATCH 02/02] Task 08: add foo file

Hint, look at using 'git send-email' as a way to send these files out.

This is Task 09 of the Eudyptula Challenge
------------------------------------------

Nice job with debugfs.  That is a handy thing to remember when wanting
to print out some debugging information.  Never use /proc/ that is only
for processes, use debugfs instead.

Along with debugfs, sysfs is a common place to put information that
needs to move from the user to the kernel.  So let us focus on sysfs for
this task.

The tasks this time:

  - Take the code you wrote in task 08, and move it to sysfs.  Put the
    "eudyptula" directory under the /sys/kernel/ location in sysfs.
  - fix up the permissions of the files to not allow world writable
    values, but only be able to be written to by root.
  - Provide some "proof" this works.

That's it!  Simple, right?  No, you are right, it's more complex; sysfs
is complicated.  I'd recommend reading Documentation/kobject.txt as a
primer on how to use kobjects and sysfs.

Feel free to ask for hints and help with this one if you have questions
by sending in code to review if you get stuck.  Many people have dropped
out in the challenge at this point in time, so don't feel bad about
asking.  We don't want to see you go away just because sysfs is so damn
complicated.

This is Task 10 of the Eudyptula Challenge
------------------------------------------

Yeah, you conquered the sysfs monster, great job!

Now you know you'll never want to mess with a kobject again, right?
Trust me, there are easier ways to create sysfs files, and we will get
into that for a future task, but for now, let's make it a bit more
simple after all of that coding.

For these tasks, go back to the linux-next tree you used for task 07.
Update it, and then do the following:
  - Create a patch that fixes one coding style problem in any of the
    files in drivers/staging/
  - Make sure the patch is correct by running it through
    scripts/checkpatch.pl
  - Submit the code to the maintainer of the driver/subsystem, finding
    the proper name and mailing lists to send it to by running the tool,
    scripts/get_maintainer.pl on your patch.
  - Get the patch accepted into the subsystem maintainers git tree.
  - Send a web link back to me of your patch in the public mailing list
    archive (don't cc: me on the patch, that will only confuse me and
    everyone in the kernel development community) as well as a pointer
    to the git commit of your patch in the subsystem tree.

Hopefully this patch will be accepted into the kernel tree, and all of a
sudden, you are an "official" kernel developer!

Don't worry, there's plenty more tasks coming, but a little breather
every now and again for something simple is always nice to have.

This is Task 11 of the Eudyptula Challenge
------------------------------------------

You made a successful patch to the kernel source tree, that's a great step!

But, let's not rest, time to get back to code.

Remember that mess of kobject and sysfs code back in task 09?  Let's move one level up the tree and start to mess with devices and not raw kobjects.

For this task:
  - Write a patch against any driver that you are currently using on
    your machine.  So first you have to figure out which drivers you are
    using, and where the source code in the kernel tree is for that
    driver.
  - In that driver, add a sysfs file to show up in the /sys/devices/
    tree for the device that is called "id".  As you might expect, this
    file follows the same rules as task 09 as for what you can read and
    write to it.
  - The file is to show up only for devices that are controlled by a
    single driver, not for all devices of a single type (like all USB
    devices.  But all USB mailbox LEDs would be acceptable, if you
    happen to have the device that that driver controls.)

Submit both the patch, in proper kernel commit form, and "proof" of it working properly on your machine.

And as always, please use your id in the subject line.  If you happened to forget it, as it has been a while since I reminded you of it, it is "5c39dda5ea83".

