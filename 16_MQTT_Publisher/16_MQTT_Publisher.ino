
#include <SPI.h>
#include <WiFi.h>
#include <PubSubClient.h>

// your network name also called SSID
char ssid[] = "EDGATE TECH";
// your network password
char password[] = "00936903";
// MQTTServer or broker to use
char server[] = "broker.hivemq.com";

void callback(char* topic, byte* payload, unsigned int length) 
{
}

WiFiClient pub_client;
PubSubClient client(server, 1883, callback, pub_client);

void setup()
{
  Serial.begin(9600);
  pinMode(PUSH1,INPUT_PULLUP);
  Serial.print("Attempting to connect to Network named: "); 
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  
  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");
  
  while (WiFi.localIP() == INADDR_NONE) {
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nIP Address obtained");
 Serial.println(WiFi.localIP());

   while(!client.connect("pub_client")) 
    {
    Serial.print(".");
    delay(300);
    } 
      Serial.println("Connection success");
}

void loop()
{
  int data=digitalRead(PUSH1);
//  Serial.println(data);
  delay(1000);
  if(data==1)
  {
    if(client.publish("value","Hello"))  //value is name of project and hello is message
    {
      Serial.println("Publish success");
     delay(1000);
    } 
    else
    {
       Serial.println("Publish failed");
        delay(1000);
  }
//  delay(400);
  }
}
