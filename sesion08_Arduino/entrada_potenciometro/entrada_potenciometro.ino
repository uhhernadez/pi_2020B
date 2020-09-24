const int ledPin = 11;
int sensorValue;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  sensorValue = analogRead(A0);

  digitalWrite(ledPin,HIGH);
  delay(sensorValue);
  digitalWrite(ledPin,LOW);
  delay(sensorValue);
  
}
