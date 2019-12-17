# Add misc-module into module list to build 
obj-m += misc-module.o

all:
	# Call the make inside linux build folder with module option
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	# Make application to read driver file
	gcc read.c -o read
clean:
	# Clean module and application
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf read
