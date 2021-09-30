#include "Arduino.h"
#include "PrintFormat.h"

void formatPrint( char *leftStr, int MyVar1, char *sepStr) {
  Serial.print (leftStr);
  Serial.print (MyVar1);
  Serial.print (sepStr);
}


void formatPrint( char *leftStr, char *myStr, char *sepStr) {
  Serial.print (leftStr);
  Serial.print (myStr);
  Serial.print (sepStr);
}
