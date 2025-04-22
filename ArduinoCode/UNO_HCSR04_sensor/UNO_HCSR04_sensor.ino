#include <HCSR04.h>

HCSR04 hc(2, 3);  //trigger op 2, echo op 3. Ik heb een Arduino UNO gebruikt, maar dit werkt ook op je NodeMCU
int afstand;

void setup() {
  Serial.begin(9600);
}

void loop() {

  afstand = hc.dist();
  delay(100);

  if (afstand > 4 && afstand < 220) // de sensor werkt alleen betrouwbaar tussen deze afstanden
    Serial.println(afstand / 50);  //ik deel de afstand door 50. Dan krijg je in Touchdesinger 1, 2, 3 of 4 binnen. Dan kun je op deze afstanden (elke keer 50 cm verder) een beeld/geluid triggeren
}