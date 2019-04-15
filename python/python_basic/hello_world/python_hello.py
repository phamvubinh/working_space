#!/usr/bin/python
import sys
import os
import time

def TFP_Open_File(fileName):
	fd = open(fileName, "w+")
	return fd

def TFP_Help():
	print "Usage:"
	print "./python_hello file_name"

def TFP_Main():
	#Remove file if existed
	if (os.path.isfile(sys.argv[1]) == True):
		os.remove(sys.argv[1])

	#Choose appending mode to write and read


	fTSFileFd = TFP_Open_File(sys.argv[1])

	print "Name of this file: ", fTSFileFd.name
	print "Closed or not:     ", fTSFileFd.closed
	print "Opening mode:      ", fTSFileFd.mode
	print "Softspace flag:    ", fTSFileFd.softspace

	#Writing into file
	fTSFileFd.write("Python is a greate language. Yes this is great\n")

	#Need to go to the fisrt position before write

	# Check current position
	position = fTSFileFd.tell();
	print "Current file position : ", position

	# Reposition pointer at the beginning once again
	position = fTSFileFd.seek(0, 0);
	print "Go to the first posistion: ", position

	#Reading data from file
	str1 = fTSFileFd.read(29)
	str2 = fTSFileFd.read()
	str3 = "Hello Python. I will go along with you!\n"

	print "str1 is: ", str1
	print "str2 is: ", str2
	print str3

	fTSFileFd.close()

if(len(sys.argv) >= 2 ):
	TFP_Main()
else:
	TFP_Help()

