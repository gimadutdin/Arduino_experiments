//this sketch processes button pressing, also fixes contact bounce
byte button = 2, yellow = 11, blue = 12, yellow_flag = 0, blue_flag = 1, press_flag = 0;
unsigned long last_press = 0;//if you write byte or int it will not work good due to overflow

void setup() {
  pinMode(button, INPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  write_leds();
}

void swap_leds()
{
  yellow_flag = !yellow_flag;
  blue_flag = !blue_flag;
}

void write_leds()
{
  digitalWrite(yellow, yellow_flag);
  digitalWrite(blue, blue_flag);
}

void loop() {
  if (digitalRead(button) == HIGH && millis() - last_press > 200)
  {
    swap_leds();
    write_leds();
    last_press = millis();
  }
}
