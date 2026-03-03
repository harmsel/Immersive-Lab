#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "hutspot";//GEEN SPATIES gebruiken
const char* password = "88888888";

const char* tdIP = "10.71.28.174";  // IP van je PC met TouchDesigner (jouw IP nummer kun je vinden, vraag internet even ;-)
const int tdPort = 7000;              // Dit zo laten, staat in TD al goed


WiFiUDP udp;

const int buttonPin = D1;  // !!!! draadjes verbinden: op de knop VCC en OUT. Die maak je aan GND en D1 op de NodeMCU
bool lastButtonState = HIGH;
bool buttonPressed = false;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {

  Serial.begin(115200);
      Serial.println(".");
  pinMode(buttonPin, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi verbonden: " + WiFi.localIP().toString());
}

void loop() {
  bool reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }



    if (reading == LOW ) {  // Valt van HIGH naar LOW (ingedrukt)
      udp.beginPacket(tdIP, tdPort);
      udp.write("1\n");  // deze waarde gaat naar TD
      udp.endPacket();

      Serial.println("Knop gedrukt");
    } else if (reading == HIGH) {
      udp.beginPacket(tdIP, tdPort);
      udp.write("0\n");  // Deze waarde gaat naar TouchDesigner
      udp.endPacket();

    }


  lastButtonState = reading;
  delay(50);
}