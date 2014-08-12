/**************************************************************************
  Title: LED Random 010
  Date: 2014-08-08
  By; April
  
  Remarks: 
  Randoming of LEDs can be stopped by pressing the button connected to pin 2
  
  Comment:
  ^-^ finally worked!!!!!
*****************************************************************************/
#define prt(x)  Serial.println(x)
#define buttonPin 2

int last;     //last random number
int bState;   //button state

void setup() {
  int x;  x = 100;            //setup for randoming
  
  Serial.begin(115200);
    
  for(x = 8; x <= 12; x++) {
    pinMode(x, OUTPUT);
    digitalWrite(x, HIGH);
  }
  
  last = 999;
  
  bState = 0;                 //setup for button
  pinMode(buttonPin, INPUT);
}

void loop() {  
  int n;
  
  bState = digitalRead(buttonPin);
  
  if(bState == HIGH) {
    do {
      n = random(8, 13);
      Serial.print("last="); 
      Serial.println(last);
      Serial.print("n=");
      Serial.println(n);
    
    } while (n == last);

    last = n;
 
    Serial.print("***** Set last=");
    Serial.println(last);
  
    digitalWrite(n, LOW);
    delay(30);
  
    digitalWrite(n, HIGH);
    delay(50);
  
    Serial.println(" ");
  }
  
  if(bState == LOW) {
    int x;  x = 100;
    
    for(x = 8; x <= 12; x++) {
      pinMode(x, OUTPUT);
      digitalWrite(x, HIGH);
    }
  }
}
