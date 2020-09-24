const int buttonPin = 2;
const int ledPin = 11;

int ledState = HIGH;
int lastReading = LOW;

int reboteEspera = 150;
int ultimoCambio = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {  
  int reading = digitalRead(buttonPin);

  if ((millis() - ultimoCambio) > reboteEspera) {
    if(reading == HIGH && lastReading == LOW) {
      ledState = (ledState == HIGH)? LOW: HIGH;
      ultimoCambio = millis();
    }
  }
  digitalWrite(ledPin, ledState);
  lastReading = reading;
}
