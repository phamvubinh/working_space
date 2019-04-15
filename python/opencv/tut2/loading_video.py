#!/usr/bin/python3
#https://pythonprogramming.net/loading-video-python-opencv-tutorial/?completed=/loading-images-python-opencv-tutorial/

import cv2
import numpy as np

print("Loading video")


#cap = cv2.VideoCapture('/home/pvbinh/work/python/opencv/tut2/small.flv', apiPreference=cv2.CAP_FFMPEG)

cap = cv2.VideoCapture('/home/pvbinh/work/python/opencv/tut2/small.flv')

# Get current width of frame
#width = cap.get(cv2.cv.CV_CAP_PROP_FRAME_WIDTH)   # float
# Get current height of frame
#height = cap.get(cv2.cv.CV_CAP_PROP_FRAME_HEIGHT) # float
ret, frame = cap.read()
print('ret =', ret, 'W =', frame.shape[1], 'H =', frame.shape[0], 'channel =', frame.shape[2])

#important need to get correct frame size
FrameSize=(frame.shape[1], frame.shape[0])
fourcc = cv2.VideoWriter_fourcc(*'FLV1')

#https://stackoverflow.com/questions/35531233/cannot-save-gray-frames-but-no-problems-to-save-the-original-color-frames
#Need to add false option to save gray frame to output
out = cv2.VideoWriter('output_gray.avi', fourcc, 20.0, FrameSize, False)

if (cap.isOpened() == False):
	print("Error openingggg video stream or file ")

while(cap.isOpened()):
	ret, frame = cap.read()

	if ret == True:
		gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
		#save gray frame to output
		out.write(gray)

		cv2.imshow('Frame', frame)
		if cv2.waitKey(25) & 0xFF == ord('q'):
			break
	else:
		break

cap.release()
out.release()
cv2.destroyAllWindows()

cap = cv2.VideoCapture('/home/pvbinh/work/python/opencv/tut2/output_gray.avi')
if (cap.isOpened() == False):
	print("Error openingggg video stream or file ")
while(cap.isOpened()):
	ret, frame = cap.read()

	if ret == True:
		cv2.imshow('Frame2', frame)
		if cv2.waitKey(25) & 0xFF == ord('q'):
			break
	else:
		break


cap.release()
#out.release()
cv2.destroyAllWindows() 
