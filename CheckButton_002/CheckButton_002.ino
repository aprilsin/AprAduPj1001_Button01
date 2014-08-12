/***************************************************
  Title: Check Button 002
  Date: 2014-08-07
  By: April
  
  Description: 
  Toggle between mode1(ledRandom) & mode2(ledStop)
*****************************************************/
boolean ledMode = 0;
boolean bState;

#define btnPin 2

#define ON   LOW
#define OFF  HIGH

void setup() {
  Serial.begin(9600);
  
  pinMode(btnPin, INPUT);
}

void loop() {
  bState = digitalRead(btnPin);
  
  if(bState == OFF) {
    delay(30);
    bState = digitalRead(btnPin);
  
    if(bState == ON) {
      ledMode = ~ledMode;
      Serial.println(ledMode);
    }
  }
  delay(30);
}
