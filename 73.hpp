// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description
// 121. Best Time to Buy and Sell Stock
/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
 */
#import <iostream>

class Solution73 {
public:
    int maxProfit(vector<int> &prices) {
        auto result = 0;

        auto min = INT32_MAX;
        auto max = INT32_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] > max) {
                max = prices[i];
            }
            if (prices[i] < min) {
                if (max > min) {
                    if (max - min > result) {
                        result = max - min;
                    }
                }

                min = prices[i];
                max = INT32_MIN;
            }
        }
        if (max > min) {
            if (max - min > result) {
                result = max - min;
            }
        }

        return result;
    }

    void test() {
//        auto prices = vector<int>({7, 1, 5, 3, 6, 4});
//        auto prices = vector<int>({7, 6, 4, 3, 1});
        auto prices = vector<int>({3, 2, 6, 5, 0, 3});

        auto result = this->maxProfit(prices);
        cout << "121. Best Time to Buy and Sell Stock : " << result << endl;
    }
};
