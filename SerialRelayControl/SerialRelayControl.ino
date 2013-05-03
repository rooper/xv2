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
    if (message.equals("turn off 0;")) {
        digitalWrite(pin0, LOW);
        Serial.println("Pin 0 turning off.");
      }
    if (message.equals("turn on 0;")) {
      digitalWrite(pin0, HIGH);
      Serial.println("Pin 0 turning on.");
    }
    if (message.equals("status;")) {
      boolean pinStatus = digitalRead(pin0);
      Serial.print(pinStatus, BIN);
    }
  
}

