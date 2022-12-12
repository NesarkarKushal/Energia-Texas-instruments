int a=0;
int b=0;
int c=0;
int d=0;
void sloat_1()
{
  digitalWrite(23,HIGH);
}
void sloat_2()
{
    digitalWrite(24,HIGH);

}
void sloat_3()
{
  digitalWrite(25,HIGH);

}
void sloat_4()
{
  digitalWrite(26,HIGH);

}
void setup()
{
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);

  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  a=digitalRead(3);
  b=digitalRead(4);
  c=digitalRead(5);
  d=digitalRead(6);
  delay(500);
  if(a==1)
  sloat_1();
   else if(b==1)
  sloat_2();
  else if(c==1)
  sloat_3();
  else if(d==1)
  sloat_4();
  else
  {
      digitalWrite(23,LOW);
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      digitalWrite(26,LOW);
  }
}
