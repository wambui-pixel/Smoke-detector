#include <Blynk.h>


//Blynk MQ-2 Smoke Detector
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include <SimpleTimer.h>
//#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
char auth[] = "vt9SFMRsZ9uEgSjg3MqdF3cwOe8Kosu7"; //Enter Authentication code sent by Blynk
 

char ssid[] = "GEARBOX STAFF"; //Enter WIFI Name
char pass[] = "Staff@Gearbox"; //Enter WIFI Password
 
SimpleTimer timer;
 
int mq2 = A0; // smoke sensor is connected with the analog pin A0 
int data = 0; 
void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}
 
void getSendData()
{
data = analogRead(mq2); 
  Blynk.virtualWrite(V2, data);
 
  if (data > 700 )
  {
    Blynk.notify("Smoke Detected!"); 
  }
 
}
