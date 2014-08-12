/******************************
  Title: LED Button Control Ver 1
  Date: 2014-08-07
  By; April & Aaron
******************************/

#define buttonPin 2

byte x = B00001;
byte shift = 0;
byte limit = 5;

int ledPattern[] = {B10000, B01000, B00100, B00010, B00001};

int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  DDRB = B11111;    //set PortB(pin 8-12) to OUTPUT
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    PORTB = x << shift;
    shift ++;
  
    if (shift == limit) {
      shift = 0;
    }
    delay(100);
  }
 
  if (buttonState == LOW) { 
    int n = random(0,5);
    PORTB = ledPattern[n];
    delay(100);
  }
}

