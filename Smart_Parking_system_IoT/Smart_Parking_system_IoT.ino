int motor_flag =0;
int i=0;
void servo_motor()
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
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(31,OUTPUT);
}

void loop() 
{
  if(Serial1.available())
  {
    char data=Serial1.read();
    Serial.print(data); 
    motor_flag+=1;
  }
  else if(motor_flag>10)
  {
    servo_motor();
    motor_flag=0;
  }
}
