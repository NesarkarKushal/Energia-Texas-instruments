#define LS 40 //Left motor speed - to provide speed for the motor
#define RS 39 //right motor speed - to provide speed for the motor
#define LD 30 //left motor direction
#define RD 29 //right motor direction

// if LD,RD = 0 then forward direction
// if LD,RD = 1 then backward direction

#define SLPR 11 // sleep pin 
#define SLPL 31  //sleep pin

char c;

void setup() {
  // put your setup code here, to run once:
    pinMode(LD, OUTPUT);
    pinMode(RD, OUTPUT);
    pinMode(SLPR , OUTPUT);
    pinMode(SLPL , OUTPUT);
    digitalWrite(SLPR, HIGH);
    digitalWrite(SLPL , HIGH);
}

void loop() 
{
  // put your main code here, to run repeatedly: 
      digitalWrite(LD,LOW);
      digitalWrite(RD,LOW);
       analogWrite(LS,20);
       analogWrite(RS,20);                    
  }
  // FORWARD F
  //backward B
  //Left L
  //Right R


  
