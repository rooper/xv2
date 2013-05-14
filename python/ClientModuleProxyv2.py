import serial
import socket

usbPath = raw_input('Please enter the path to the device (/dev/tty...): ')

def main():
    serverCatch()

def serverCatch():
    host = ''
    port = 24632
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind((host, port))
    server.listen(1)
    serversock, serveraddr = server.accept()
    serverfile = serversock.makefile('rw', 0)
    serverfile.write('HTTP/1.1 200 OK\n\n')
    serverfile.write('<html><head><title>Welcome %s!</title></head>' %(str(serveraddr)))
    serverfile.write('<body><br>%s' % serial.log.readline())
    serverfile.write('</body></html>')
    serialLoop()

def serialLoop():
	serial_log = open("log.txt", "w")
	#Define clientInput and usbPath
	clientInput = raw_input('> ')
	#Open Serial Comm.
	print("Debug clientInput: " + clientInput)
	if clientInput == exit:
		serial_log.close()
		server.close()
	ser = serial.Serial(usbPath, 9600)
	print("Debug serial started")
	#Write clientInput to serial
	ser.write(clientInput)
	#Print actual line
	temp_serial = ser.readline()
	print ("Debug temp_serial")
	serial_log.write(temp_serial + '\n')
	print("Debug temp_serial: " + temp_serial)
	serialLoop()

if __name__ == '__main__':
  main()