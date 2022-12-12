char data;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly: 
  if(Serial1.available())
  {
    data=Serial1.read();
    Serial.print(data);
    delay(500);
  }
}
