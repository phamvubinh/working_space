CC=gcc
CPP=g++
RM=rm -f
CPPFLAGS=-g
LDFLAGS=-g
LDLIBS=

SRCS=$(wildcard *.cpp)

OBJS=$(subst .cpp,.o,$(SRCS))

all: application

application: $(OBJS)
	$(CPP) $(LDFLAGS) -o application $(OBJS) $(LDLIBS)

depend: .depends

.depend: $(SRC)
	$(RM) ./.depend
	$(CPP) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	# $(RM) *~ .depend
	$(RM) application

# include depend