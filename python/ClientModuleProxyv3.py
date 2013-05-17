import serial
import time

usbPath = raw_input('Please enter the path to the device: ')
def main():
	serialWrite()
def serialWrite():
	i = 0
	ser = serial.Serial(usbPath, 9600)
	while i < 10:
		clientInput = raw_input('> ')
		ser.write(clientInput)
		logfile = open('log.html', 'a+', 0)
		logfile.write('<p>' + ser.readline())
		i = i + 1
		print ('Reached end of file')
	logfile.close()
	logfile = open('log.html', 'w+', 0)
	backupfile = open('backup.txt', 'a+', 0)
	for line in logfile.readline():
		print line
		backupfile.write(line)
	logfile.write('<html><meta http-equiv="refresh" content ="5"></html>')
	logfile.close()
	backupfile.close()
	main()

if __name__ == '__main__':
  main()