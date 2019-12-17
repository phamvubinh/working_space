# This makefile is used to call makefile in subfolder
TOPTARGETS := all clean distclean
TOPDIR = $(shell pwd)
# $(info TOPDIR is $(TOPDIR))

# Get the subfolder name with the / in ending and remove / at the end
SUBDIRS := $(patsubst %/,%,$(wildcard */))
$(info SUBDIRS is $(SUBDIRS))

# We are setting up the makefile dependency based on setup <- app <- shared_lib
.PHONY: $(TOPTARGETS) $(SUBDIRS)
# setup folder needs to be build in last step
$(TOPTARGETS): setup

# Make will set the special variable MAKECMDGOALS to the list of goals you specified on the command line
$(SUBDIRS):
	$(MAKE) --directory=$@ $(MAKECMDGOALS)

# we create the dependency scenario for this make 
setup: app shared_lib
app: shared_lib

# refer https://stackoverflow.com/questions/17834582/run-make-in-each-subdirectory
# https://www.oreilly.com/openbook/make3/book/ch06.pdf
