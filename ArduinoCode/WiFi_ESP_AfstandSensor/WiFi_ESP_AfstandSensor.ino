#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "hutspot";
const char* password = "88888888";
const char* tdIP = "10.71.28.174";
const int tdPort = 7000;

WiFiUDP udp;

// HC-SR04 pinnen
const int trigPin = D1;  // TRIG aansluiten op D1
const int echoPin = D2;  // ECHO aansluiten op D2
                         // VCC naar 3.3V (of 5V), GND naar GND

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi verbonden: " + WiFi.localIP().toString());
}

long meetAfstand() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms
  long afstand = duration * 0.034 / 2;           // omrekenen naar cm
  return afstand;
}

void loop() {
  long afstand = meetAfstand();
  Serial.println("Afstand: " + String(afstand) + " cm");

  int waarde = 0;

  if (afstand >= 5 && afstand < 15) {
    waarde = 1;  // ~10cm
  } else if (afstand >= 15 && afstand < 25) {
    waarde = 2;  // ~20cm
  } else if (afstand >= 25 && afstand < 35) {
    waarde = 3;  // ~30cm
  } else if (afstand >= 35 && afstand < 45) {
    waarde = 4;  // ~40cm
  }

  if (waarde > 0) {
    String bericht = String(waarde) + "\n";
    udp.beginPacket(tdIP, tdPort);
    udp.write(bericht.c_str());
    udp.endPacket();
    Serial.println("Verstuurd: " + String(waarde));
  }

  delay(200);
}