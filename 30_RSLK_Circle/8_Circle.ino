#define LS 40 //Left motor speed - to provide speed for the motor
#define RS 39 //right motor speed - to provide speed for the motor
#define LD 30 //left motor direction
#define RD 29 //right motor direction

// if LD,RD = 0 then forward direction
// if LD,RD = 1 then backward direction

#define SLPR 11 // sleep pin 
#define SLPL 31  //sleep pin

char c;

void setup() 
{
  pinMode(LD, OUTPUT);
  pinMode(RD, OUTPUT);
  pinMode(SLPR , OUTPUT);
  pinMode(SLPL , OUTPUT);
  digitalWrite(SLPR, HIGH);
  digitalWrite(SLPL , HIGH);
}

void loop()
{
  digitalWrite(LD, LOW);
  digitalWrite(RD, LOW);
  analogWrite(LS, 25);
  analogWrite(RS, 20);
  delay(200);
  
//  digitalWrite(LD, LOW);
//  digitalWrite(RD, LOW);
//  analogWrite(LS, 35);
//  analogWrite(RS, );
//  delay(500);
}
