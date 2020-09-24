const int ledPin = 11;
int sensorValue;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  sensorValue = analogRead(A0);

  digitalWrite(ledPin,HIGH);
  delay(sensorValue);
  digitalWrite(ledPin,LOW);
  delay(sensorValue);
  Serial.print(sensorValue);
  Serial.print("\n");
}
