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
    
    if (inChar == '0') {
      digitalWrite(pin, LOW);
    }
    if (inChar == '1') {
      digitalWrite(pin, HIGH);
    }
    if (inChar == 'on') {
      digitalWrite(pin, HIGH);
    }
    if (inChar == 'off') {
      digitalWrite(pin, LOW);
    }
    if (inChar == 'status') {
      boolean pinStatus = digitalRead(pin);
      Serial.print(pinStatus, BIN);
    }
    if (inChar == '2') {
      boolean pinStatus = digitalRead(pin);
      Serial.print(pinStatus, BIN);
    }
    if (inChar == '\n') {
      messageFinished = true;
    }
  }
}

