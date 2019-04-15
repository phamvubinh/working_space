#!/usr/bin/python3
import cv2
import numpy as np

img = cv2.imread("/home/pvbinh/work/python/opencv/marterial/baby.jpg")

cv2.line(img,(0,0),(50,50),(128,128,128),30)
cv2.rectangle(img,(50,250),(100,500),(0,0,255),15)
cv2.circle(img,(350,63),63,(0,255,0),-1)

pts = np.array([[100,50],[200,300],[450,200],[300,100]],np.int32)
pts = pts.reshape((-1,1,2))
cv2.polylines(img,[pts],True,(0,255,255),3)
font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(img,'OpenCV Tuts!', (30, 250), font, 2, (100,255,150), 5, cv2.LINE_AA)

cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()

