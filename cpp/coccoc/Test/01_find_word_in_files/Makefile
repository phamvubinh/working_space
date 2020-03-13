#Create basic variable that will be used in recipes rule
CPP     := g++
LDFLAGS := -lrt -pthread
CFLAGS_INC := -I./include
CFLAGS  := -g -Wall $(CFLAGS_INC) -std=c++0x
LIB     := -lboost_filesystem -lboost_system
PRG		:= cococ
SRCS    := $(wildcard *.cpp)

all:
	$(CPP) $(CFLAGS) $(SRCS) -o $(PRG) $(LIB)
clean:
	rm -rf *.o (PRG)

# sudo apt-get install libboost-filesystem-dev 