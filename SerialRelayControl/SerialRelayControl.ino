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
String inputString;
boolean messageFinished;

void setup() {
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  
  Serial.begin(9600);
  digitalWrite(pin0, LOW);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, LOW);
  
  Serial.println("Ready!\nEnter a command. ex: 'turn on 0;' turns on pin 0.");
}


//MAIN LOOP
void loop() {
 catchSerialEvent();
 //Serial.println("main loop running...");
}

void catchSerialEvent(){
  //Serial.println("catchSerialEvent method fired");
  inputString = "";
  messageFinished = false;
  char inChar;
  while (Serial.available() && !messageFinished) {
    //Serial.println("serial event captured");
    inChar = (char)Serial.read();
    inputString += (String)inChar;
    delay(50);
    Serial.println("inputString is "+inputString);
    //; is the termination character
    if (inChar == ';') {
      messageFinished = true;
      Serial.println("Message successfully recieved: "+ inputString);
      //attempt to execute command
      execute(inputString);
      //clear inputString
      inputString = "";
    }
  }
}
void execute(String message){
  //execute command based on message
    if (message.equals("0;")) {
      digitalWrite(pin0, LOW);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      digitalWrite(pin5, LOW);
      digitalWrite(pin6, LOW);
      digitalWrite(pin7, LOW);
      Serial.println("All Pins turned off.");
    }
    if (message.equals("1;")) {
      digitalWrite(pin0, HIGH);
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, HIGH);
      digitalWrite(pin5, HIGH);
      digitalWrite(pin6, HIGH);
      digitalWrite(pin7, HIGH);
      Serial.println("All pins turned on.");
    }
    if (message.equals("0:0;")) {
        digitalWrite(pin0, LOW);
        Serial.println("Pin 0 turning off.");
    }
    if (message.equals("1:0;")) {
      digitalWrite(pin0, HIGH);
      Serial.println("Pin 0 turning on.");
    }
    if (message.equals("2:0;")) {
      boolean pinStatus = digitalRead(pin0);
      Serial.println(pinStatus);
    }
    if (message.equals("0:1;")) {
      digitalWrite(pin1, LOW);
      Serial.println("Pin 1 turning off.");
    }
    if (message.equals("1:1;")) {
      digitalWrite(pin1, HIGH);
      Serial.println("Pin 1 turning on.");
    }
    if (message.equals("2:1;")) {
      boolean pinStatus = digitalRead(pin1);
      Serial.println(pinStatus);
    }
    if (message.equals("0:2;")) {
      digitalWrite(pin2, LOW);
      Serial.println("Pin 2 turning off.");
    }
    if (message.equals("1:2;")) {
      digitalWrite(pin2, HIGH);
      Serial.println("Pin 2 turning on.");
    }
    if (message.equals("2:2;")) {
      boolean pinStatus = digitalRead(pin2);
      Serial.println(pinStatus);
    }
    if (message.equals("0:3;")) {
      digitalWrite(pin3, LOW);
      Serial.println("Pin 3 turning off.");
    }
    if (message.equals("1:3;")) {
      digitalWrite(pin3, HIGH);
      Serial.println("Pin 3 turning on.");
    }
    if (message.equals("2:3;")) {
      boolean pinStatus = digitalRead(pin3);
      Serial.println(pinStatus);
    }
}
