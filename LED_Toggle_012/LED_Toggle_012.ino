/**************************************************************************
  Title:       LED Toggle 012
  Date:        2014-08-11
  By:          April
  Edited by:   Michael
  
  Description: 
  Randoming of LEDs can be stopped by pressing the button connected to pin 2
  Toggle is used to change the modes og LEDs
*****************************************************************************/
#define prtln(x)  Serial.println(x)
#define prt(x)    Serial.print(x)
#define btnPin 2

#define keybounceDelayMs  25

#define LED_ON   LOW
#define LED_OFF  HIGH

#define BTN_ON   LOW
#define BTN_OFF  HIGH

// Variables used for Button Status
boolean buttonIsOn;      // button state

// Variables for LED Status
boolean ledStopped;   // states if the LEDs are Randoming(true) or Stopped(false)

// Variables used for Randoming
int last;     // last random number
int randNo;   // Number Randommed

//////////////////////////////////////////////////////////
// SETUP //
void setup() {
  int x;                      // used for setup for randoming
  
  Serial.begin(9600);         // set SerialMonitor at 9600baud
  
  for(x = 8; x <= 12; x++) {  // set the LEDs as OUTPUT and HIGH(LED_OFF)
    pinMode(x, OUTPUT);
    digitalWrite(x, LED_OFF);
  }
  
  pinMode(btnPin, INPUT);     // set button as INPUT
  
  last       = -1;            // no random number yet
  buttonIsOn = false;         // set button state to false
  ledStopped  = false;          // set ledStopped to true(randoming)
}


////////////////////////////////////////////////////////
// MAIN LOOP //
void loop() {  

  //** State: A
  
  //////// CHECLK BUTTON /////////
  if (((buttonIsOn == false) && (digitalRead(btnPin) == BTN_ON))   ||   // Button status changes temporarily
      ((buttonIsOn != false) && (digitalRead(btnPin) == BTN_OFF))) { 
    
       prt("1st buttonIsOn = ");
       prtln(buttonIsOn);
         
    //** State: A'    
    delay(keybounceDelayMs);                // Wait for a real button pressing
    
    //** State: Post-Delay
    if (((buttonIsOn == false) && (digitalRead(btnPin) == BTN_ON))   || // A real button presses action
        ((buttonIsOn != false) && (digitalRead(btnPin) == BTN_OFF))) { 
    
       prt("2nd buttonIsOn = ");
       prtln(buttonIsOn);
       
       buttonIsOn = ~buttonIsOn;                    //***** Change button Status
       
       
       /////// LED MODE CONTROL ////////
       if(buttonIsOn != false) {                    // if the button is really pressed
          ledStopped = ~ledStopped;
      
          prt("ledMode = ");       //to verify the ledStopped in SerialMonitor
          prtln(ledStopped);
          prtln("    ");
       }
    }
  }
  
       prt("====== button status = ");
       prtln(buttonIsOn);

  //** State: A
  
  //////// RANDOM /////////
  if(ledStopped == false) {
    digitalWrite(last, LED_OFF);  // turn the LED in 'Stopped' mode off
    
    do {                          // re-random if the random no. is same as the last random no.
      randNo = random(8, 13);
  
//      prt("last="); 
//      prtln(last);
//      prt("randNo=");
//      prtln(randNo);
  
  } while (randNo == last);

    digitalWrite(randNo, LED_ON);     // turn the LED on
    delay(30);
  
    digitalWrite(randNo, LED_OFF);    // turn the LED off
    delay(50);
  
    last = randNo;
 
//    prt("***** Set last=");
//    prtln(last);
//    prtln(" ");
  }
  
  ////// STOP /////////
  if(ledStopped != false) {
    digitalWrite(last, LED_ON);
  }
}
