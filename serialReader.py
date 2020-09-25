
import serial
import time

import win32com.client

#The following line is for serial over GPIO
port = 'COM7'


ard = serial.Serial(port,9600,timeout=5)

shell = win32com.client.Dispatch("WScript.Shell")
#shell.AppActivate("Notepad")

def findPreamble(msg):
    if(len(msg) < 5):
        return False
    preamble = "FFFE"

    for i in range(len(preamble)):
        if(msg[i] != preamble[0]):
            return False
        return True
    


#print("here")
while (True):

    # Serial read section
    msg = ard.readline()
    msgStr = msg.decode("utf-8") 
    #print("Message from arduino: ")
    #print(msg)

    time.sleep(0.05)
    if(findPreamble(msgStr)):
        shell.SendKeys(str(msgStr[4]))

    ard.reset_input_buffer()
    #print(str(msg)) # CTRL+A may "select all" depending on which window's focused
    #shell.SendKeys("{DELETE}") # Delete selected text?  Depends on context. :P
    #shell.SendKeys("{TAB}") #Press tab... to change focus or whatever
exit()