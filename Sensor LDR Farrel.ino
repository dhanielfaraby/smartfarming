const int ledPin = 13;
const int ldrPin = A0;
void setup() {
  Serial.begin(19200);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <= 500)
  {
    digitalWrite(ledPin, HIGH);
    Serial.print("Its Dark, Turn on the LED:");
    Serial.println(ldrStatus);

  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.print("Its Bright, Turn off the LED:");
    Serial.println(ldrStatus);
  }

}
