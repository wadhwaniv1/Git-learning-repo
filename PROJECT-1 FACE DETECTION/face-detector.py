import cv2
from random import randrange

#Load some pre trained data on face frontals from opencv(haar cascade algorithm)
trained_face_data = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Choose an image to detect faces
#img = cv2.imread('rd.jpg')
#To capture video from webcam ; 0:default camera
webcam = cv2.VideoCapture(0, cv2.CAP_DSHOW)

#Iterate forever over frames
while True:

    #Read frame (get image out of video)
    successful_frame_read, frame = webcam.read()

    # Must convert to grayscale to deal with just one color instead of bgr
    grayscaled_img = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    #Detect faces
    face_coordinates = trained_face_data.detectMultiScale(grayscaled_img)

    #Draw a rectangle around the face (hardcoded face coordinates)
    #(x,y,w,h) = face_coordinates[0]
    for(x, y, w, h) in face_coordinates:
        cv2.rectangle(frame, (x,y), (x+w, y+h), (randrange(256),randrange(256),randrange(256)), 2)

    # Display the image
    cv2.imshow("Vishal's face detector", frame)

    #wait till key is pressed
    key = cv2.waitKey(1)

    #To remove force quit(Stop if Q key is pressed)
    if key==81 or key==113:
        break

#Release the VideoCapture object
webcam.release()

print("Hey Vishal!!")