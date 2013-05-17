import serial
import time

usbPath = raw_input('Please enter the path to the device: ')
def main():
	serialWrite()
def serialWrite():
	#clientInput = raw_input('> ')
	ser = serial.Serial(usbPath, 9600)
	#ser.write(clientInput)
	logfile = open('log.html', 'a+', 0)
	logfile.write('<html><meta http-equiv="refresh" content ="5"></html>')
	logfile.write('<p>' + ser.readline())
	#logfile.write(ser.readline())
	logfile.close()
	main()

if __name__ == '__main__':
  main()