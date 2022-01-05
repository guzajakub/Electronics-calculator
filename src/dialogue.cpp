#include "dialogue.h"


using std::cout; using std::cin; using std::vector; using std::string;


void askDiffSys_Case() {

	/* handling a case, what to do after getting a result */
	cout << "\nThat's your result! Tell what you wanna do next:\n \n1. Back to main menu \n2. I wanna calculate same option again!\n3. Exit\n";
	int opt;
	cin >> opt;

	while (cin.fail() || opt > 3 || opt < 1) {

		cin.clear();
		cin.ignore();
		cout << "Bad choice! Please enter a number from 1-3. Please type again: " << std::endl;
		cin >> opt;
	}


	switch (opt) {
	case 1: { show();
		caseMenu();
		break; }

	case 2: diffSys_case();
		break;

	case 3: { cout << "Closing program, see you again!\n";

		exit(0);
	}

	}
}

void askbasOP_Case() {
	/* handling a case, what to do after getting a result */
	cout << "\nThat's your result! Tell what you wanna do next:\n \n1. Back to main menu \n2. I wanna calculate same option again!\n3. Exit\n";
	int opt;
	cin >> opt;

	while (cin.fail() || opt > 3 || opt < 1) {

		cin.clear();
		cin.ignore();
		cout << "Bad choice! Please enter a number from 1-3. Please type again: " << std::endl;
		cin >> opt;
	}

	switch (opt) {
	case 1: { show();
		caseMenu();
		break; }

	case 2: BasOp_case();
		break;

	case 3: { cout << "Closing program, see you again!\n";

		exit(0);
	}

	}
}

void askComplex_Case() {
	/* handling a case, what to do after getting a result */
	cout << "\nThat's your result! Tell what you wanna do next:\n \n1. Back to main menu \n2. I wanna calculate same option again!\n3. Exit\n";
	int opt;
	cin >> opt;

	while (cin.fail() || opt > 3 || opt < 1) {

		cin.clear();
		cin.ignore();
		cout << "Bad choice! Please enter a number from 1-3. Please type again: " << std::endl;
		cin >> opt;
	}

	switch (opt) {
	case 1: { show();
		caseMenu();
		break; }

	case 2: complex_case();
		break;

	case 3: { cout << "Closing program, see you again!\n";

		exit(0);
	}

	}
}

void diffSys_case() {

	/* DESC, this function is handling a case, when user wants to change between specific systems*/

	E_Calc Ec;
	cout << "\nPlease choose which system you wanna enter: \n";
	cout << "1. Hex\n2. Bin\n3. Dec\n\n";
	int sys;
	cin >> sys;
	/* check validity */
	while (cin.fail() || sys > 3 || sys < 1) {

		cin.clear();
		cin.ignore();
		cout << "Bad choice! Please enter a number from 1-3. Please type again: " << std::endl;
		cin >> sys;
	}

	/* switch case, regardless of user input*/
	switch (sys) {

	case 1: {

		string input = {};
		cout << "Please enter hexadecimal value: ";
		cin >> input;
		/* check if given input is a hexadecimal value!!*/
		while (std::all_of(input.begin(), input.end(), ::isxdigit) == false) {

			cin.clear();
			cin.ignore();
			cout << "Bad choice! Please enter a hexadecimal number [e.g. 1FF, 58DCE]: " << std::endl;
			cin >> input;
		}
		/* initializing outputs*/
		double outh2d = {};
		string outh2b = {};
		/* setting user's input to E_Calc object*/
		Ec.setA(input);
		
		/* setting outputs, by specific class methods and showing it on the screen */
		outh2d = Ec.hex2dec(Ec);
		outh2b = Ec.hex2bin(Ec);
		cout << "Bin: " << outh2b << std::endl;
		cout << "Dec: " << outh2d << std::endl;

		askDiffSys_Case();
		break;

	}
		  /* all cases bases on the same scheme as above!! */
	case 2: {

		string input2 = {};
		cout << "Please enter binary value: ";
		cin >> input2;

		while (isStringBinary(input2) == false) {

			cin.clear();
			cin.ignore();
			cout << "Bad input! Please enter a binary value! " << std::endl;
			cin >> input2;
		}

		string out;
		Ec.setA(input2);

		string outb2h = {};
		double outb2d = {};

		outb2h = Ec.bin2hex(Ec);
		outb2d = Ec.bin2dec(Ec);
		
		cout << "Hex: " << outb2h << std::endl;
		cout << "Dec: " << outb2d << std::endl;
		askDiffSys_Case();
		break;
	}
	case 3: {

		int input3 = {};
		cout << "Please enter decimal value: ";
		cin >> input3;

		while (cin.fail() ) {

			cin.clear();
			cin.ignore();
			cout << "Bad input! Please enter a decimal value " << std::endl;
			cin >> input3;
		}

		string outd2h = {};
		vector<int> outd2b = {};

		Ec.setb1(input3);

		outd2h = Ec.dec2hex(Ec);
		outd2b = Ec.dec2bin(Ec);

		cout << "Hex: " << outd2h << std::endl;
		cout << "Bin: ";
		/* reversing order by rbegin(), rend()*/
		std::copy(outd2b.rbegin(), outd2b.rend(),
			std::ostream_iterator<int>(cout));
		askDiffSys_Case();

		break;

	}
	

	}
}



