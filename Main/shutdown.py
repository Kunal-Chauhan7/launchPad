import pyautogui
import time
def shutdown():
    time.sleep(2)
    pyautogui.hotkey('win', 'x')
    time.sleep(1)
    pyautogui.press('u')
    pyautogui.press('u')
    time.sleep(1)

shutdown()