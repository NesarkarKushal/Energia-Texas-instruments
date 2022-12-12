void setup()
{  pinMode(RED_LED,OUTPUT);
  pinMode(PUSH1,INPUT_PULLUP);
}
void loop() 
{
  if(digitalRead(PUSH1))
  {
  digitalWrite(RED_LED,HIGH);
  delay(1000);}
  else
  {  digitalWrite(RED_LED,LOW);
  delay(1000);
  }
}
