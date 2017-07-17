// https://leetcode.com/problems/median-of-two-sorted-arrays/#/description
// 4. Median of Two Sorted Arrays
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 */
#import <iostream>

class Solution85 {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        // 分割后左右两边数字一样多，一定符合
        // m + n = (nums1.size() - m) + (nums2.size() - n)
        // 通过 m 计算 n 有可能 n 会溢出，所以让 m 是短的数组，n 是长的数组
        if (nums1.size() > nums2.size()) {
            auto tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }

        int mMin = 0;
        int mMax = nums1.size();
        int m = 0;
        int n = 0;

        int ml = 0;
        int mr = 0;
        int nl = 0;
        int nr = 0;

        while (mMin <= mMax) {
            m = (mMin + mMax) / 2;
            n = (nums1.size() + nums2.size() - 2 * m) / 2;

            ml = m != 0 ? nums1[m - 1] : INT32_MIN;
            mr = m != nums1.size() ? nums1[m] : INT32_MAX;
            nl = n != 0 ? nums2[n - 1] : INT32_MIN;
            nr = n != nums2.size() ? nums2[n] : INT32_MAX;

            if (ml > nr) {
                mMax = m - 1;
            } else if (nl > mr) {
                mMin = m + 1;
            } else {
                if ((nums1.size() + nums2.size()) % 2 == 1) {
                    return min(mr, nr);
                } else {
                    return (max(ml, nl) + min(mr, nr)) / 2.0;
                }
            }
        }

        return 0.0;
    }

    void test() {
        // 2
        auto nums1 = vector<int>({1, 3});
        auto nums2 = vector<int>({2, 2});
        // 2.5
//        auto nums1 = vector<int>({1, 2});
//        auto nums2 = vector<int>({3, 4});

        auto result = this->findMedianSortedArrays(nums1, nums2);
        cout << "4. Median of Two Sorted Arrays : " << result << endl;
    }
};
