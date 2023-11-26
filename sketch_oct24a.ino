#include<Stepper.h>

const int nbPas = 2048;

int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;

Stepper myStepper(nbPas, in1, in2, in3, in4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(nbPas);
  delay(10);
  myStepper.step(-nbPas);
  delay(10);
}
