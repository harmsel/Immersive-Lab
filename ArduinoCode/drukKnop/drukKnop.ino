const int buttonPin = D1;  // verbind de knop tussen GND en deze pin. VOor UNO is dat D2
const int ledPin = 13;


int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {

  buttonState = digitalRead(buttonPin);


  if (buttonState == LOW) {

    Serial.println("1");
    digitalWrite(ledPin, HIGH);
  } else {

    digitalWrite(ledPin, LOW);
    Serial.println("0");
  }
}
