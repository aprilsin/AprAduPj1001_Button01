/***************************
 Title: LED Shifting
 Date: 2014-08-07
 By: Aaron
****************************/

byte x = B00001;
byte shift = 0;
byte limit = 5;

void setup()
{
    DDRB = B11111;
}

void loop()
{
  PORTB = x << shift;
  shift ++;
  if (shift == limit)
  {
    shift = 0;
  }
  delay(100);
}
    
