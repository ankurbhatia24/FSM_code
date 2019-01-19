#######################################
###import function
import numpy
import cv2
from picamera import PiCamera
from picamera.array import PiRGBArray
from time import sleep


###initialize a camera
cam=PiCamera()
cap1=PiRGBArray(cam)
#######################################

#######################################
##take the time to initilize 
sleep(8)
###read the image
cam.capture(cap1, format ="bgr")
image =cap1.array

#######################################


#######################################
###Do the processing
#############df##########################

#######################################
### show the image
cv2.imshow('image',image)
#######################################


#######################################
### close and exit
cap1.release()
cv2.waitKey(0)
cv2.destroyAllWindows()
#######################################
