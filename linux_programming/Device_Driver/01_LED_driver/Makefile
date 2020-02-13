# Building kernel module outside of the kernel tree
# This condition selects whether we are in Kernel Makefile or not

# For cross compile
# CROSS_TOOL=arm-linux-gnueabihf-
# ARCH=arm

obj-m := 01_LED_module.o 

# The KERNERDIR should be set in where the kernel was build
KERNELDIR?=/lib/modules/$(shell uname -r)/build

# The KERNERDIR should be set in where the kernel was build
# KERNELDIR_CROSS?=/home/pvbinh/work/BeagleBone_Black/linux_programming_blog/03_BBB_kernel_build/BBB_kernel/kernel/kernel

# The current directory is passed to sub-makes as argument
PWD := $(shell pwd)

all: modules app

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

app: 
	$(CC) -o 01_LED_app 01_LED_app.c
# modules_cross: 
# 	$(MAKE) ARCH=arm CROSS_COMPILE=$(CROSS_TOOL) -C $(KERNELDIR_CROSS) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.symvers *.order 01_LED_app

