//XV OCEANS http://xv-oceans.com
//SERIAL RELAY CONTROL

//SETUP
//This is the pin that information is being read from.
int pin0 = 0;
int pin1 = 1; 
int pin2 = 2; 
int pin3 = 3; 
int pin4 = 4; 
int pin5 = 5; 
int pin6 = 6; 
int pin7 = 7; 
String inputString = ""; //
boolean messageFinished = false;

void setup() {
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  
  Serial.begin(19200);
  digitalWrite(pin0, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, LOW);
  
  Serial.println("Ready!");
}


//MAIN LOOP
void loop() {
 serialEvent();
}

void serialEvent(){
  while (Serial.available() && !messageFinished) {
    char inChar = (char)Serial.read();
    inputString += (String)inChar;
    
    if (inChar == '\n') {
      messageFinished = true;
      Serial.println("Message successfully recieved.");
    } 
  }
  
  //execute command based on message
    if (inputString == "0") {
        digitalWrite(pin0, LOW);
      }
    if (inputString == "1") {
      digitalWrite(pin0, HIGH);
    }
    if (inputString == "on") {
      digitalWrite(pin0, HIGH);
    }
    if (inputString == "off") {
      digitalWrite(pin0, LOW);
    }
    if (inputString == "status") {
      boolean pinStatus = digitalRead(pin0);
      //Serial.print(pinStatus, BIN);
    }
    if (inputString == "2") {
      boolean pinStatus = digitalRead(pin0);
      //Serial.print(pinStatus, BIN);
    }
  
}

