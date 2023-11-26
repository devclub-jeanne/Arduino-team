#include <Servo.h>

const int buttonPin = 2;  // Broche du bouton
const int servoPin = 9;   // Broche du servomoteur

Servo myServo;  // Crée un objet Servo

void setup() {
  pinMode(buttonPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    // Appuyez sur le bouton pour faire tourner le servomoteur de 90 degrés
    myServo.write(90);
    delay(1000);  // Attendez 1 seconde pour éviter un mouvement continu
  }
}
