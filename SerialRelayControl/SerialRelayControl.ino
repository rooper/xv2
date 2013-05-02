//xv oceans relay module serial control
//test comment.

void setup() {
  Serial.begin(57600);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  Serial.println("Ready");
}


void loop() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    if (inChar == '1') {
      digitalWrite(1, HIGH);
      Serial.println("turning on 1");
    }
    if (inChar == '0') {
      digitalWrite(0, HIGH);
      Serial.println("turning on 0");
    }
    if (inChar == '2') {
      digitalWrite(0, LOW);
      digitalWrite(1, LOW);
      Serial.println("clearing");
  }
}


