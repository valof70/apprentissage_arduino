#define BROCHE_LED LED_BUILTIN          // LED intégrée sur LED_BUILTIN
#define BROCHE_ADC LED_BUILTIN         // Broche pour la mesure
#define TENSION_MAX 3.3       // Tension max mesurable (ADC = 0–3.3 V)
#define RESOLUTION 4095       // ADC 12 bits : 0–4095

unsigned long dernierClignotement = 0;
const unsigned long intervalLED = 250; // 500 ms
bool etatLED = false;

unsigned long dernierMesure = 0;
const unsigned long intervalMesure = 250; // 250 ms (4 mesures/s)


void setup() {
  // put your setup code here, to run once:
pinMode(LED_BUILTIN, OUTPUT);
analogReadResolution(12);   // Active la résolution 12 bits du SAMD21
Serial.begin(9600);          // Démarre la communication série (pour afficher les résultats)
while (!Serial);
Serial.println("Lecture de tension sur Arduino MKR Zero");
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long maintenant = millis();

  // Clignotement LED
  if (maintenant - dernierClignotement >= intervalLED) {
    etatLED = !etatLED;
    digitalWrite(BROCHE_LED, etatLED);
    dernierClignotement = maintenant;
  }

}
