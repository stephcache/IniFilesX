#ifndef IniFileX_h
#define IniFileX_h

#include <Arduino.h>
#include <SD.h>

class IniFileX {
  public:
   IniFileX(int sdPin, const String& fileName);
   bool begin();
   String readVariable(const String& section, const String& variable);
   void end();
   int getSDPin();  // Ajout de la méthode pour obtenir le numéro de broche de la carte SD
  private:
   int _sdPin;
   String _fileName;
   File _configFile;
};

#endif
