//XV OCEANS http://xv-oceans.com
//SERIAL RELAY CONTROL

//SETUP
//These are the pins information is read from
int pin0 = 0;
int pin1 = 1; 
int pin2 = 2; 
int pin3 = 3; 
int pin4 = 4; 
int pin5 = 5; 
int pin6 = 6; 
int pin7 = 7; 
//These are the variables status, commands, and "acting pins" are stored in.
int pinString;
int pinState;
String inputString;
String statusString;
//These are checks to end while loops.
boolean messageFinished;
boolean statusFinished;

void setup() {
  //Set every pin as output
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  
  //Start serial and set all pins to off.
  Serial.begin(9600);
  digitalWrite(pin0, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, LOW);
  //delay for stability
  delay(50);
  Serial.println("Ready!");
  Serial.println("Type 0 (off), 1 (on), or 2 (state) followed by : and then the pin you're using. E.G. 1:1;");
}


//MAIN LOOP
void loop() {
 catchSerialEvent();
 //Serial.println("main loop running...");
}

void catchSerialEvent(){
  //Serial.println("catchSerialEvent method fired");
  inputString = "";
  statusString = "";
  messageFinished = false;
  statusFinished = false;
  char inChar;
  while (Serial.available() && !messageFinished && !statusFinished) {
    //Serial.println("serial event captured");
    inChar = (char)Serial.read();
    statusString += (String)inChar;
    //delay for stability
    delay(50);
    //Checks if the command section of the input is finished.
    if (inChar == ':') {
      statusFinished = true;
    }
  }
  while (Serial.available() && !messageFinished && statusFinished) {
    pinString = (int)Serial.read() - 48;
    //Turn the character form of the numbers into the int form so digitalWrite accepts them.
    inChar = (char)Serial.read();
/*    if (inChar == '0') {
      pinString = 0;
    }
    else if (inChar == '1') {
      pinString = 1;
    }
    else if (inChar == '2') {
      pinString = 2;
    }
    else if (inChar == '3') {
      pinString = 3;
    }
    else if (inChar == '4') {
      pinString = 4;
    }
    else if (inChar == '5') {
      pinString = 5;
    }
    else if (inChar == '6') {
      pinString = 6;
    }
    else if (inChar == '7') {
      pinString = 7;
    }
    */
    //Debugging
/*    Serial.println("inputString is "+inputString);
    delay(10);
    Serial.println("statusString is "+statusString);
    delay(10);
    Serial.println("pinString is "+(String)pinString);
*/
    //; is the termination character
    if (inChar == ';') {
      messageFinished = true;
      //attempt to execute command
      execute(statusString, pinString);
      //reset all variables.
      inputString = "";
      statusString = "";
    }
  }
}
void execute(String pinStatus, int pinNumber){
  //execute command based on message
  if (pinStatus.equals("0:")) {
    digitalWrite(pinNumber, LOW);
    Serial.println("Pin "+(String)pinNumber+" turning off.");
    pinState = 0;
    
  }
  if (pinStatus.equals("1:")) {
    digitalWrite(pinNumber, HIGH);
    Serial.println("Pin "+(String)pinNumber+" turning on.");
    pinState = 1;
  }
  if (pinStatus.equals("2:")) {
    Serial.println(pinState);
  }
}

