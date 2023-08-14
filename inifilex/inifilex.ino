#include <Arduino.h>
#include <IniFileX.h>

IniFileX configFile(D1, "/config.ini");  // Initialisez la bibliothèque avec la broche D1 et le nom du fichier

void setup() {
  Serial.begin(115200);
  while (!Serial);
  delay(1000);

  if (!SD.begin(configFile.getSDPin()))
  {
    Serial.println("Carte SD non détectée.");
    while (1);  // Arrêtez l'exécution en boucle si la carte SD n'est pas détectée
  }

  String motDePasse = configFile.readVariable("wifi", "mdp");
  Serial.println("Mot de passe WiFi : " + motDePasse);

  // ... Reste de la configuration
}

void loop() {
  // Votre code ici
}
