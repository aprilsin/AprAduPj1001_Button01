/******************************
  Title: LED Random 003
  Date: 2014-08-07
  By; April
******************************/
#define prt(x)  Serial.println(x)

int x;
int randNo;
int randLast = 0;

void setup() {
  x =100;
  
  Serial.begin(115200);
    
  for(x = 8; x <= 12; x++) {
    pinMode(x, OUTPUT);
    digitalWrite(x, HIGH);
  }
  
}

void loop() {
  randNo = random(8, 13);
  if (randLast == randNo) {
    random(8,13);

    if(randLast != randNo) {
      digitalWrite(randNo, LOW);
      delay(300);
  
      digitalWrite(randNo, HIGH);
      delay(500);
    }
  }
  randLast = randNo;
}
  
