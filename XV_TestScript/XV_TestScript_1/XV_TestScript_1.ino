int pin = 11; //This is the pin that information is being read from.
String inputString = ""; //
boolean messageFinished = false;

void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (messageFinished) {
    Serial.println(inputString);
    inputString = "";
    messageFinished = false;
  }
}

void serialEvent(){
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += (String)inChar;
    
    if (inChar == '\n') {
      messageFinished = true;
    } 
  }
  //test
  
  //execute command based on charset
    if (inputString == "0") {
        digitalWrite(pin, LOW);
      }
    if (inputString == "1") {
      digitalWrite(pin, HIGH);
    }
    if (inputString == "on") {
      digitalWrite(pin, HIGH);
    }
    if (inputString == "off") {
      digitalWrite(pin, LOW);
    }
    if (inputString == "status") {
      boolean pinStatus = digitalRead(pin);
      Serial.print(pinStatus, BIN);
    }
    if (inputString == "2") {
      boolean pinStatus = digitalRead(pin);
      Serial.print(pinStatus, BIN);
    }
  
}

