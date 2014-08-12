/******************************
  Title: LED Button Control Ver 2
  Date: 2014-08-07
  By; April & Aaron
******************************/

#define buttonPin 2

byte x = B00001;
byte shift;
byte limit = 5;

int n;
int a;
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
 
  for(a = 8; a <= 12; a++) {
    pinMode(x, OUTPUT);
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    
    for(shift = 0; shift < limit; shift++) {
      PORTB = x << shift;
      delay(10);
      PORTB = 0;
      delay(10);
    }
  
    if (shift == limit) {
      shift = 0;
    }
   delay(100);
  }
 
  if (buttonState == LOW) { 
    n = random(8, 13);
    
    digitalWrite(n, HIGH);
    delay(30);
    digitalWrite(n, LOW);
    delay(50);
  }
}

