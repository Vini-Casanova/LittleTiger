
#define dirFrente 25 
#define dirTras   26

#define esqFrente 32
#define esqTras   33

#define FRENTE 1
#define PARADO 0
#define TRAS  -1

#define velocidadeE 100
#define velocidadeD 110

#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif
BluetoothSerial SerialBT;
char ch;
//
//PS2X ps2x;
//
//void configuraControle() {
//  int erroControle = ps2x.config_gamepad(13, 11, 10, 12, true, true);
//  if (!erroControle) {
//    Serial.println("Controle encontrado");
//  } else {
//    Serial.println("Controle não encontrado");
//    while (erroControle) {
//      if (bitRead(millis(), 11)) erroControle = ps2x.config_gamepad(13, 11, 10, 12, true, true);
//    }
//  }
//}

void setup() {
  Serial.begin(115200);

  //configuraControle();

  SerialBT.begin("LITTLE TIGER"); //Bluetooth device name
  Serial.println("O dispositivo foi iniciado, agora você pode parar!");

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
//    analogWrite(dirFrente,  velocidadeD);
//    analogWrite(dirTras,    LOW);

    digitalWrite(dirFrente, HIGH);
    digitalWrite(dirTras, LOW);

    // MOTOR ESQUERDO PARA FRENTE
//    analogWrite(esqFrente,  velocidadeE);
//    analogWrite(esqTras,    LOW);

    digitalWrite(esqFrente, HIGH);
    digitalWrite(esqTras, LOW);
}

void andarTras(){
  // MOTOR DIREITO PARA TRAS
//    analogWrite(dirFrente,  LOW);
//    analogWrite(dirTras,    velocidadeE);

    parar();
    delay(50);

    digitalWrite(dirFrente, LOW);
    digitalWrite(dirTras, HIGH);

    // MOTOR ESQUERDO PARA TRAS
//    analogWrite(esqFrente,  LOW);
//    analogWrite(esqTras,    velocidadeD);

    digitalWrite(esqFrente, LOW);
    digitalWrite(esqTras, HIGH);
}

void virarDireita(){
  // MOTOR DIREITO PARA TRAS
//    analogWrite(dirFrente,  LOW);
//    analogWrite(dirTras,    velocidadeD);

    digitalWrite(dirFrente, HIGH);
    digitalWrite(dirTras, LOW);

    // MOTOR ESQUERDO PARA FRENTE
//    analogWrite(esqFrente,  velocidadeE);
//    analogWrite(esqTras,    LOW);

    digitalWrite(esqFrente, LOW);
    digitalWrite(esqTras, LOW);
}

void virarEsquerda(){
  // MOTOR DIREITO PARA FRENTE
//    analogWrite(dirFrente,  velocidadeD);
//    analogWrite(dirTras,    LOW);

    digitalWrite(dirFrente, LOW);
    digitalWrite(dirTras, LOW);

    // MOTOR ESQUERDO PARA TRAS
//    analogWrite(esqFrente,  LOW);
//    analogWrite(esqTras,    velocidadeE);

    digitalWrite(esqFrente, HIGH);
    digitalWrite(esqTras, LOW);
}

void parar(){
  digitalWrite(dirFrente, LOW);
  digitalWrite(dirTras,   LOW);
  digitalWrite(esqFrente, LOW);
  digitalWrite(esqTras,   LOW);
}


void loop() {
    if (Serial.available()) {
       SerialBT.write(Serial.read());    }
    if (SerialBT.available()) {
    ch = SerialBT.read();
    if (ch == 'A')  {andarFrente();}
    if (ch == 'V')  {andarTras();}
    if (ch == 'P')  {parar();}
    if (ch == 'D')  {virarDireita();}
    if (ch == 'E')  {virarEsquerda();}
    }
//  ps2x.read_gamepad();
//
//  if (ps2x.Button(PSB_PAD_UP)) {
//    andarFrente();
//  } else if (ps2x.Button(PSB_PAD_RIGHT)) {
//    virarDireita();
//  } else if (ps2x.Button(PSB_PAD_LEFT)) {
//    virarEsquerda();
//  } else if (ps2x.Button(PSB_PAD_DOWN)) {
//    andarTras();
//  } else {
//    parar();
//  }

  delay(50);
}
