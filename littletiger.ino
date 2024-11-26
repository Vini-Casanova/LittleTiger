
#define dirFrente 25 
#define dirTras   26

#define esqFrente 32
#define esqTras   33

#define pinDigital //26 Preciso trocar 
#define pinAnalogico 36

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

int valorDigital;
int valorAnalogico;

void setup() {
  Serial.begin(115200);


  Serial.begin(115200);
  pinMode(pinDigital, INPUT);
  pinMode(pinAnalogico, INPUT);

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

    digitalWrite(dirFrente, HIGH);
    digitalWrite(dirTras, LOW);

    // MOTOR ESQUERDO PARA FRENTE

    digitalWrite(esqFrente, HIGH);
    digitalWrite(esqTras, LOW);
}

void andarTras(){
  // MOTOR DIREITO PARA TRAS
    parar();
    delay(50);

    digitalWrite(dirFrente, LOW);
    digitalWrite(dirTras, HIGH);

    // MOTOR ESQUERDO PARA TRAS

    digitalWrite(esqFrente, LOW);
    digitalWrite(esqTras, HIGH);
}

void virarDireita(){
  // MOTOR DIREITO PARA TRAS

    digitalWrite(dirFrente, HIGH);
    digitalWrite(dirTras, LOW);

    // MOTOR ESQUERDO PARA FRENTE
    digitalWrite(esqFrente, LOW);
    digitalWrite(esqTras, LOW);
}

void virarEsquerda(){
  // MOTOR DIREITO PARA FRENTE

    digitalWrite(dirFrente, LOW);
    digitalWrite(dirTras, LOW);

    // MOTOR ESQUERDO PARA TRAS

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

    valorDigital = digitalRead(pinDigital);
  valorAnalogico = analogRead(pinAnalogico);
  Serial.print("Leitura Digital: ");
  Serial.println(valorDigital);
  Serial.print("Leitura Analogica: ");
  Serial.println(valorAnalogico);
  Serial.println();
  //delay(500);

  delay(50);
}
