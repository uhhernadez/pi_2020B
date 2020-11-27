import oscP5.*;
import netP5.*;

// Cliente de osc
OscP5 oscCliente;
// Dirección IP de nuestro parche
NetAddress oscParche;
ArrayList<PVector> puntos;

void setup() {
  size(521,521);
  int puertoEntrada = 12000;
  oscCliente = new OscP5(this, puertoEntrada);
  
  int puertoParche = 13000;
  oscParche = new NetAddress("127.0.0.1", puertoParche);
  puntos = new ArrayList<PVector>();
}

void draw() {
  background(0);
  for(PVector p : puntos) {
    float d = p.mag()/sqrt(2*521*521);
    fill(255*(1-d),0,0);
    ellipse(p.x, p.y, 30, 30);
  } 
}

void mousePressed() {
  EnviarPunto(mouseX, mouseY);
  puntos.add(new PVector(mouseX, mouseY));
}

void EnviarPunto(int x, int y) {
  OscMessage msgX = new OscMessage("/processing/punto/x");
  msgX.add(x);
  oscCliente.send(msgX,oscParche);
  
  OscMessage msgY = new OscMessage("/processing/punto/y");
  msgY.add(y);
  oscCliente.send(msgY,oscParche);
}
