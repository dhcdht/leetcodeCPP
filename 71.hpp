// https://leetcode.com/problems/permutation-sequence/#/description
// 60. Permutation Sequence
/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
 */
#import <iostream>
#include <set>

class Solution71 {
public:
    string getPermutation(int n, int k) {
        auto numbers = string("123456789").substr(0, n);

        auto power = 1;
        for (int i = 2; i <= n; ++i) {
            power *= i;
        }

        string result = "";

        auto num = '0';
        auto section = 0;
        auto index = k;
        for (int i = 0; i < n; ++i) {
            power /= (n - i);
            section = (index - 1) / power;

            num = numbers[section];
            numbers.erase(section, 1);

            result += num;

            index -= power * section;
        }

        return result;
    }

    void test() {
        auto n = 3;
        auto k = 3;

        auto result = this->getPermutation(n, k);
        cout << "60. Permutation Sequence : " << result << endl;
    }
};
