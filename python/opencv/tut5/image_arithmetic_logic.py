#!/usr/bin/python3

import cv2
import numpy as np

baby = cv2.imread("/home/pvbinh/work/python/opencv/marterial/baby.jpg", cv2.IMREAD_COLOR)
cv2.imshow("baby", baby)

logo = cv2.imread("/home/pvbinh/work/python/opencv/marterial/Capture.JPG", cv2.IMREAD_COLOR)
cv2.imshow("logo", logo)

#only for same size image
#add = baby + logo 
#cv2.imshow("add", add)

#put logo on the left corner
rows,cols,channels = logo.shape
roi = baby[0:rows,0:cols]

#creat a mask of logo and create it inverse mask
logogray = cv2.cvtColor(logo,cv2.COLOR_BGR2GRAY)

cv2.imshow('logogray', logogray) 
#add a threshold
ret, mask = cv2.threshold(logogray, 220, 255, cv2.THRESH_BINARY_INV)

cv2.imshow('mask', mask) 
mask_inv = cv2.bitwise_not(mask)
cv2.imshow('mask_inv', mask_inv) 
#now black-out the area of logo in ROI
baby_bg = cv2.bitwise_and(roi,roi,mask = mask_inv)
cv2.imshow('baby_bg', baby_bg) 
#take only region of logo from logo image
logo_fg = cv2.bitwise_and(logo, logo, mask = mask)
cv2.imshow('logo_fg', logo_fg) 
dst = cv2.add(baby_bg, logo, mask = mask)
cv2.imshow('dst', dst) 
dst = cv2.add(baby_bg, logo_fg)
baby[0:rows,0:cols] = dst

cv2.imshow('res', baby) 
cv2.waitKey(0)
cv2.destroyAllWindows()
