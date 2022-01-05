#include "utils.h"
#include "calc.h"

using std::cout; using std::cin; using std::vector; using std::string;

const char* hex_char_to_bin(char c) {
    /*
       INPUT -> character, from 0 to F a.k.a hexadecimal signs
       DESC -> return a string binary value, for each hexadecimal sign
       OUTPUT -> binary value, but in a string

   */

    switch (toupper(c)) {

    case '0': return "0000";
    case '1': return "0001";
    case '2': return "0010";
    case '3': return "0011";
    case '4': return "0100";
    case '5': return "0101";
    case '6': return "0110";
    case '7': return "0111";
    case '8': return "1000";
    case '9': return "1001";
    case 'A': return "1010";
    case 'B': return "1011";
    case 'C': return "1100";
    case 'D': return "1101";
    case 'E': return "1110";
    case 'F': return "1111";

    }
}

void showRes(int out) {
     
    /* this function is useful for showing outputs for basic calculations like + - / and *
    */

        E_Calc E2;
        E2.setb1(out);
        vector<int> outd2b = {};
        outd2b = E2.dec2bin(E2);

        cout << "Dec: " << out << std::endl;
        cout << "Hex: " << E2.dec2hex(E2) << std::endl;
        cout << "Bin: ";

        std::copy(outd2b.rbegin(), outd2b.rend(),
            std::ostream_iterator<int>(cout));
}

bool isStringBinary(string str) {

    /* iterate thhrough all characters, and cheeck if they are only 0's or 1's*/
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '1' && str[i] != '0')
            return false;
    }
    return true;
}

//bool isDecimal(string str) {
//
//    
//    for (int i = 0; i < str.size(); i++)
//    {
//        if (str[i] == '.' || str[i] == ',')
//            return false;
//    }
//    return true;
//}