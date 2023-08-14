#include <Arduino.h>
#include <IniFileX.h>

IniFileX configFile(D1, "/config.ini");  // Initialisez la bibliothèque avec la broche D1 et le nom du fichier

void setup() {
  Serial.begin(115200);
  while (!Serial);
  delay(1000);

  String motDePasse = configFile.readVariable("wifi", "mdp");
  Serial.println("Mot de passe WiFi : " + motDePasse);

  // ... Reste de la configuration
}

void loop() {
  // Votre code ici
}
