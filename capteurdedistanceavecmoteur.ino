#include <Servo.h>

const int trigPin = 6; // Broche de déclenchement du capteur ultrason
const int echoPin = 7; // Broche d'écho du capteur ultrason
const int servoPin1 = 8; // Broche de contrôle du servomoteur
const int servoPin2 = 9; 

Servo monServo1; // Création d'une instance de la classe Servo
Servo monServo2;

void setup() {
  Serial.begin(9600); // Initialisation de la communication série
  monServo1.attach(servoPin1); // Attache du servomoteur à la broche de contrôle
  monServo2.attach(servoPin2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  monServo1.write(0);
}

void loop() {
  long duree, distance;

  // Envoi d'une impulsion ultrasonique
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mesure du temps de retour de l'écho
  duree = pulseIn(echoPin, HIGH);

  // Calcul de la distance en centimètres
  distance = duree * 0.034 / 2;

  // // Affichage de la distance mesurée dans le moniteur série
  // Serial.print("Distance: ");
  // Serial.print(distance);
  // Serial.println(" cm");

  // Vérification de la distance
  if (distance < 15) {
    // Si la distance est inférieure à 15 cm, actionner le servomoteur
    monServo1.write(90);
    monServo2.write(90); // Fait tourner le servomoteur de 45 degrés
    delay(500); // Attendre un court instant
    monServo1.write(0);
    monServo2.write(0); // Ramène le servomoteur à la position initiale (0 degré)
    delay(500);
  }

  delay(100); // Attendre une seconde entre chaque mesure
}