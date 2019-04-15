#!/usr/bin/python3
import numpy as np
import cv2
from matplotlib import pyplot as plt

img = cv2.imread("/home/pvbinh/work/python/opencv/marterial/baby.jpg", cv2.IMREAD_COLOR)

mask = np.zeros(img.shape[:2], np.uint8)

bgdModel = np.zeros((1,65), np.float64)
fgdModel = np.zeros((1,65), np.float64)

#spider = img[140:200, 270:340]
rect = (270,140,70,70)

cv2.grabCut(img, mask, rect, bgdModel, fgdModel, 5, cv2.GC_INIT_WITH_RECT)
mask2 = np.where((mask==2)|(mask==0),0,1).astype('uint8')
print(mask2)
img = img*mask2[:,:,np.newaxis]

plt.imshow(img)
plt.colorbar()
plt.show()