#include "calc.h"
#include "dialogue.h"
#include "complex.h"

/*		
		Electronics calculator project.
   Author: Jakub Guza
   Subject: Object-Oriented Programming Language
   Date: 17.01.2022

   This project, will allow user switching between different number systems
   - bin
   - hex
   - dec,
   also we will be able to perform basic operations on these numbers,
   and we will be able to perform calculations on complex numbers.

*/

/* main function of my project, here I will call all neccessary functions */

int main() {


	show();

	while (true) { // Infinite loop

		caseMenu();

	}
}