#include "IniFileX.h"

IniFileX::IniFileX(int sdPin, const String& fileName) : _sdPin(sdPin), _fileName(fileName) {}

String IniFileX::readVariable(const String& section, const String& variable) {
  if (!SD.begin(_sdPin)) {
     Serial.println("Erreur lors de l'initialisation de la carte SD");
     return "";
 }

 _configFile = SD.open(_fileName);
 if (!_configFile) {
     Serial.println("Erreur lors de l'ouverture du fichier " + _fileName);
     return "";
 }

 bool sectionTrouvee = false;
 String ligne;
 while (_configFile.available()) {
     ligne = _configFile.readStringUntil('\n');
     ligne.trim();
     if (ligne == "[" + section + "]") {
         sectionTrouvee = true;
         break;
     }
 }

 if (!sectionTrouvee) {
     Serial.println("Section non trouvée : " + section);
     _configFile.close();
     return "";
 }

 while (_configFile.available()) {
     ligne = _configFile.readStringUntil('\n');
     ligne.trim();
     if (ligne.startsWith(variable)) {
         _configFile.close();
         String valeur = ligne.substring(ligne.indexOf('=') + 1);
         valeur.trim();
         return valeur;
     }
 }

 Serial.println("Variable non trouvée : " + variable);
 _configFile.close();
 return "";
}

