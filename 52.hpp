// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/#/description
// 122. Best Time to Buy and Sell Stock II
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#import <iostream>

using namespace std;

class Solution52 {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if (prices.empty()) {
            return profit;
        }

        int curMin = prices[0];
        int curMax = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            int num = prices[i];
            if (num > prices[i - 1]) {
                if (num > curMax) {
                    curMax = num;
                }
            } else if (num < prices[i - 1]) {
                profit += curMax - curMin;

                curMin = num;
                curMax = num;
            }
        }
        profit += curMax - curMin;

        return profit;
    }

    void test() {

    }
};
