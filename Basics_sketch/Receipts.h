/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef Receipts
#define Receipts

#include "Arduino.h"

//Definitions of quatities
int ML10 = 2;
int ML15 = 3;
int ML20 = 4;
int ML25 = 5;
int ML30 = 6;
int ML35 = 7;
int ML40 = 8;
int ML45 = 9;
int ML50 = 10;
int ML100 = 20;

//Definitions of receipts of coctails
int MARGARITA[3][2] = {{TEKILA, ML30},{LIME_DJ, ML30},{CUANTRO, ML30}}; //case 1
int WHISKEY50[1][2] = {{WHISKEY, ML50}};                                //case 3
int WHISKEY100[1][2] = {{WHISKEY, ML100}};                              //case 4
int BLOOD_MARY[3][2] = {{VODKA, ML50},{TOMATO_DJ, ML50}};               //case 2
int VODKA50[1][2] = {{VODKA, ML50}};                                    //case 5
int VODKA100[1][2] = {{VODKA, ML100}};                                  //case 6

#endif
