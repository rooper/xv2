import serial
import socket

usbPath = raw_input('Please enter the path to the device (/dev/tty...): ')
host = ''
port = 8080
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((host, port))
print("Debug: Bind complete")
server.listen(1)
serversock, serveraddr = server.accept()
serverfile = serversock.makefile('rw', 0)

def main():
    serverWrite()

def serverWrite():
	server.listen(1)
	clientInput = raw_input('> ')
	ser = serial.Serial(usbPath, 9600)
	ser.write(clientInput)
	serverfile.write(ser.readline())
	main()

if __name__ == '__main__':
  main()