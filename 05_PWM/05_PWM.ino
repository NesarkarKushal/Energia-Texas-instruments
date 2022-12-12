int i=0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(RED_LED,OUTPUT);
}
void loop() 
{
  // put your main code here, to run repeatedly: 
  for(i=0;i<255;i+=50)
  {
    analogWrite(RED_LED,i);
    delay(500);
  }
    for(i=255;i>0;i-=50)
  {
    analogWrite(RED_LED,i);
    delay(500);
  }
}
