# Stream Video with OpenCV from an Android running IP Webcam (https://play.google.com/store/apps/details?id=com.pas.webcam)
# Code Adopted from http://stackoverflow.com/questions/21702477/how-to-parse-mjpeg-http-stream-from-ip-camera
#
# Pip install the client:
# pip install clarifai
#

# The package will be accessible by importing clarifai:

from clarifai import rest
from clarifai.rest import ClarifaiApp
from clarifai.rest import Image as ClImage
# The client takes the `APP_ID` and `APP_SECRET` you created in your <a href="/account/application">Clarifai
# account.</a> You can set these variables in your environment as:

# - `CLARIFAI_APP_ID`
# - `CLARIFAI_APP_SECRET`

import sys
sys.path.insert(0, '/usr/local/lib/python2.7/site-packages')
import numpy as np
import cv2
import urllib2
	
host = "10.0.1.35:8080"
if len(sys.argv)>1:
    host = sys.argv[1]

hoststr = 'http://' + host + '/video'
print 'Streaming ' + hoststr

stream=urllib2.urlopen(hoststr)

app = ClarifaiApp("4dR2VJxpC1r5oHSwjk_0XnQXK7k5jEv6tRcuDVb9", "6o187-_f803bdezLfDCZNj5mKqf9_LAKFq95UACD")
# get the general model
model = app.models.get("aaa03c23b3724a16a56b629203edc62c")

bytes=''
while True:
    #image = ClImage(file_obj=open('/Users/simon.guo/Desktop/coke.jpg', 'rb'))
    #print (model.predict([image]))
    bytes+=stream.read(1024)
    a = bytes.find('\xff\xd8')
    b = bytes.find('\xff\xd9')
    if a!=-1 and b!=-1:
        jpg = bytes[a:b+2]
        bytes= bytes[b+2:]
        i = cv2.imdecode(np.fromstring(jpg, dtype=np.uint8),cv2.CV_LOAD_IMAGE_COLOR)
        cv2.imshow(hoststr,i)
        if cv2.waitKey(1) == 27: #esc key
            exit(0)
        else if cv2.waitKey(1) == 13: #enter key
            #image = ClImage(file_obj=open('/Users/simon.guo/Desktop/coke.jpg', 'rb'))
            #print (model.predict([image]))
            cv2.imwrite("result.jpg", jpg)



# predict with the model
#result = model.predict_by_url(url='https://samples.clarifai.com/metro-north.jpg')
#print(result)

#

