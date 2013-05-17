"""
run.sh file coming soon, but for right now to start you have to:

python -m SimpleHTTPServer

and in a different window move to the directory this file is in
and run it using:

python ClientModuleProxyv3.py

If you want it to run on a port other then 8000, use:

python -m SimpleHTTPServer [port]

"""
import serial #http://pyserial.sourceforge.net/

#Ask for device path (E.G. /dev/tty.usbmodem611)
#Get a list of devices using: python -m serial.tools.list_ports
usbPath = raw_input('Please enter the path to the device: ')
readOrWrite = raw_input('Are you going to be writing information? :')
def main():
	serialWrite()
def serialWrite():
	i = 0
    #Open serial communication
	ser = serial.Serial(usbPath, 9600)
    #Open log.html for appending, and write the meta refresh tag to it.
	logfile = open('log.html', 'a+', 0)
	logfile.write('<html><meta http-equiv="refresh" content ="5"></html>')
    #10 iterations
	while i < 10:
		clientInput = raw_input('Input command > ')
        #This writes the input (E.G. 1:1; to turn on pin one.)
		ser.write(clientInput)
        #Write arduino output and put space (paragraph tag)
		logfile.write('<p>' + ser.readline())
        #Increment i by one
		i = i + 1
    #Close the file and open it again for overwriting and reading
	logfile.close()
	logfile = open('log.html', 'w+', 0)
    #Open the backup file
	backupfile = open('backup.txt', 'a+', 0)
    #Write every line in the logfile to the backup file
	for line in logfile.readline():
        #Debugging
		print line
		backupfile.write(line)
    #Close all files
	logfile.close()
	backupfile.close()
	main()

if __name__ == '__main__':
  main()