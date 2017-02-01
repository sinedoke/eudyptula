# eudyptula chalenge

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

<dev class="class>

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

</div>
