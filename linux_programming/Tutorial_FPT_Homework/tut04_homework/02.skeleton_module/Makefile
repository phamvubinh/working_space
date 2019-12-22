# Building kernel module outside of the kernel tree
# This condition selects whether we are in Kernel Makefile or not

# For cross compile
# CROSS_TOOL = <TOOLCHAIN_DIR>/bin/arm-linux-gnueabihf-

# First step check current folder outside linux folder tree
ifeq ($(KERNELRELEASE), )
	# The KERNERDIR should be set in where the kernel was build
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	# The current directory is passed to sub-makes as argument
	PWD := $(shell pwd)

modules: 
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	# For cross compile
	# $(MAKE) ARCH=arm CROSS_COMPILE=$(CROSS_TOOL) -C $(KERNELDIR) SUBDIRS=$(PWD) modules

# Make then install module into /modules/ folder
modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.symvers *.order

#Second step when inside the linux source directory /usr/src/linux-headers-3.13.0-32-generic, the module name now is used for the real build
else
	obj-m := skeleton_module_1.o skeleton_module_2.o
endif	
