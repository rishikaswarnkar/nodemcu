
//#include <ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>
const char* ssid = "LU-IoT2";
const char* password = "CSC49008";
WiFiClient client;
  
void setup(){
    String host = "dweet.io";
Serial.begin(9600);
WiFi.begin(ssid, password);
Serial.print("Connecting"); 
while( WiFi.status() != WL_CONNECTED) // while not connected to AP 
{
  delay(500);
  Serial.print("."); 
}
Serial.println(WiFi.localIP());

if (client.connect(host, 80))
{

 String url = "/get/latest/dweet/for/CSC49008SAB";
 client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" +
 "Connection: close\r\n\r\n");
 while (client.connected())
 {
 Serial.print( client.readStringUntil('\r') );
 client.stop();
  }
    }
}

void loop(){
  delay(100);
}
