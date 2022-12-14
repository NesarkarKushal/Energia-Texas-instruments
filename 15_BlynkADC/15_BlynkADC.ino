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
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"
#define BLYNK_TEMPLATE_ID "TMPL-dysk2Bn"
//#define BLYNK_DEVICE_NAME "Analog"
//#define BLYNK_AUTH_TOKEN "8kIRtrRe4mzYvxG25Ri3ToZkVpN-hrZi"

#include <SPI.h>
#include <WiFi.h>
#include "BlynkSimpleEnergiaWiFi.h"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "8kIRtrRe4mzYvxG25Ri3ToZkVpN-hrZi";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "EDGATE TECH";
char pass[] = "00936903";

int i;
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(2,INPUT);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
   i=analogRead(2);
    Serial.println(i);
    
  Blynk.virtualWrite(V0,i);
      delay(1000);


  Blynk.run();
}
