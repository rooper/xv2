"""
This is the Serial temperature listener. It will refresh temperature
every 10 seconds. Designed for use with Python SimpleHTTPServer.
"""

import serial
from time import sleep
usbPath = raw_input('Please enter the path to the device')
ser = serial.Serial(usbPath, 9600)
readingfile = open('temp.html', 'a+', 0)
readingfile.write('<html><meta http-equiv="refresh" content ="10"></html>')
def main():
    serialRead()

def serialRead():
    readingfile.write('<p>' + ser.readline())
    sleep(10)
    main()

if __name__ == '__main__':
    main()