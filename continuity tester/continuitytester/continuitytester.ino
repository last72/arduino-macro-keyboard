const int BUTTON = 2;
int BUTTONstate = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  Serial.println(digitalRead(BUTTON));
  BUTTONstate = digitalRead(BUTTON);
  if (BUTTONstate == HIGH)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  } 
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}
