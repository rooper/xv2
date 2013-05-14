import serial
import socket

usbPath = raw_input('Please enter the path to the device (/dev/tty...): ')
host = '10.0.1.3'
port = 80
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((host, port))
print("Debug: Bind complete")
server.listen(1)
serversock, serveraddr = server.accept()
serverfile = serversock.makefile('rw', 0)

def main():
    serverCatch()

def serverCatch():
    temp_line = serverfile.readline()
    serverfile.write(temp_line)
    serialLoop()

def serialLoop():
	serial_log = serverfile
	#Define clientInput and usbPath
	clientInput = raw_input('> ')
	#Open Serial Comm.
	if clientInput == exit:
		serial_log.close()
		server.close()
	ser = serial.Serial(usbPath, 9600)
	#Write clientInput to serial
	ser.write(clientInput)
	#Print actual line
	temp_serial = ser.readline()
	serial_log.write(temp_serial + '\n')
	main()

if __name__ == '__main__':
  main()