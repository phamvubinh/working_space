#!/usr/bin/python3
# implement 3 ways for threshold
import cv2
import numpy as np

img = cv2.imread('/home/pvbinh/work/python/opencv/marterial/bookpage.jpg')
# gray scale the image
grayscaled = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
# set threshold value to change to black and white
retval, threshold = cv2.threshold(grayscaled, 12, 255, cv2.THRESH_BINARY)
cv2.imshow('origial1', img)
cv2.imshow('threshold', threshold)

th = cv2.adaptiveThreshold(grayscaled, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 115, 1)
cv2.imshow('origial2', img)
cv2.imshow('Adaptive threshold',th)

retval2,threshold2 = cv2.threshold(grayscaled,125,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
cv2.imshow('original3',img)
cv2.imshow('Otsu threshold',threshold2)

cv2.waitKey(0)
cv2.destroyAllWindows()