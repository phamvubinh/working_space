#!/usr/bin/python3
import cv2
import numpy as np
cap = cv2.VideoCapture('/home/pvbinh/work/python/opencv/marterial/SampleVideo_1280x720_30mb.flv')

while(cap.isOpened()):
	ret, frame = cap.read();
	if ret==True:
		hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

		lower_red = np.array([30, 150, 150])
		upper_red = np.array([60, 255, 255])

		mask = cv2.inRange(hsv, lower_red, upper_red)
		res = cv2.bitwise_and(frame, frame, mask=mask)

		laplacian = cv2.Laplacian(frame, cv2.CV_64F)
		sobelx = cv2.Sobel(frame, cv2.CV_64F, 1, 0, ksize=5)
		sobely = cv2.Sobel(frame, cv2.CV_64F, 0, 1, ksize=5)

		cv2.imshow('Original',frame)
		cv2.imshow('Mask',mask)
		cv2.imshow('laplacian',laplacian)
		cv2.imshow('sobelx',sobelx)
		cv2.imshow('sobely',sobely)

		edges = cv2.Canny(frame,100,200)
		cv2.imshow('Edges',edges)

		k = cv2.waitKey(5) & 0xFF
		if k == ord('q'):
			break

cv2.destroyAllWindows()
cap.release()