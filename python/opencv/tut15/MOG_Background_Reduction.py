#!/usr/bin/python3
import numpy as np
import cv2

cap = cv2.VideoCapture('/home/pvbinh/work/python/opencv/tut2/small.flv')
fgbg = cv2.createBackgroundSubtractorMOG2()

while(1):
	ret, frame = cap.read()

	fgmask = fgbg.apply(frame)

	cv2.imshow('fgmask', frame)
	cv2.imshow('frame', fgmask)

	k = cv2.waitKey(30) & 0xFF
	if k == ord('q'):
		break

cap.release()
cv2.destroyAllWindows()