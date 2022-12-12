
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPLdo7sm4WK"
#define BLYNK_DEVICE_NAME "KSRM"
//#define BLYNK_AUTH_TOKEN "z3H0SIVa2fRdgQaNIDDnvX9HID5D3h49"

#include <SPI.h>
#include <WiFi.h>
#include "BlynkSimpleEnergiaWiFi.h"

#include <LiquidCrystal.h>
#define RS 2
#define EN 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "z3H0SIVa2fRdgQaNIDDnvX9HID5D3h49";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "EDGATE TECH";
char pass[] = "00936903";
int motor_flag = 0;
int i = 0;
int a = 0;
int b = 0;
int c = 0;
void servo_motor()
{
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Entry Gate:Open");
  for (i = 0; i < 150; i++)
  {
    analogWrite(31, i);
    delay(100);
    i = i + 20;
  }
  delay(2000);
  for (i = 150; i > 0; i--)
  {
    analogWrite(31, i);
    delay(100);
    i = i - 20;
  }
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Etry Gate:Closed");
  delay(2000);
}
void setup()
{
  // Debug console
  Serial.begin(9600);
  Serial1.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print("Welcome Cars");
  pinMode(31, OUTPUT);
  pinMode(28, INPUT);
  pinMode(30, INPUT);
  //  pinMode(5, INPUT);

  Blynk.begin(auth, ssid, pass);
}


void loop()
{
  lcd.clear();
  //  lcd.setCursor(0, 1);
  //  lcd.print("Welcome");
  if (Serial1.available())
  {
    char data = Serial1.read();
    Serial.print(data);
    motor_flag += 1;
  }
  else if (motor_flag > 10)
  {
    servo_motor();
    motor_flag = 0;
  }
  a = digitalRead(28);
  b = digitalRead(30);
  if (a == 1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Slot 1 is full");
    if (b == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No space to park");
    }
  }
  else if (b == 1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Slot 2 is full");
    if (a == 1)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No space to park");
    }
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("All Slot r Empty");
  }
  Blynk.virtualWrite(V0, a);
  Blynk.virtualWrite(V1, b);
  //  Blynk.virtualWrite(V2, c);

  Blynk.run();
}
