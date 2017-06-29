// https://leetcode.com/problems/candy/#/description
// 135. Candy
/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
 */
#import <iostream>

class Solution68 {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) {
            return 0;
        }

        auto candys = vector<int>(ratings.size());
        candys[0] = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candys[i] = candys[i - 1] + 1;
            } else {
                candys[i] = 1;
            }
        }

        for (int j = ratings.size() - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1]) {
                if (candys[j] <= candys[j + 1]) {
                    candys[j] = candys[j + 1] + 1;
                }
            }
        }

        auto result = 0;
        for (int k = 0; k < candys.size(); ++k) {
            result += candys[k];
        }

        return result;
    }

    void test() {
        // 9
        vector<int> ratings = {4, 2, 3, 4, 1};

        auto result = this->candy(ratings);
        cout << "135. Candy : " << result << endl;
    }
};
