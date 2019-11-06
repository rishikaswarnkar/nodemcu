int sensorPin = A0; // D0 = 16    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);
   Serial.begin(9600);  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); // digitalread 
  Serial.println(sensorValue) ;

  delay(sensorValue);
  delay(1000);
}
