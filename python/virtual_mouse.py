import cvzone
from cvzone.HandTrackingModule import HandDetector
import cv2
import pyautogui
cap = cv2.VideoCapture(0)
cap.set(3, 1500)
cap.set(4, 900)
detector = HandDetector(detectionCon=0.6,maxHands=1,minTrackCon=0.4)

while  True:
    success,img=cap.read()
    img=cv2.flip(img,1)
    hands, img = detector.findHands(img)
    if hands:
        hand=hands[0]
        lmList1 = hand["lmList"]
        #print(lmList1)
        x=lmList1[8][0]
        y=lmList1[8][1]
        pyautogui.moveTo(x, y)
        length_single_click, info, img = detector.findDistance(lmList1[8], lmList1[12], img)
        length_double_click, info, img = detector.findDistance(lmList1[12], lmList1[16], img)
        if length_single_click<40:
            pyautogui.click(button='left')
        if length_double_click+length_single_click<90:
            pyautogui.click(clicks=2,interval=0,button=pyautogui.PRIMARY)
        
    cv2.imshow("Image",img)
    cv2.waitKey(1)