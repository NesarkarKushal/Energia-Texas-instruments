/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use Energia with WiFi
  to connect your project to Blynk. Tested with:
    TI MSP430F5529 + CC3100
    TI CC3200-LaunchXL
    RedBearLab CC3200
    RedBearLab WiFi Mini w/ CC3200
    RedBearLab WiFi Micro w/ CC3200

  Requires Energia IDE: http://energia.nu/download/

  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPLdo7sm4WK"
#define BLYNK_DEVICE_NAME "KSRM"
//#define BLYNK_AUTH_TOKEN "z3H0SIVa2fRdgQaNIDDnvX9HID5D3h49"

#include <SPI.h>
#include <WiFi.h>
#include "BlynkSimpleEnergiaWiFi.h"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "z3H0SIVa2fRdgQaNIDDnvX9HID5D3h49";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "realme 6";
char pass[] = "123456789";

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(GREEN_LED,OUTPUT);
    pinMode(RED_LED,OUTPUT);
  pinMode(YELLOW_LED,OUTPUT);


  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}


BLYNK_WRITE(V0)
{
    int a=param.asInt();
    digitalWrite(RED_LED,a);
    delay(500);
}

BLYNK_WRITE(V1)
{
    int c=param.asInt();
    digitalWrite(GREEN_LED,c);
    delay(500);
}

BLYNK_WRITE(V2)
{
    int b=param.asInt();
    digitalWrite(YELLOW_LED,b);
    delay(500);
}
void loop()
{
  Blynk.run();
}
