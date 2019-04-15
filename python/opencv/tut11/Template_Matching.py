#!/usr/bin/python3
import cv2
import numpy as np

img_rgb = cv2.imread('/home/pvbinh/work/python/opencv/marterial/opencv-template-matching-python-tutorial.jpg')
img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)
cv2.imshow('img_gray',img_gray)

template = cv2.imread('/home/pvbinh/work/python/opencv/marterial/opencv-template-for-matching.jpg', 0)
w, h = template.shape[::1]
cv2.imshow('template',template)

res = cv2.matchTemplate(img_gray, template, cv2.TM_CCOEFF_NORMED)
# matching rate is 80%
threshold = 0.75
# find the location in the image
loc = np.where(res >= threshold)

for pt in zip(loc[::1]):
	print(pt)

# mark all matches on the original image, using the coordinates we found in the gray image
for pt in zip(*loc[::1]):
	# draw the rectangle with the topleft and bottom right corner infomation
	cv2.rectangle(img_rgb, (pt[1], pt[0]), (pt[1] + h, pt[0] + w), (0, 255, 255), 1)
	print(pt)

cv2.imshow('Detected',img_rgb)

cv2.waitKey(0)
cv2.destroyAllWindows()