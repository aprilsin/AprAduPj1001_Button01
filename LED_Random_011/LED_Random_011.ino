/**************************************************************************
  Title: LED Random 011
  Date: 2014-08-11
  By; April
  
  Remarks: 
  Randoming of LEDs can be stopped by pressing the button connected to pin 2
*****************************************************************************/
#define prtln(x)  Serial.println(x)
#define prt(x)    Serial.print(x)


#define LED_ON   LOW
#define LED_OFF  HIGH

int last;     //last random number
int randNo;

void setup() {
  int x;  x = 100;
  
  Serial.begin(9600);
    
  for(x = 8; x <= 12; x++) {
    pinMode(x, OUTPUT);
    digitalWrite(x, HIGH);
  }
  
  last = 999;
}

void loop() {  
    do {                          //re-random if the random no. is same as the last random no.
      randNo = random(8, 13);
  
      prt("last="); 
      prtln(last);
      prt("randNo=");
      prtln(randNo);
  
  } while (randNo == last);

    digitalWrite(randNo, LED_ON);     //turn the LED on
    delay(300);
  
    digitalWrite(randNo, LED_OFF);    //turn the LED off
    delay(500);
  
    last = randNo;
 
    prt("***** Set last=");
    prtln(last);
    prtln(" ");
    
    delay(2000);
  }
  
