#include <PS2X_lib.h>

#define dirFrente 5 
#define dirTras   3

#define esqFrente 9
#define esqTras   6

#define FRENTE 1
#define PARADO 0
#define TRAS  -1

#define velocidadeE 100
#define velocidadeD 110

PS2X ps2x;

void configuraControle() {
  int erroControle = ps2x.config_gamepad(13, 11, 10, 12, true, true);
  if (!erroControle) {
    Serial.println("Controle encontrado");
  } else {
    Serial.println("Controle não encontrado");
    while (erroControle) {
      if (bitRead(millis(), 11)) erroControle = ps2x.config_gamepad(13, 11, 10, 12, true, true);
    }
  }
}

void setup() {
  Serial.begin(9600);

  configuraControle();

  pinMode(dirFrente, OUTPUT);
  pinMode(dirTras,   OUTPUT);
  pinMode(esqFrente, OUTPUT);
  pinMode(esqTras,   OUTPUT);

  digitalWrite(dirFrente, LOW);
  digitalWrite(dirTras,   LOW);
  digitalWrite(esqFrente, LOW);
  digitalWrite(esqTras,   LOW);

}

void andarFrente(){
  // MOTOR DIREITO PARA FRENTE
    analogWrite(dirFrente,  velocidadeD);
    analogWrite(dirTras,    LOW);

    // MOTOR ESQUERDO PARA FRENTE
    analogWrite(esqFrente,  velocidadeE);
    analogWrite(esqTras,    LOW);
}

void andarTras(){
  // MOTOR DIREITO PARA TRAS
    analogWrite(dirFrente,  LOW);
    analogWrite(dirTras,    velocidadeE);

    // MOTOR ESQUERDO PARA TRAS
    analogWrite(esqFrente,  LOW);
    analogWrite(esqTras,    velocidadeD);
}

void virarDireita(){
  // MOTOR DIREITO PARA TRAS
    analogWrite(dirFrente,  LOW);
    analogWrite(dirTras,    velocidadeD);

    // MOTOR ESQUERDO PARA FRENTE
    analogWrite(esqFrente,  velocidadeE);
    analogWrite(esqTras,    LOW);
}

void virarEsquerda(){
  // MOTOR DIREITO PARA FRENTE
    analogWrite(dirFrente,  velocidadeD);
    analogWrite(dirTras,    LOW);

    // MOTOR ESQUERDO PARA TRAS
    analogWrite(esqFrente,  LOW);
    analogWrite(esqTras,    velocidadeE);
}

void parar(){
  digitalWrite(dirFrente, LOW);
  digitalWrite(dirTras,   LOW);
  digitalWrite(esqFrente, LOW);
  digitalWrite(esqTras,   LOW);
}


void loop() {
  ps2x.read_gamepad();

  if (ps2x.Button(PSB_PAD_UP)) {
    andarFrente();
  } else if (ps2x.Button(PSB_PAD_RIGHT)) {
    virarDireita();
  } else if (ps2x.Button(PSB_PAD_LEFT)) {
    virarEsquerda();
  } else if (ps2x.Button(PSB_PAD_DOWN)) {
    andarTras();
  } else {
    parar();
  }

  delay(50);
}



