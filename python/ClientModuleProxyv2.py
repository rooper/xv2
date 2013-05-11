usbPath = raw_input('Please enter the path to the device (/dev/tty...): ')

def main():
    #Import PySerial
	import serial
	from time import sleep

    #Define clientInput and usbPath
	clientInput = raw_input('> ')
    #Open Serial Comm.
	ser = serial.Serial(usbPath, 9600)
    	#Write clientInput to serial
	ser.write(clientInput)
    	#Ignore first two lines that will show up (Ready! and Type 1:1;)
    	#Print actual line
    	print ser.readline()
	main()

if __name__ == '__main__':
  main()