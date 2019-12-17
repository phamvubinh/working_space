all:
	# make foo.o object file from foo.c
	gcc -c -Wall -Werror -fpic foo.c
	# make a shared library from foo.o object
	gcc -shared -o libfoo.so foo.o
	# make main application from shared library 
	# gcc -L./ -Wl,-rpath=/usr/bin -Wall -o test1 main.c -lfoo
clean:
	# rm -f test1
	rm -f *.o *.so
