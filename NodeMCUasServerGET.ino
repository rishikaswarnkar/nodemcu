#include <ESP8266WiFi.h>
const char* ssid = "LU-IoT2";
const char* password = "CSC49008";
WiFiServer myServer(80);// parameter is serverport
WiFiClient nextClient; // clients will connect to server


void setup() {
  myServer.begin();

  Serial.begin(9600);
  Serial.print("Connecting");
  WiFi.begin(ssid, password);
     pinMode(D1, OUTPUT);

}
void loop() {

  WiFiClient nextClient; // clients will connect to server
  nextClient = myServer.available(); //checks for new client

  if (nextClient != NULL) // if client exists …
  {
    Serial.print("Connected" );
    Serial.println(WiFi.localIP());
    String clientData = ""; // no client data yet …
    while (nextClient.connected()) // while client is there
    {
      if (nextClient.available()) // has client sent data?
      {
         char ch = nextClient.read(); // read next char from client
          if (ch=='\n') { // if this is end of line (command sent)
                        // empty command? in http, means client is done sending commands
              if (clientData.length()==0)  { // tell http client we are done
                     
                     nextClient.println("Connection: close");
                     nextClient.println();
                     nextClient.stop(); // disconnect from client
                     }
      else{ 
        
        Serial.println(clientData);
        nextClient.println(clientData);
 
        {
          if(clientData == "GET"){
            
            ch nextdata = nextClient.read();
            Serial.println("Inside if " + nextdata);
          }
          }
     
         }
 clientData=""; // clear out current command (done with it now)
    } 
 else if (ch!='\r'){
 clientData += ch; // append character to data client sent
 }
      }
    }
  }
}
