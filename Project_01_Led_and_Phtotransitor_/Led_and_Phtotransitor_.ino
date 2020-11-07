const int LEDPin = 13;
const int LDRPin = A0;


void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(LDRPin, INPUT);

}

void loop() {
  int LDRStatus = analogRead(LDRPin);

  if (LDRStatus <=300) {
    digitalWrite(LEDPin, HIGH);
    Serial.println("Phototransitor is dark, LED is ON");
  }

  else {
    digitalWrite(LEDPin, LOW);
    Serial.println("Phototransitor is not dark, LED is OFF");
    }

}
