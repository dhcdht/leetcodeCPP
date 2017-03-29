// https://leetcode.com/problems/complex-number-multiplication/#/description
// 537. Complex Number Multiplication
/*
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.

 */
#import <iostream>
#import <string>
#import <sstream>

using namespace std;

class Solution29 {
private:
    // https://en.wikipedia.org/wiki/Complex_number
    class ComplexNumber {
    public:
        int m_realPart;
        int m_imaginaryPart;

        ComplexNumber(string input) {
            auto ss = stringstream(input);
            int realPart = 0;
            int imaginaryPart = 0;
            ss >> realPart;
            // ignore +
            ss.ignore(1);
            ss >> imaginaryPart;

            m_realPart = realPart;
            m_imaginaryPart = imaginaryPart;
        }

        ComplexNumber(int realPart, int imaginaryPart) : m_realPart(realPart), m_imaginaryPart(imaginaryPart) {}
    };

public:
    string complexNumberMultiply(string a, string b) {
        auto inputA = ComplexNumber(a);
        auto inputB = ComplexNumber(b);

        auto realPart = (inputA.m_realPart * inputB.m_realPart) - (inputA.m_imaginaryPart * inputB.m_imaginaryPart);
        auto imaginaryPart =
                (inputA.m_imaginaryPart * inputB.m_realPart) + (inputA.m_realPart * inputB.m_imaginaryPart);
        auto multiplication = ComplexNumber(realPart, imaginaryPart);

        auto oss = ostringstream();
        oss << multiplication.m_realPart << "+" << multiplication.m_imaginaryPart << "i";
        auto result = oss.str();

        return result;
    }

    void test() {
        // 0+2i
//        auto a = string("1+1i");
//        auto b = string("1+1i");
        // 0+-2i
        auto a = string("1+-1i");
        auto b = string("1+-1i");
        auto result = this->complexNumberMultiply(a, b);
        cout << "537. Complex Number Multiplication : " << result << endl;
    }
};
