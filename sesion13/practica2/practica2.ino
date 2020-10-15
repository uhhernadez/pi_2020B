// Programación Interactiva 2020b
// Pines de leds
// 3, 5, 6, 9, 10 PWD
const int leds[] = {3, 5, 6, 9, 10};
int pinIntensidad = A0;
int seleccion = 0;
int orientacion = true;

void setup() {
    // 9600 Bauds
    Serial.begin(9600);
    pinMode(pinIntensidad, INPUT);
    for (int k = 0; k < 5; k++) {
      pinMode(leds[k], OUTPUT);
    }
}

void loop() {
    int intensidad = analogRead(pinIntensidad);
    Secuencia(seleccion, intensidad/4);
    delay(200);
    seleccion = Siguiente(seleccion);
}

void Secuencia(int led, int intensidad) {
    for (int k = 0; k < 5; k++) {
      analogWrite(leds[k], 0);
    }
    analogWrite(leds[led], intensidad);
}

int Siguiente(int actual) {
  // Cuando la orientacion es positiva se incrementa la variable
  if(orientacion) {
    if(actual == 4) {
      orientacion = false;
      return 3;  
    }  
    return actual + 1;
  // Cuando la orientacion es negativa se decrementa
  } else {
    if(actual == 0) {
      orientacion = true;
      return 1;  
    }    
    return actual - 1;
  }
}
