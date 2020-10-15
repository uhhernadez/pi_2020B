// Programación Interactiva 2020b
// Pines de leds
// 3, 5, 6, 9, 10 PWD
int led0 = 3, led1 =5, led2 = 6,  led3 = 9, led4 = 10;
int seleccion = 0;

void setup() {
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  Secuencia(seleccion%5);
  delay(200);
  seleccion++;
}

void Secuencia(int led) {
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  
  switch(led) {
    case 0:  digitalWrite(led0,HIGH); break;   
    case 1:  digitalWrite(led1,HIGH); break;
    case 2:  digitalWrite(led2,HIGH); break;
    case 3:  digitalWrite(led3,HIGH); break;
    case 4:  digitalWrite(led4,HIGH); break;
  }
}
