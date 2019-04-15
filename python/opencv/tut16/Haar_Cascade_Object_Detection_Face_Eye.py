#!/usr/bin/python3
import numpy as np
import cv2

# multiple cascades: https://github.com/Itseez/opencv/tree/master/data/haarcascades
# https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml

face_cascade = cv2.CascadeClassifier('/home/pvbinh/work/python/opencv/marterial/haarcascade_frontalface_default.xml')
#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_eye.xml
eye_cascade = cv2.CascadeClassifier('/home/pvbinh/work/python/opencv/marterial/haarcascade_eye.xml')

img = cv2.imread('/home/pvbinh/work/python/opencv/marterial/DangThiThuyLinh.JPG')
cv2.imshow('img',img)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('gray',gray)

#faces = face_cascade.detectMultiScale(gray, 1.3, 5)

# Detect faces in the image
faces = face_cascade.detectMultiScale(
    gray,
    scaleFactor=1.1,
    minNeighbors=5,
    minSize=(30, 30),
    flags = cv2.CASCADE_SCALE_IMAGE
)

for (x,y,w,h) in faces:
	cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
	roi_gray = gray[y:y+h, x:x+w]
	roi_color = img[y:y+h, x:x+w]

eyes = eye_cascade.detectMultiScale(roi_gray, flags = cv2.CASCADE_SCALE_IMAGE)
for (ex,ey,ew,eh) in eyes:
    cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0), 2)

cv2.imshow('img',img)
cv2.waitKey(0)

cap.release()
cv2.destroyAllWindows()