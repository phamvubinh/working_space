#!/usr/bin/python
import time

print time.time()
print time.localtime(time.time())
print time.asctime(time.localtime(time.time()))
print "delay 5 second"
time.sleep(5)
print time.asctime(time.localtime(time.time()))