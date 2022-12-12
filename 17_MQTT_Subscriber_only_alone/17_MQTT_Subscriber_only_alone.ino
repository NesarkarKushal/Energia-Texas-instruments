/*
 * MQTT Subscriber 
 * Required: CC3200--1 and MY MQTT App
 * in mobile app; Host=broker.hivemq.com
 * then click on publish topic=data or value and then enter message
 */


#include <SPI.h>
#include <WiFi.h>
#include <PubSubClient.h>

// your network name also called SSID
char ssid[] = "EDGATE TECH";
// your network password
char password[] = "00936903";
// MQTTServer to use
char server[] = "broker.hivemq.com";

 
void callback(char* topic, byte* payload, unsigned int length) 
{ 
  Serial.print("Received message for topic: ");
  Serial.println(topic);
  Serial.write(payload,length);
  Serial.println();
}


WiFiClient sub_client;
PubSubClient client(server, 1883, callback, sub_client);

void setup()
{
  Serial.begin(9600);
  Serial.print("Attempting to connect to Network named: ");
  // print the network name (SSID);
  Serial.println(ssid); 
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED) {
    // print dots while we wait to connect
    Serial.print(".");
    delay(300);
  }
  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");
  
  while (WiFi.localIP() == INADDR_NONE) {
    // print dots while we wait for an ip addresss
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nIP Address obtained");
  // We are connected and have an IP address.
  // Print the WiFi status.
  Serial.println(WiFi.localIP());
     while(!client.connect("sub_client")) 
    {
    Serial.print(".");
    delay(300);
    } 
      Serial.println("Connection success");
         while(!client.subscribe("value")) // value is name of the topic
      {
     Serial.print(".");
    delay(300);
      }

      while(!client.subscribe("data")) // value is name of the topic
      {
     Serial.print(".");
    delay(300);
      }
      Serial.println("Subscription successfull");
}

void loop()
{
  client.poll();  // CONTINUOUS Polling for the data on a topic
}