void BasOp_case() {

	/* DESC, this function is handling an option, when our project can be a simple calculator for basic operations
	         as a user we are giving two inputs, and then we can choose which operation we want to do on them, 
			 then show the result in all implemented system [bin, hex] */

	E_Calc E;
	int d1 = {};
	int d2 = {};

	cout << "You've chosen basic operations \n";

	cout << "Please enter first decimal number: ";
	cin >> d1;
	while (cin.fail()) {

		cin.clear();
		cin.ignore();
		cout << "Bad input, enter a decimal number: " << std::endl;
		cin >> d1;
	}

	cout << "\nPlease enter second decimal number: ";
	cin >> d2;
	while (cin.fail()) {

		cin.clear();
		cin.ignore();
		cout << "Bad input, enter a decimal number: " << std::endl;
		cin >> d2;
	}

	E.setb1(d1);
	E.setb2(d2);

	int first = E.getb1();
	int second = E.getb2();

	char sign = {};
	cout << "\nNow specify an operation, type\n+ to perform addition\n- for subtraction\n* for multiplication\n/ for division(INPUTS ARE INTS! be careful)\n-> ";
	cin >> sign;

	/* check if inputs are good */
	while (sign != '+' && sign != '-' && sign != '*' && sign != '/' ) {

		cin.clear();
		cin.ignore();
		cout << "Bad choice! Please enter an operation [*, -, +, /] " << std::endl;
		cin >> sign;
	}

	switch (sign) {

	case '/': {
		/* using showRes function to show us result in all number systems */
		int outD = first / second;
		showRes(outD);
		askbasOP_Case();
		break;
	}

	case '*': {

		int outM = first * second;
		showRes(outM);
		askbasOP_Case();
		break;
	}

	case '+': {

		int outA = first + second;
		showRes(outA);
		askbasOP_Case();
		break;
	}
	case '-': {
		int outS = first - second;
		showRes(outS);
		askbasOP_Case();
		break;
	}

	}
	
}

void complex_case() {


	/* DESC, this function is handling an option, when our project can be a simple calculator for basic complex
	   operations */

	Complex C1(0, 0);
	Complex C2(0, 0);

	cout << "You've chosen operations on complex numbers! \n\n";

	cout << "Please enter first complex number: \n";
	cin >> C1;
	
	cout << "\nPlease enter second complex number: \n";
	cin >> C2;
	cout << "Your numbers: C1 = " << C1;
	cout << "\n              C2 = " << C2;
	char sign2 = {};
	cout << "\n\nNow specify an operation, type\n+ to perform addition\n- for subtraction\n* for multiplication\nm for module for both given numbers\n";
	cin >> sign2;
	/* check for validity of input data!*/
	while (sign2 != '+' && sign2 != '-' && sign2 != '*' && sign2 != 'm'  ) {

		cin.clear();
		cin.ignore();
		cout << "Bad choice! Please enter an operation [*, -, +, module] " << std::endl;
		cin >> sign2;
	}

	cout << std::endl;

	switch (sign2) {


	case '*': {

		Complex C5 = C1 * C2;
		cout << C1 << " * " << C2 << " = " << C5;
		askComplex_Case();
		break;

	}

	case '+': {

		Complex C3 = C1 + C2;
		cout << C1 << " + " << C2 << " = " << C3;
		askComplex_Case();
		break;
	}

	case '-': {

		Complex C4 = C1 - C2;
		cout << C1 << " - " << C2 << " = " << C4;
		askComplex_Case();
		break;

	}

	case 'm': {

		cout << "Module of " << C1 << " is: " << C1.ComplexModule(C1) << std::endl;
		cout << "Module of " << C2 << " is: " << C2.ComplexModule(C2) << std::endl;
		askComplex_Case();
		break;

	}
	}
}


void show() {

	/* simple show menu function*/

	cout << "  ----------------------------------\n";
	cout << "  Welcome to electronics calculator! \n";
	cout << "  ----------------------------------\n\n";

	cout << "Please choose what you wanna do: \n";
	cout << "1. Switch between different systems [hex, bin, dec]\n";
	cout << "2. Perform basic operations like [+, -, :, /]\n";
	cout << "3. Perform basic operations on complex numbers\n";
	cout << "4. Exit\n";
	cout << "Choose option and press enter: ";

}




void caseMenu() {


	/* function caseMenu() is a handler for a user, to actually choose, by putting an specific input,
	whether he wants to switch between different systems
	perform basic operations on different number systems
	perform basic operations on complex numbers */

	int choice = {};

	cin >> choice;

	/* check for validity of input data!*/
	while (cin.fail() || choice > 4 || choice < 1) {
		
		cin.clear();
		cin.ignore();
		cout << "Bad choice! Please enter a number from 1-4. Please type again: " << std::endl;
		cin >> choice;
	}

	switch (choice) {

	case 1:

		diffSys_case();
		break;

	case 2: {

		BasOp_case();
		break;

	}
	case 3: {
		
		complex_case();
		break;

	}

	case 4: {

		cout << "Closing program, see you again!\n";
		exit(0);

	}

	}

}




