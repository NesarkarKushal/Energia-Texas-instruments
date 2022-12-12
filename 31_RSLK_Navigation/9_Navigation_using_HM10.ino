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
  Serial1.begin(9600);
}

void loop()
{
  char data;
  if (Serial1.available())
  {
    data = Serial1.read();
  }
  switch (data)
  {
    case 'f' : digitalWrite(LD, LOW);  // Forward
      digitalWrite(RD, LOW);
      analogWrite(LS, 30);
      analogWrite(RS, 30);
      delay(3000);
      break;
      
    case 'b' : digitalWrite(LD, HIGH); // Backward
      digitalWrite(RD, HIGH);
      analogWrite(LS, 30);
      analogWrite(RS, 30);
      delay(3000);
      break;
      
    case 'r' : digitalWrite(LD, LOW); // Right
      digitalWrite(RD, LOW);
      analogWrite(LS, 30);
      analogWrite(RS, 0);
      delay(1500);
      break;
      
    case 'l' : digitalWrite(LD, LOW); //Left
      digitalWrite(RD, LOW);
      analogWrite(LS, 0);
      analogWrite(RS, 30);
      delay(1500);
      break;

    case 'q' : digitalWrite(LD, HIGH); // Backward Left
      digitalWrite(RD, HIGH);
      analogWrite(LS, 0);
      analogWrite(RS, 30);
      delay(1500);
      break;
      
    case 'w' : digitalWrite(LD, HIGH); // Backward Right
      digitalWrite(RD, HIGH);
      analogWrite(LS, 30);
      analogWrite(RS, 0);
      delay(1500);
      break;
      
    default:  digitalWrite(LD, LOW); // Stop
      digitalWrite(RD, LOW);
      analogWrite(LS, 0);
      analogWrite(RS, 0);
      delay(1000);
      break;
  }
}
