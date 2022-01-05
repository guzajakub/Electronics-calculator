#include "calc.h"

using std::vector;

using std::string; using std::bitset; using std::stringstream; using std::hex; using std::uppercase;

double E_Calc::hex2dec(E_Calc &calc) {

    /*
        INPUT -> object of class E_Calc
        DESC -> change hex into decimal value, by multiplying every digit with 16 power of digit location
        OUTPUT -> decimal value 
    
    */

    double dec_value = 0;

        //Example of this function:
        //7DE is a hex number
        //7DE = (7 * 16 ^ 2) + (13 * 16 ^ 1) + (14 * 16 ^ 0)
        
    // We are multiplying every digit with 16 power of digit location
    for (int i = 0; i < calc.getA().length(); i++) {

        if (calc.getA()[i] >= 48 && calc.getA()[i] <= 57) {
            dec_value += (static_cast<unsigned __int64>(calc.getA()[i]) - 48) * pow(16, calc.getA().length() - i - 1);
        }

        else if (calc.getA()[i] >= 65 && calc.getA()[i] <= 70) {
            dec_value += (static_cast<unsigned __int64>(calc.getA()[i]) - 55) * pow(16, calc.getA().length() - i - 1);
        }

        else if (calc.getA()[i] >= 97 && calc.getA()[i] <= 102) {
            dec_value += (static_cast<unsigned __int64>(calc.getA()[i]) - 87) * pow(16, calc.getA().length() - i - 1);
        }

    }
    return dec_value;

};


string E_Calc::hex2bin(E_Calc& calc) {
    /*
        INPUT -> object of class E_Calc
        DESC -> change hex into binary value, by using a function hex_char_to_bin from utils.cpp
        OUTPUT -> binary value 

    */
    string bin = {};

    /* using hex_char_to_bin function, to add to the output a 4bit represenation of every hexadecimal digit*/
    for (unsigned i = 0; i != calc.getA().length(); ++i)
        bin += hex_char_to_bin(calc.getA()[i]);

    return bin;

}



string E_Calc::bin2hex(E_Calc& calc) {


    /*
        INPUT -> object of class E_Calc
        DESC -> change binary into hexadecimal value, b
        OUTPUT -> string value

    */


    bitset<32> set(calc.getA());
    stringstream res;
    res << hex << uppercase << set.to_ulong();
    return res.str();

};



double E_Calc::bin2dec(E_Calc& calc) {

    /*
        INPUT -> object of class E_Calc
        DESC -> change binary into decimal value(unsigned long)
        OUTPUT -> unsigned long value, representation of a decimal value

    */

    double out = {};
    string bin_in = calc.getA();
    int count = 0;

    /* looping from the last index, and if we're occuring '1', we are adding 2^(count) to the output value*/
    for (int i = bin_in.length() - 1; i >= 0; --i) {

        if (calc.getA()[i] == '1') {
            out += pow(2, count);
        }
        count += 1;

    }

    return out;
}


string E_Calc::dec2hex(E_Calc& calc) {

    /*
       INPUT -> object of class E_Calc
       DESC -> change decimal value into hex value(string)
       OUTPUT -> string hexadecimal value

   */


    int dec_num = calc.getb1();
    int r; /* it's a remainder from dividing decimal number by 16*/
    string out_hex = "";
    char hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

    /* it works like that divide number by 16, then take it's quotient, and the whole remainder(e.gif its 14, then in hexa it's E) is our hexadecimal sign */
    while (dec_num > 0) {

        r = dec_num % 16;
        out_hex = hex[r] + out_hex;
        dec_num = dec_num / 16;

    }

    return out_hex;
}



vector<int> E_Calc::dec2bin(E_Calc& calc) {

    /*
      INPUT -> object of class E_Calc
      DESC -> change decimal value into a binary number(vector of ints)
      OUTPUT -> vector<int>

  */


    int dec_num = calc.getb1();
    vector<int> out_bin;

    int i = 0;
    while (dec_num > 0) {

        /* pushback 0 or 1, whether the number is even or no*/
        // Example: 7%2 = 1
        // now 7 / 2 = 3 -> because it's integer
        // 3%2 = 1
        // now 3 / 2 = 1
        // 1%2 = 1
        // and we will pushback to the vector 111 and it's a decimal 7
        out_bin.push_back(dec_num % 2);
        dec_num = dec_num / 2;
        i += 1;

    }

    return out_bin;

}


 /* getters */
string E_Calc::getA() { return a; }
string E_Calc::getB() { return a; }

int E_Calc::getb1() { return b1; }
int E_Calc::getb2() { return b2; }

/* setters */
void E_Calc::setA(string a_) { a = a_; }
void E_Calc::setB(string b_) { a = b_; }

void E_Calc::setb1(int b1_) { b1 = b1_; }
void E_Calc::setb2(int b2_) { b2 = b2_; }