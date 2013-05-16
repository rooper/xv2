import serial

usbPath = raw_input('Please enter the path to the device: ')
def main():
	serialWrite()
def serialWrite():
	clientInput = raw_input('> ')
	ser = serial.Serial(usbPath, 9600)
	ser.write(clientInput)
	logfile = open('log.txt', 'a+', 0)
	logfile.write(ser.readline())
	logfile.close()
	main()

if __name__ == '__main__':
  main()