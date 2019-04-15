#!/usr/bin/python3
import cv2
import numpy as np

cap = cv2.VideoCapture('/home/pvbinh/work/python/opencv/marterial/SampleVideo_1280x720_30mb.flv')

while(cap.isOpened()):
	ret, frame = cap.read()
	if ret==True:
		hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

		lower_red = np.array([30,40,40])
		upper_red = np.array([90,255,255])

		mask = cv2.inRange(hsv, lower_red, upper_red)
		res = cv2.bitwise_and(frame, frame, mask=mask)

		kernel = np.ones((5,5),np.uint8)
		erosion = cv2.erode(mask, kernel, iterations = 1)
		dilation = cv2.dilate(mask, kernel, iterations = 1)

		opening = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
		closing = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)

		cv2.imshow('Original', frame)
		cv2.imshow('Mask', mask)
		cv2.imshow('Erosion', erosion)
		cv2.imshow('Dilation', dilation)

		cv2.imshow('Opening', opening)
		cv2.imshow('Closing', closing)

		k = cv2.waitKey(5) & 0xFF
		if k == ord('q'):
			break

cv2.destroyAllWindows()
cap.release()