#include <SPI.h>
#include <WiFi.h>
char ssid[]= "EDGATE TECH";
char password[]= "00936903";
char b[100];
int k;

uint16_t port =5555;     // port number of the server
IPAddress server(192,168,43,122);   // IP Address of the server
WiFiClient client;

void setup()
{
  Serial.begin(9600); 
 // pinMode(RED_LED,OUTPUT);
  WiFi.begin(ssid, password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("Waiting for Wi-Fi Connection");
     Serial.print(".");
    delay(300);
  }
  
  Serial.println("WiFi Connected");
  Serial.println("Attempting to connect to Server");
  
  while(!client.connect(server,port));
    {
    Serial.println("Connected to Server");
    }  
}

void loop()
{
      if(client.available())   //Checks for any incoming data from server
      {
          char c=client.read();
          Serial.print(c);
          delay(200);
//          if(c==1)
//          digitalWrite(RED_LED,HIGH);
//          else
//          digitalWrite(RED_LED,LOW);

      }  
  if((Serial.available()))
  { 
     for(k = 0;b[k];k++)
     {
     b[k] = ' ';
     }
     Serial.readBytes(b,100);
     Serial.println(b);
     client.println(b);
    delay(500);
  }
}
