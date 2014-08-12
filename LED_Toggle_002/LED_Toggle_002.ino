/**************************************************************************
  Title: LED Toggle 002
  Date: 2014-08-09
  By; April
  
  Description: 
  Randoming of LEDs can be stopped by pressing the button connected to pin 2
  Toggle is used to change the modes og LEDs
*****************************************************************************/
#define prt(x)  Serial.println(x)
#define btnPin 2

#define ON   LOW
#define OFF  HIGH

//Variables used for Button Status
boolean bState;   //button state

//Variables for LED Status
boolean ledMode = true;   //states if the LEDs are Randoming(true) or Stopped(false)

//Variables used for Randoming
int last;     //last random number
int randNo;   //Number Randommed

////////////////////////////////////////////////////////////

void checkBtn() {
  bState = digitalRead(btnPin);
  
  if(bState == OFF) {                //check if the button is off-ed
    delay(25);
    bState = digitalRead(btnPin);
  
    if(bState == ON) {               //check if the button is pressed
      ledMode = ~ledMode;
      Serial.println(ledMode);       //to verify the ledMode in SerialMonitor
    }
  }
  delay(20);
}

////////////////////////////////////////////////////////////
 
void ledRandom() {                //function for Randoming the LEDs  
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

////////////////////////////////////////////////////////////

void ledStop() {              //function for Stoping the LEDs
  digitalWrite(last, HIGH);
}

//////////////////////////////////////////////////////////
//SETUP
void setup() {
  int x;            //setup for randoming
  
  Serial.begin(9600);         //set SerialMonitor at 9600baud
  
  for(x = 0; x <= 12; x++) {  //set the LEDs as OUTPUT and HIGH(ON)
    pinMode(x, OUTPUT);
    digitalWrite(x, HIGH);
  }
  
  last = 999;
  
  bState = 0;                 //setup for button
  pinMode(btnPin, INPUT);     //set button as INPUT
}

////////////////////////////////////////////////////////
//MAIN LOOP
void loop() {  
  checkBtn;
  
  if(ledMode == true) {
    ledRandom;
  }
  
  else {
    ledStop;
  }
  delay(30);
}
