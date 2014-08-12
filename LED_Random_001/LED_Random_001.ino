/******************************
  Title: LED Random 001
  Date: 2014-08-07
  By; April
******************************/

int ledPattern[] = {B10000, B01000, B00100, B00010, B00001};

void setup() {
  for(int x = 8; x < 12; x++) {
    pinMode(x, OUTPUT);
  }
}

void loop() {
  int n = random(0,5);
  PORTB = ledPattern[n];
  delay(10);
}
  
