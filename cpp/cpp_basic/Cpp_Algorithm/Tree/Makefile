TOPTARGETS := all clean distclean
TOPDIR = $(shell pwd)

# $(info TOPDIR is $(TOPDIR))

# Get the subfolder name
SUBDIRS := $(wildcard */)

$(TOPTARGETS): $(SUBDIRS)

# Make will set the special variable MAKECMDGOALS to the list of goals you specified on the command line
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)

# refer https://stackoverflow.com/questions/17834582/run-make-in-each-subdirectory