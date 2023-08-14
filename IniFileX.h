#ifndef IniFileX_h
#define IniFileX_h

#include <Arduino.h>
#include <SD.h>

class IniFileX {
  public:
   IniFileX(int sdPin, const String& fileName);
   String readVariable(const String& section, const String& variable);
  private:
   int _sdPin;
   String _fileName;
   File _configFile;
};

#endif
