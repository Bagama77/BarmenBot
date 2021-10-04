#include "Arduino.h"
#include "PrintFormat.h"

void formatPrint( char *leftStr, int MyVar1, char *sepStr) {
  Serial.print (leftStr);
  Serial.print (MyVar1);
  Serial.println (sepStr);
}


void formatPrint( char *leftStr, char *myStr, char *sepStr) {
  Serial.print (leftStr);
  Serial.print (myStr);
  Serial.println (sepStr);
}

void formatPrint( char *leftStr, byte *myStr, char *sepStr){
  Serial.print (leftStr);
  for(int i = 4; i < 11; i++) {
    Serial.print(myStr[i]);
  }
  Serial.print(F(" "));
  Serial.println (sepStr);
}

void readTransferedData(char (& cocktailRequest)[11]){
//  char result[11];
  int counter = 0;
  while (Serial.available()) {
    delay(10);  //small delay to allow input buffer to fill

    char c = Serial.read();  //gets one byte from serial buffer
//    Serial.print(F("byte = ")); Serial.println(c); 
    
    if (c == '.' || counter == 11) {
      break;
    }  
    
    cocktailRequest[counter] = c;
    Serial.print(F("result = ")); Serial.println(cocktailRequest);
    counter++; 
  }  

  if (sizeof(cocktailRequest) > 0) {
    Serial.println(cocktailRequest); //prints string to serial port out
  }
//  return result;
}

boolean compareStr(char * str1, char * str2){
  for(int c = 0; c < sizeof(str1); c++){
    Serial.print("size=");
    Serial.print(sizeof(str1));
    Serial.print("comparing str1[c]=");
    Serial.print((char)str1);
    Serial.print(" with str2[c]=");
    Serial.println(str2);
    if(str1[c] != str2[c]) return false;
  }
  return true;
}
