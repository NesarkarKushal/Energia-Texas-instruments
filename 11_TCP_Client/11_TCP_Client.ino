#include <SPI.h>
#include <WiFi.h>

char ssid[]= "EDGATE TECH";
char password[]= "00936903";

uint16_t port =1124;     // port number of the server
IPAddress server(192,168,1,122);   // IP Address of the server
WiFiClient client;

void setup()
{
  Serial.begin(9600);
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
        Serial.print(".");

  }
  
    Serial.println("Connected to Server");

  }

void loop()
{
  if(client.available())
  {
    char c=client.read();
    Serial.print(c);
  }
}
