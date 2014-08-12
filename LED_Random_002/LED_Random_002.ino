/******************************
  Title: LED Random 002
  Date: 2014-08-07
  By; April
******************************/
#define prt(x)  Serial.println(x)

int x;

void setup() {
    
    x = 100;
  
    Serial.begin(115200);
    
    for(int x = 8; x <= 12; x++) {
    pinMode(x, OUTPUT);
    prt((long int)&x);
    prt(x);
  }
  prt((long int)&x);
  prt(x);
  
}

void loop() {
  int n = random(8, 13);
  digitalWrite(n, HIGH);
  delay(30);
  digitalWrite(n, LOW);
  delay(50);
}
  
