#include<ESP8266WiFi.h>
const char* ssid = "LU-IoT2";
const char* password = "CSC49008";

void setup() {
  Serial.begin(9600);
WiFi.begin(ssid, password);
Serial.print("Connecting"); 
while( WiFi.status() != WL_CONNECTED) // while not connected to AP 
{
  delay(500);
  Serial.print("."); 

}

Serial.println(WiFi.localIP());
}
void loop(){

}
