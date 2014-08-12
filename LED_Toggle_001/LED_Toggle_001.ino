/**************************************************************************
  Title: LED Random Ver 2.0
  Date: 2014-08-08
  By; April
  
  Description: 
  Randoming of LEDs can be stopped by pressing the button connected to pin 2
*****************************************************************************/
#define prt(x)  Serial.println(x)
#define btnPin 2

//Variables used for Button Status
boolean bState;   //button state

//Variables for LED Status
boolean ledMode = false;   //states if the LEDs are Randoming(true) or Stopped(false)

//Variables used for Randoming
int last;     //last random number
int randNo;   //Number Randommed

////////////////////////////////////////////////////////////

void checkBtn() {
  bState = digitalRead(btnPin);
  
  if(bState == LOW) {                      //check if pressed
    delay(100);
    bState = digitalRead(btnPin);
    
    if(bState == HIGH) {                   //check if released
      ledMode = ~ledMode;                        //compensate the mode of LEDs
    }
  }
}

////////////////////////////////////////////////////////////
 
void ledRandom() {                          //function for Randoming the LEDs  
    do {                      //re-random if the random no. is same as the last random no.
      randNo = random(8, 13);
      Serial.print("last="); 
      Serial.println(last);
      Serial.print("randNo=");
      Serial.println(randNo);
    
    } while (randNo == last);

    last = randNo;
 
    Serial.print("***** Set last=");
    Serial.println(last);
  
    digitalWrite(randNo, LOW); //turn the LED on
    delay(30);
  
    digitalWrite(randNo, HIGH);//turn the LED off
    delay(50);
  
    Serial.println(" ");
}

////////////////////////////////////////////////////////////

void ledStop() {                            //function for Stoping the LEDs
  digitalWrite(last, HIGH);
}

//////////////////////////////////////////////////////////
//SETUP
void setup() {
  int x;  x = 100;            //setup for randoming
  
  Serial.begin(115200);
  
  for(x = 0; x <= 12; x++) {
    pinMode(x, OUTPUT);
    digitalWrite(x, HIGH);
  }
  
  last = 999;
  
  bState = 0;                 //setup for button
  pinMode(btnPin, INPUT);
}

////////////////////////////////////////////////////////
//MAIN LOOP
void loop() {  
  checkBtn;
  
  if(ledMode == false) {
    ledRandom;
    ledMode = true;
  }
  
  else {
    ledStop;
    ledMode = false;
  }
}
