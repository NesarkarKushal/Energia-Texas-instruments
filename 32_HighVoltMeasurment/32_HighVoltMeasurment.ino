void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A1,INPUT);
}

void loop() 
{
  int data;
  // put your main code here, to run repeatedly: 
  data=analogRead(A1);
  Serial.println(data);
  delay(100);
}
