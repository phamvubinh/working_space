#!/usr/bin/python3
import numpy as np
import cv2
import matplotlib.pyplot as plt

img1 = cv2.imread('/home/pvbinh/work/python/opencv/marterial/opencv-feature-matching-template.jpg', 0)
img2 = cv2.imread('/home/pvbinh/work/python/opencv/marterial/opencv-feature-matching-image.jpg', 0)

# detector that going to use in this feature
orb = cv2.ORB_create()

#Here, we find the key points and their descriptors with the orb detector
kp1, des1 = orb.detectAndCompute(img1,None)
kp2, des2 = orb.detectAndCompute(img2,None)

# BFMatcher object
bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)

# create matches of the descriptors, then sort them based on the distances
matches = bf.match(des1,des2)
matches = sorted(matches, key = lambda x:x.distance)

# draw the first 10 match
img3 = cv2.drawMatches(img1, kp1, img2, kp2, matches[:10], None, flags=2)
plt.imshow(img3)
plt.show()