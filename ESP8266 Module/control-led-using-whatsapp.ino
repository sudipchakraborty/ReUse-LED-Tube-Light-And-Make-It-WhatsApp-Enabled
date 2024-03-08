#include <ESP8266WiFi.h>
#include <ThingESP.h>

ThingESP8266 thing("sudip", "LevelIndicator", "ESP8266");

int LED = D0;

unsigned long previousMillis = 0;
const long INTERVAL = 6000;  

void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  thing.SetWiFi("Dr.SudipChakraborty", "abcd@9876543210");
  thing.initDevice();
}


String HandleResponse(String query)
{
  if (query == "led on") {
    digitalWrite(LED, 1);
    return "Done: LED Turned ON";
  }

  else if (query == "led off") {
    digitalWrite(LED, 0);
    return "Done: LED Turned OFF";
  }

  else if (query == "led status")
    return digitalRead(LED) ? "LED is OFF" : "LED is ON";
  else return "Your query was invalid..";

}

void loop()
{
  thing.Handle();

  

}
