/***************************************************
  Title: Check Button 001
  Date: 2014-08-07
  By: April
  
  Description: 
  Toggle between mode1(ledRandom) & mode2(ledStop)
*****************************************************/
boolean ledMode;
boolean bState;

#define btnPin 2

void checkBtn() {
  bState = digitalRead(btnPin);
  
  if(bState == HIGH) {
    delay(100);
    bState = digitalRead(btnPin);
    
    if(bState == LOW) {
      ledMode = ~ledMode;                        //compensate the mode of LEDs
    }
  }
}

void setup() {
  Serial.begin(9600);
  
  digitalWrite(btnPin, INPUT);
}

void loop() {
  bState = digitalRead(btnPin);
  Serial.print("bState1  ");
  Serial.print(bState);
  Serial.println("off");
  
  if(bState == LOW) {
    delay(100);
    bState = digitalRead(btnPin);
  
    Serial.print("bState2  ");
    Serial.print(bState);
    Serial.println("on");
  
    if(bState == HIGH) {
      ledMode = ~ledMode;                        //compensate the mode of LEDs
    }
  }
  
  Serial.print("******mode      ");
  Serial.println(ledMode);
    
  Serial.println("    ");
  
  delay(2000);
}
