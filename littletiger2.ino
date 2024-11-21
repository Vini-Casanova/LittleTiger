#define velmotor 3 // Analisar se necessário
#define N1 25
#define N2 26
#define N3 34
#define N4 35


void setup(){
    pinMode(N1, OUTPUT);
    pinMode(N2, OUTPUT);
    pinMode(N3, OUTPUT);
    pinMode(N4, OUTPUT);
    pinMode(velmotor,OUTPUT);

    digitalWrite(N1, LOW);
    digitalWrite(N2, LOW);
    digitalWrite(N3, LOW);
    digitalWrite(N4, LOW);
}

void loop(){
    velocidade = 255;


    digitalWrite(N2, LOW);
    digitalWrite(N1, HIGH);
}