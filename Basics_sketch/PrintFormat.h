/*
  Print methods
*/
#ifndef PRINTFORMAT_H
#define PRINTFORMAT_H

#include "Arduino.h"

void formatPrint( char *leftStr, int MyVar1, char *sepStr);
void formatPrint( char *leftStr, char *myStr, char *sepStr);
void formatPrint( char *leftStr, byte *myStr, char *sepStr);
void readTransferedData(char (& cocktailRequest)[11]);
boolean compareStr(char * str1, char * str2);

#endif
