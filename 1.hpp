// https://leetcode.com/problems/hamming-distance/#/description
// 461. Hamming Distance
#import <iostream>

using namespace std;

class Solution1 {
public:
    int hammingDistance(int x, int y) {
        int xorResult = x ^ y;
        int result = 0;
        while (xorResult > 0) {
            int r = xorResult & 1;
            if (r) {
                result += 1;
            }

            xorResult >>= 1;
        }

        return result;
    }

    void test() {
        int x = 1, y = 4;
        int result = this->hammingDistance(x, y);
        cout << "461. Hamming Distance : " << result << endl;
    }
};
