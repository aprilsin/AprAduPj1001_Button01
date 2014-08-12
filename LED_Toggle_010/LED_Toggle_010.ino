/**************************************************************************
  Title: LED Toggle 003
  Date: 2014-08-11
  By: April
  
  Description: 
  Randoming of LEDs can be stopped by pressing the button connected to pin 2
  Toggle is used to change the modes og LEDs
*****************************************************************************/
#define prtln(x)  Serial.println(x)
#define prt(x)    Serial.print(x)
#define btnPin 2

#define LED_ON   LOW
#define LED_OFF  HIGH

#define BTN_ON   LOW
#define BTN_OFF  HIGH

//Variables used for Button Status
boolean buttonIsOn;   // button state

//Variables for LED Status
boolean ledRandom;   //states if the LEDs are Randoming(true) or Stopped(false)

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
  
  last       = -1;            // No random number yet
  buttonIsOn = false;         // set button state to false
  ledRandom  = true;        // set ledRandom to true(randoming)
}

////////////////////////////////////////////////////////
//MAIN LOOP
void loop() {  

  //////// CHECLK BUTTON /////////
  if (digitalRead(btnPin) == BTN_ON) buttonIsOn = true;
  else buttonIsOn = false;
  
  if (buttonIsOn == false) {                // check if the button is off-ed
  
    delay(25);                           // Wait for key-bounce
    
    if (digitalRead(btnPin) == BTN_ON) buttonIsOn = true;
    else buttonIsOn = false;
  
    if(buttonIsOn == true) {               //check if the button is pressed
      ledRandom = ~ledRandom;
      prtln(ledRandom);       //to verify the ledRandom in SerialMonitor
    }
  }

  //////// RANDOM /////////
  if(ledRandom == true) {
    do {                          //re-random if the random no. is same as the last random no.
      randNo = random(8, 13);
  
      prt("last="); 
      prtln(last);
      prt("randNo=");
      prtln(randNo);
  
  } while (randNo == last);

    digitalWrite(randNo, LED_ON);     //turn the LED on
    delay(30);
  
    digitalWrite(randNo, LED_OFF);    //turn the LED off
    delay(50);
  
    last = randNo;
 
    prt("***** Set last=");
    prtln(last);
    prtln(" ");
  }
  
  ////// STOP /////////
  else {
    digitalWrite(last, LED_ON);
  }
  
  delay(500);
}
