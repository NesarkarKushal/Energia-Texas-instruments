#include <SPI.h>
#include <WiFi.h>

IPAddress ip(192, 168, 43, 122);  

char ssid[] = "EDGATE TECH";
char password[] ="00936903";
char b[100];
int k;

WiFiServer server(5555);

void setup() 
{
  Serial.begin(9600);
 // pinMode(PUSH1,INPUT_PULLUP);
  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to Network named: ");
  // print the network name (SSID);
  Serial.println(ssid); 
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  WiFi.config(ip);
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

  // you're connected now, so print out the status:
  printWifiStatus();

  // start the server:
  server.begin();
}


void loop() 
{
  // wait for a new client:
  WiFiClient client = server.available();  
  if((Serial.available()))
  { 
     for(k = 0;b[k];k++)
     {
     b[k] = ' ';
     }
     Serial.readBytes(b,100);
     Serial.println(b);
    server.println(b);
    delay(500);
  }
    if(client.available())  //Checks for any incoming data from client
    {
      char c=client.read();
      Serial.print(c);
    }
//    if(client==1)
//    {
//      int a=digitalRead(PUSH1);
//      if(a==1)
//      server.println(1);
//    }
}



void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress IP = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(IP);
}
