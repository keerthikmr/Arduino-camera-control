import serial #Serial imported for Serial communication

import time #Required to use delay functions

import pyautogui #Use to feed computer commands and hotkeys

ArduinoSerial = serial.Serial('com3',9600) #Create Serial port object called arduinoSerialData, baud rate 9600

time.sleep(2) #wait for 2 seconds for the communication to get established                                                                       
                 
while 1:

    incoming = str (ArduinoSerial.readline()) #read the serial data and print it as line

    if 'Capture' in incoming:
        pyautogui.keyDown('ctrl')
        pyautogui.typewrite(['space'], 0.2)
        pyautogui.keyUp('ctrl')
        print("Image captured")

       
    if 'Zoom in' in incoming:
        pyautogui.keyDown('ctrl')
        pyautogui.scroll(100)
        print("Zooming in")
        pyautogui.keyUp('ctrl')
                               
    if 'Zoom lock' in incoming:
        print("Zoom ready")
        
    if 'Zoom out' in incoming:
        pyautogui.keyDown('ctrl')
        pyautogui.scroll(-100)
        print("Zooming out")
        pyautogui.keyUp('ctrl')
                         
                                        
    incoming = "";
     