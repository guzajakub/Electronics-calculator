#ifndef UTILS_H
#define UTILS_H
#include "dialogue.h"
/*  utils header  */
/*  there will be stored some useful functions  */


/* function to change each character from hexa system, into a 4bit binary number */
const char* hex_char_to_bin(char c);

/* helpful function to show all results for different number systems*/
void showRes(int out);

/* nice function to check if a given string is only binary*/
bool isStringBinary(std::string str);

bool isDecimal(std::string str);

#endif