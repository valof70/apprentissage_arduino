void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  delay(500);
  Serial.println("HELLO from ESP32-S3");
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(millis());
  delay(1000);
}
