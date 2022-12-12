#include <LiquidCrystal.h>
#define RS 2
#define EN 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7); 
void setup()
{

  lcd.begin(16, 2);

}

void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  lcd.setCursor(0, 1);
  lcd.print("hello, world!");

}
