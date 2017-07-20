// https://leetcode.com/problems/predict-the-winner/#/description
// 486. Predict the Winner
/*
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2.
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
 */
#import <iostream>

class Solution86 {
public:
    bool PredictTheWinner(vector<int> &nums) {
        auto sum = 0;
        for (auto num : nums) {
            sum += num;
        }

        auto maxScore = takeNumMax(nums, 0, nums.size() - 1, 0);

        return maxScore >= (sum - maxScore);
    }

    int takeNumMax(vector<int> &nums, int left, int right, int score) {
        if (left == right) {
            return score + nums[left];
        } else if (left > right) {
            return score;
        }

        int leftScore = score + nums[left];
        int llScore = takeNumMax(nums, left + 2, right, leftScore);
        int lrScore = takeNumMax(nums, left + 1, right - 1, leftScore);

        int rightScore = score + nums[right];
        int rrScore = takeNumMax(nums, left, right - 2, rightScore);
        int rlScore = takeNumMax(nums, left + 1, right - 1, rightScore);

        return max(min(llScore, lrScore), min(rrScore, rlScore));
    }

    void test() {
        auto nums = vector<int>({1, 5, 2});

        auto result = this->PredictTheWinner(nums);
        cout << "486. Predict the Winner : " << result << endl;
    }
};
