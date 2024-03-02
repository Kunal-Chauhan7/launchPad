import webbrowser as wbs
import pyautogui
import serial
import time
import pywhatkit

from pynput.keyboard import Key, Controller

keyboard = Controller()

def byebye():
    print("Shutting down the computer.")
    time.sleep(2)
    pyautogui.hotkey('win', 'x')
    time.sleep(1)
    pyautogui.press('u')
    pyautogui.press('u')
    time.sleep(1)

def dailyQuestion():
    wbs.open_new_tab("https://www.geeksforgeeks.org/problem-of-the-day")
    wbs.open_new_tab("https://www.codingninjas.com/studio/problem-of-the-day")
    wbs.open_new_tab("https://www.hackerrank.com/contests/daily-challenge/challenges")
    wbs.open_new_tab("https://codeforces.com/contests")
    wbs.open_new_tab("https://leetcode.com/contest/")

def send_msg():
    msg = "Ram Ram Laddar"
    try:
        pywhatkit.sendwhatmsg_instantly(
            phone_no="+918573853018", 
            message=msg,
            tab_close=False,
        )
        time.sleep(60)
        pyautogui.click()
        time.sleep(1)
        keyboard.press(Key.enter)
        keyboard.release(Key.enter)
        time.sleep(2)
        pyautogui.hotkey('ctrl', 'w')
        print("Message sent!")
    except Exception as e:
        print(str(e))


s = serial.Serial('COM6',9600)

while True:
    data = s.readline()
    if(data.decode().strip()=="shutdown"):
        time.sleep(2)
        byebye()
    if(data.decode().strip()=="send"):
        print("sending!")
        time.sleep(2)
        send_msg()
    if(data.decode().strip()=="leetcode"):
        print("openning")
        time.sleep(2)
        dailyQuestion()
    if(data.decode().strip()=="hide"):
        print("hide!!")
        time.sleep(2)
        pyautogui.hotkey('win', 'm')        
