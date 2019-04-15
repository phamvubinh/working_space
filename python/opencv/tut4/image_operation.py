#!/usr/bin/python3
import cv2
import numpy as np

img = cv2.imread("/home/pvbinh/work/python/opencv/marterial/baby.jpg", cv2.IMREAD_COLOR)

px = img[55,55]
print(px)

px = img[100:150, 100:150]
print(px)

img[100:150,100:150] = [0,255,0]

print(img.shape)
print(img.size)
print(img.dtype)

spider = img[140:200, 270:340]

img[0:60, 0:70] = spider

cv2.imshow('image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()

