#!/usr/bin/python3
import cv2
import numpy as np

#cap = cv2.VideoCapture(0)
cap = cv2.VideoCapture('/home/pvbinh/work/python/opencv/marterial/SampleVideo_1280x720_30mb.flv')

while(cap.isOpened()):
	ret, frame = cap.read()
	if ret==True:
		hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

		lower_red = np.array([30,40,40])
		upper_red = np.array([90,255,255])

		mask = cv2.inRange(hsv, lower_red, upper_red)
		res = cv2.bitwise_and(frame, frame, mask=mask)

		cv2.imshow('frame', frame)
		cv2.imshow('mask', mask)
		cv2.imshow('res', res)

		if cv2.waitKey(25) & 0xFF == ord('q'):
			break

cv2.destroyAllWindows()
cap.release(0)

