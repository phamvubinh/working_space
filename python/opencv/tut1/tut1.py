#!/usr/bin/python3

import cv2
import numpy as np
import matplotlib.pyplot as plt

print("Reading baby.jpg image")

img = cv2.imread('baby.jpg', cv2.IMREAD_GRAYSCALE)
#IMREAD_COLOR = 1 
#IMREAD_UNCHANGED = -1


#cv2.imshow('image', img)
#cv2.waitKey(0)
#cv2.destroyAllWindows()

plt.imshow(img, cmap='gray', interpolation='bicubic')
plt.plot([50, 100], [120, 100], 'd', linewidth=5)
plt.show()

cv2.imwrite('babygray.jpg', img)
