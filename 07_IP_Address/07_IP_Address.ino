#include<SPI.h>
#include<WiFi.h>

char ssid[]="realme 6";
char password[]="123456789";
IPAddress ip;


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.print("Attempt to connect:");
  Serial.println(ssid);

  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED)
  {
  Serial.print(".");
  delay(500);
  }
  Serial.println("\n you are connected to the Network");


  while(WiFi.localIP()==INADDR_NONE)
  {
    Serial.print(".");
    delay(300);
  }

  ip=WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

}

void loop() 
{
  
}
