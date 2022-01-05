#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <numeric>

#include "dialogue.h"
#include "calc.h"
#include "complex.h"
#include "utils.h"

/* simple and clean menu, informing user about what calculations he can choose */
void show();

/* this function is handling basic operations switch-case */
void BasOp_case();

/* this function is handling switching between different systems switch-case */
void diffSys_case();

/* this function is handling operations on complex numbers switch-case */
void complex_case();

/* this function is used in infinite loop, in a switch-case, it allows the user to choose a specific option */
void caseMenu();



/* these three ASK functions below, are because we wanna interact with the calculator after getting a result! */
void askComplex_Case();

void askbasOP_Case();

void askDiffSys_Case();





/* dialogue.h */
#endif