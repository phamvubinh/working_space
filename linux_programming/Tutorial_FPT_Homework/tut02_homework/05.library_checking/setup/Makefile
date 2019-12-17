#This makefile is used to make invidual program files with invidual main() inside a folder to the different programs

#Create basic variable that will be used in recipes rule
CC=gcc
CPP=g++
LDFLAGS := -lrt -pthread
CFLAGS_INC :=
CFLAGS := -g -Wall $(CFLAGS_INC)

#Parse all source file names and create program and object names
#Get all .c file into SRCS
SRCS := $(wildcard *.c)
#Replace xxx.c by xxx and save into PRGS
PRGS := $(patsubst %.c,%,$(SRCS))
#Replace xxx in PRGS by xxx.o and save in OBJS
OBJS := $(patsubst %, %.o, $(PRGS))


#Create all target with prerequisite is programs
all: $(PRGS)

#Create OBJ as the object of program 
OBJ = $(patsubst %,%.o,$@)
#Now each program is a target 
$(PRGS): $(OBJS)
	$(CC) $(OBJ) $(LDFLAGS) -o $@
	#Remove temple objectfile
	$(RM) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(PRGS)
	$(RM) *.txt