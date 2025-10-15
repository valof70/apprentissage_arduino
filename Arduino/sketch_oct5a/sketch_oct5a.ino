
void setup() {
  // put your setup code here, to run once:
 for (int pin = 0; pin < 50; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
}
}
void loop() {
  // put your main code here, to run repeatedly:
 
}
