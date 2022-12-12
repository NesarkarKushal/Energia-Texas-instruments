#define orange 35
#define pink 36
#define yellow 37
#define blue 38

void Delay()
{
  delay(1);

}
void Step1()
{
   digitalWrite(orange,LOW);
   digitalWrite(pink,HIGH);
   digitalWrite(yellow,HIGH);
   digitalWrite(blue,HIGH);
}
void Step2()
{
     digitalWrite(orange,LOW);
   digitalWrite(pink,HIGH);
   digitalWrite(yellow,LOW);
   digitalWrite(blue,HIGH);
}
void Step3()
{
     digitalWrite(orange,HIGH);
   digitalWrite(pink,HIGH);
   digitalWrite(yellow,LOW);
   digitalWrite(blue,HIGH);
}
void Step4()
{
   digitalWrite(orange,HIGH);
   digitalWrite(pink,LOW);
   digitalWrite(yellow,LOW);
   digitalWrite(blue,HIGH);
}
void Step5()
{
     digitalWrite(orange,HIGH);
   digitalWrite(pink,LOW);
   digitalWrite(yellow,HIGH);
   digitalWrite(blue,HIGH);
}
void Step6()
{
     digitalWrite(orange,HIGH);
   digitalWrite(pink,LOW);
   digitalWrite(yellow,HIGH);
   digitalWrite(blue,LOW);
}
void Step7()
{
   digitalWrite(orange,HIGH);
   digitalWrite(pink,HIGH);
   digitalWrite(yellow,HIGH);
   digitalWrite(blue,LOW);
}
void Step8()
{
   digitalWrite(orange,LOW);
   digitalWrite(pink,HIGH);
   digitalWrite(yellow,HIGH);
   digitalWrite(blue,LOW);
}
void setup() 
{
  // put your setup code here, to run once:
  pinMode(orange,OUTPUT);
  pinMode(pink,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(blue,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly: 
  Step1();
        Delay();
        Step2();
        Delay();
        Step3();
        Delay();
        Step4();
        Delay();
        Step5();
        Delay();
        Step6();
        Delay();
        Step7();
        Delay();
        Step8();
        Delay();
}
