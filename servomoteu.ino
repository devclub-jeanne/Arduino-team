const int pinMotor = 6;

void setup() {
  Serial.begin(9600);
  pinMode(pinMotor,OUTPUT);
}

void loop() {
  int Pot_val = analogRead(A3);
  analogWrite(pinMotor, Pot_val/4);
  delay(50);
}