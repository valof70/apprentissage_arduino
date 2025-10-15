void setup() {
  // put your setup code here, to run once:
pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_BUILTIN, HIGH); // Allume la LED
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);  // Éteint la LED
  delay(500);
}
