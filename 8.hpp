// https://leetcode.com/problems/next-greater-element-i/#/description
// 496. Next Greater Element I
/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
 */
#import <iostream>
#import <vector>
#import <stack>

using namespace std;

class Solution8 {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result(findNums.size(), -1);

        auto numStack = stack<int>();
        auto greaterMap = unordered_map<int, int>(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];

            while (!numStack.empty()) {
                int stackTop = numStack.top();
                if (num > stackTop) {
                    greaterMap[stackTop] = num;
                    numStack.pop();
                } else {
                    break;
                }
            }

            numStack.push(num);
        }

        for (int j = 0; j < findNums.size(); ++j) {
            int num = findNums[j];

            int greaterNum = greaterMap[num];
            if (greaterNum) {
                result[j] = greaterNum;
            }
        }

        return result;
    }

    void test() {
//        vector<int> nums1({4, 1, 2});
//        vector<int> nums2({1, 3, 4, 2});
        vector<int> nums1({2, 4});
        vector<int> nums2({1, 2, 3, 4});
        auto result = this->nextGreaterElement(nums1, nums2);
        cout << "496. Next Greater Element I : ";
        for_each(result.begin(), result.end(), [](int num) {
            cout << num << ",";
        });
        cout << endl;
    }
};
