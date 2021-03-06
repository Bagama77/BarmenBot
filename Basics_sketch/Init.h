/*
  Initialization methods
*/
#ifndef INIT_H
#define INIT_H

#include "Arduino.h"
#include <SoftwareSerial.h>

//initialise outputs to drinks
void initOutputs();

// initialise serial port with baud rate of 9600
void initSerialPort(int baudRate);

//Init reset button
void initResetButton(int button);

#endif
