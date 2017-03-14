// https://leetcode.com/problems/fizz-buzz/#/description
// 412. Fizz Buzz
/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution6 {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);

        int mask1 = 3;
        string mask1Str = "Fizz";
        int mask2 = 5;
        string mask2Str = "Buzz";
        for (int i = 0, m1 = mask1-1, m2 = mask2-1; i < n; ++i, m1--, m2--) {
            string str;
            if (m1 == 0) {
                str += mask1Str;
                m1 = mask1;
            }
            if (m2 == 0) {
                str += mask2Str;
                m2 = mask2;
            }
            if (str.empty()) {
                str += to_string(i + 1);
            }
            result[i] = str;
        }

        return result;
    }

    void test() {
        int num = 15;
        auto result = this->fizzBuzz(num);
        cout << "412. Fizz Buzz : ";
        for_each(result.begin(), result.end(), [](string str) {
            cout << str << ",";
        });
        cout << endl;
    }
};
