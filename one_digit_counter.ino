byte digits[10] = {B11011110, B00000110, B11101100, B10101110, B00110110, B10111010, B11111010, B00001110, B11111110, B10111110};

//7segment indicator with common anode
//connected with 4-11 pins of arduino and 5V pin (to common anode)
//4-11 pins are connected to indicator's pins through 220 ohm resistors
//tested on BL-S56B-11UR-10 - works good
void setup() {
  for (byte i = 4; i <= 11; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
}

void writeDigit(byte x)
{
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead(digits[x], i) == 1)
    {
      digitalWrite(i + 4, LOW);
    } else
    {
      digitalWrite(i + 4, HIGH);
    }
  }
}

void loop() {  
  delay(200);
  for (byte i = 0; i <= 9; i++)
  {
    writeDigit(i);
    delay(1000);
  }
}
