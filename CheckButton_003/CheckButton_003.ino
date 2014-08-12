/***************************************************
  Title: Check Button 003
  Date: 2014-08-11
  By: April
  
  Description: 
  Toggle between mode1(ledRandom) & mode2(ledStop)
*****************************************************/
boolean ledMode = false;
boolean buttonIsOn = false;

#define prtln(x)  Serial.println(x)
#define prt(x)    Serial.print(x)
#define btnPin 2

#define BTN_ON   LOW
#define BTN_OFF  HIGH

void setup() {
  Serial.begin(9600);
  
  pinMode(btnPin, INPUT);
}

void loop() {
  if (digitalRead(btnPin) == BTN_ON) buttonIsOn = true;
  else buttonIsOn = false;
  
  if (buttonIsOn == false) {                // check if the button is off-ed
  
    delay(25);                           // Wait for key-bounce
    
    if (digitalRead(btnPin) == BTN_ON) buttonIsOn = true;
    else buttonIsOn = false;
  
    if(buttonIsOn == true) {               //check if the button is pressed
      ledMode = ~ledMode;
      prtln(ledMode);       //to verify the ledMode in SerialMonitor
    }
  }
}
