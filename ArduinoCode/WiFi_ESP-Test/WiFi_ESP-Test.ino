//Deze code is gemaakt om te testen of de verbinding tussen TD en de NodeMCU werkt
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "hutspot";  //GEEN SPATIES gebruiken
const char* password = "88888888";

const char* tdIP = "10.71.28.174";  // IP van je PC met TouchDesigner (jouw IP nummer kun je vinden, vraag internet even ;-)
const int tdPort = 7000;            // Dit zo laten, staat in TD al goed

WiFiUDP udp;

void setup() {

  Serial.begin(115200);
  Serial.println(".");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi verbonden: " + WiFi.localIP().toString());
}


void loop() {

  udp.beginPacket(tdIP, tdPort);
  udp.write("0\n");
  udp.endPacket();
  delay(500);

  udp.beginPacket(tdIP, tdPort);
  udp.write("1\n");
  udp.endPacket();
  delay(500);

  udp.beginPacket(tdIP, tdPort);
  udp.write("2\n");
  udp.endPacket();
  delay(500);

  udp.beginPacket(tdIP, tdPort);
  udp.write("3\n");
  udp.endPacket();
  delay(500);
}
