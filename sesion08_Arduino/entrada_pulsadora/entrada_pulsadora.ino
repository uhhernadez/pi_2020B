const int buttonPin = 2;
const int ledPin = 11;

int ledState = HIGH;
int lastReading = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  int reading = digitalRead(buttonPin);

  if(reading == HIGH && lastReading == LOW) {
    ledState = (ledState == HIGH)? LOW: HIGH;
  }
  
  digitalWrite(ledPin, ledState);
  lastReading = reading;
}
