// https://leetcode.com/problems/counting-bits/#/description
// 338. Counting Bits
/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Show Hint

 */
#import <iostream>

using namespace std;

class Solution5 {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);

        for (int i = 1; i <= num; ++i) {
            int prevNum = i & (i-1);
            result[i] = result[prevNum] + 1;
        }

        return result;
    }

    void test() {
//        int num = 5;
        int num = 4;
        auto result = this->countBits(num);
        cout << "338. Counting Bits : ";
        for_each(result.begin(), result.end(), [](int num) {
            cout << num << ",";
        });
        cout << endl;
    }
};
