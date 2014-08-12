/**************************************************************************
  Title: LED Toggle 002
  Date: 2014-08-09
  By: April
  
  Description: 
  Randoming of LEDs can be stopped by pressing the button connected to pin 2
  Toggle is used to change the modes og LEDs
  
  Remarks:
  Edited by Michael
*****************************************************************************/
#define prt(x)  Serial.println(x)
#define btnPin 2

#define LED_ON   LOW
#define LED_OFF  HIGH

#define BTN_ON   LOW
#define BTN_OFF  HIGH

//Variables used for Button Status
boolean buttonIsOn;   // button state

//Variables for LED Status
boolean ledMode = true;   //states if the LEDs are Randoming(true) or Stopped(false)

//Variables used for Randoming
int last;     // last random number
int randNo;   // Number Randommed

//////////////////////////////////////////////////////////
//SETUP
void setup() {
  int x;                      // used for setup for randoming
  
  Serial.begin(9600);         // set SerialMonitor at 9600baud
  
  for(x = 8; x <= 12; x++) {  // set the LEDs as OUTPUT and HIGH(LED_OFF)
    pinMode(x, OUTPUT);
    digitalWrite(x, LED_OFF);
  }
  
  pinMode(btnPin, INPUT);     // set button as INPUT
  
  last   = -1;                // No random number yet
  buttonIsOn = false;             // set button state to false
}

////////////////////////////////////////////////////////
//MAIN LOOP
void loop() {  

  //////// CHECLK BUTTON /////////
  // buttonIsOn = digitalRead(btnPin);      // Get button status ????
  
  if (digitalRead(btnPin) == BTN_ON) buttonIsOn = true;
  else buttonIsOn = false;
  
  if (buttonIsOn == false) {                // check if the button is off-ed
  
    delay(25);                           // Wait for key-bounce
    
    buttonIsOn = digitalRead(btnPin);
  
    if(buttonIsOn == BTN_ON) {               //check if the button is pressed
      ledMode = ~ledMode;
      Serial.println(ledMode);       //to verify the ledMode in SerialMonitor
    }
  }

  //////// RANDOM /////////
  if(ledMode == true) {
      do {                          //re-random if the random no. is same as the last random no.
      randNo = random(8, 13);
//      Serial.print("last="); 
//      Serial.println(last);
//      Serial.print("randNo=");
//      Serial.println(randNo);
    
    } while (randNo == last);

    last = randNo;
 
//    Serial.print("***** Set last=");
//    Serial.println(last);
  
    digitalWrite(randNo, LOW);     //turn the LED on
    delay(30);
  
    digitalWrite(randNo, HIGH);    //turn the LED off
    delay(50);
  
//    Serial.println(" ");
}
  
  ////// STOP /////////
  else {
    digitalWrite(last, HIGH);
  }
  
  delay(30);
}
