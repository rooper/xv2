import serial
import socket
import errno

usbPath = raw_input('Please enter the path to the device (/dev/tty...): ')
host = ''
port = 8081
#This opens an IPv4 socket and sets it to TCP.
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#This sets up the socket, allowing it to reuse the address
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#This starts the server itself
server.bind((host, port))
#This listens on the socket we setup
server.listen(1)
serversock, serveraddr = server.accept()
#This makes a read/write file with no buffer
serverfile = serversock.makefile('rw', 0)

def main():		
	serverWrite()

def serverWrite():
	server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	server.listen(1)
	clientInput = raw_input('> ')
	if clientInput == 'read':
		logfile = open('log.txt', 'r', 0)
		for line in logfile:
			try:
				serverfile.write(line)
			except socket.error, e:
				server.close()
				server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
				server.bind((host, port))
				server.listen(1)
				serversock, serveraddr = server.accept()
		logfile.close()
	elif clientInput != 'read':
		ser = serial.Serial(usbPath, 9600)
		ser.write(clientInput)
		tempread = ser.readline()
		#serverfile.write(tempread)
		logfile = open('log.txt', 'a+', 0)
		logfile.write(tempread)
		logfile.close()
	main()

if __name__ == '__main__':
  main()