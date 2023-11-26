void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  int a;
  int b;
  a = digitalRead(2);
  b = 1;

  if(a == b){
    digitalWrite(13, LOW);
  }
  else digitalWrite(13, HIGH);
}