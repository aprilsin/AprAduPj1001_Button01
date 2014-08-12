/**************************************************************************
  Title: LED Random Ver 1.0
  Date: 2014-08-08
  By; April
  
  Remarks: 
  Randoming of LEDs can be stopped by pressing the button connected to pin 2
*****************************************************************************/
#define prt(x)  Serial.println(x)

int last;     //last random number
int bState;   //button state

void setup() {
  int x;  x = 100;
  
  bState = 0;
  
  Serial.begin(115200);
    
  for(x = 8; x <= 12; x++) {
    pinMode(x, OUTPUT);
    digitalWrite(x, HIGH);
  }
  
  last = 999;
}

void loop() {  
  int n;
  
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
  delay(300);
  
  digitalWrite(n, HIGH);
  delay(500);
  
  Serial.println(" ");
}
