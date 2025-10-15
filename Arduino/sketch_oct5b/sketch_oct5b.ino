#define BROCHE_ADC 1     // Broche GPIO utilisée pour lire la tension (ex: GPIO1)
#define TENSION_MAX 3.3  // Tension max mesurable (3.3V sur ESP32-S3)
#define RESOLUTION 4095  // Résolution ADC 12 bits (0 à 4095)

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);          // Démarre la communication série (pour afficher les résultats)
  delay(1000);
  Serial.println("Lecture de tension sur ESP32-S3");
}

void loop() {
  // put your main code here, to run repeatedly:
int valeurBrute = analogRead(BROCHE_ADC);             // Lit la valeur ADC brute (0 à 4095)
  float tension = valeurBrute * (TENSION_MAX / RESOLUTION);  // Conversion en volts
  
  Serial.print("Valeur brute : ");
  Serial.print(valeurBrute);
  Serial.print("  -->  Tension : ");
  Serial.print(tension, 3);  // affiche avec 3 décimales
  Serial.println(" V");
  
  delay(1000);  // lecture toutes les secondes
}
