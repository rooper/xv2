import socket
import arduinoserial

#Going to have it accepting HTTP POST requests later?
clientInput = raw_input('> ')

#Debugging
#print clientInput
arduino = arduinoserial.SerialPort('/dev/ttyACM0', 9600)
#print arduino.read_until('\n')
arduino.write(clientInput)

#Debugging
#print clientInput + " has been sent to the Arduino"

if clientInput == "read":
    print arduino.read_until('\n')