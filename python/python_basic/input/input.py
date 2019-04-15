#!/usr/bin/python
import sys

str = raw_input("Enter raw_input: ")
print "raw_input is: ", str

try:
	str = input("Enter expression input: ")
	print "result is: ", str
except NameError:
	print "No valid expression"

sys.exit()

