// Programación Interactiva 2020b
// Pines de leds
// 3, 5, 6, 9, 10 PWD
const int leds[] = {3, 5, 6, 9, 10};
int pinIntensidad = A0;
int pinVelocidad = 2;
int pinAlto = 4;
int seleccion = 0;
int tiempoBoton = 100;
int ultimoAlto = 0;
int ultimoVelocidad = 0;

int  velocidad = 1;
bool orientacion = true;
bool alto = false;


void setup() {
    // 9600 Bauds
    Serial.begin(9600);
    pinMode(pinIntensidad, INPUT);
    pinMode(pinVelocidad, INPUT);
    pinMode(pinAlto,INPUT);
    
    for (int k = 0; k < 5; k++) {
      pinMode(leds[k], OUTPUT);
    }
    ultimoAlto = millis();
    ultimoVelocidad = millis();
}

void loop() {
    int intensidad = analogRead(pinIntensidad);
    int altoValor = digitalRead(pinAlto);
    int velocidadValor = digitalRead(pinVelocidad);
    
    Serial.println(altoValor);
    if(millis()- ultimoAlto > tiempoBoton ) {
      if(altoValor == HIGH) {
        alto = (alto == true)? false:true; 
      }
      ultimoAlto = millis();
    }

    if(millis()- ultimoVelocidad > tiempoBoton ) {
      if(velocidadValor == HIGH) {
        velocidad++;
        velocidad = (velocidad%5)+1;
        ultimoVelocidad = millis();
      }
    }
    
    if(!alto) {
      Secuencia(seleccion, intensidad/4);
      seleccion = Siguiente(seleccion);
    }
    
    delay(velocidad * 50);
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
