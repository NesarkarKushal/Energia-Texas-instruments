/*    Connections
 *     ADC pin INPUT = 1.8v
 *    Pot Input ----- 1k Reg ------Microcontroller ADC Pin------1k Reg ------- GND
 *    
 *    
 */


int i=0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly: 
  i=analogRead(2);
  Serial.println(i);
  delay(1000);
}
