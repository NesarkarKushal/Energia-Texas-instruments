int motor_flag =0;
int i=0;
void setup()
{
  pinMode(31,OUTPUT);
}

void loop() 
{
  for(i=0;i<150;i++)
  {
      analogWrite(31,i);
      delay(100); 
      i=i+20;
  }
  delay(2000);
  for(i=150;i>0;i--)
  {
      analogWrite(31,i);
      delay(100); 
      i=i-20;
  }
}
