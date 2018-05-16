// https://leetcode.com/problems/largest-triangle-area/description/
// 812. Largest Triangle Area
/*
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation:
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.
 */
#import <iostream>
#import <vector>
#import <math.h>

class Solution120 {
public:
    double largestTriangleArea(vector<vector<int>> &points) {
        double result = 0;
        for (int i = 0; i < points.size() - 2; ++i) {
            for (int j = i + 1; j < points.size() - 1; ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    double area = this->triangArea(points[i], points[j], points[k]);
                    if (area > result) {
                        result = area;
                    }
                }
            }
        }

        return result;
    }

    double triangArea(vector<int> &pt0, vector<int> &pt1, vector<int> &pt2) {
        double l1 = sqrt((pt0[0] - pt1[0]) * (pt0[0] - pt1[0]) + (pt0[1] - pt1[1]) * (pt0[1] - pt1[1]));
        double l2 = sqrt((pt1[0] - pt2[0]) * (pt1[0] - pt2[0]) + (pt1[1] - pt2[1]) * (pt1[1] - pt2[1]));
        double l3 = sqrt((pt2[0] - pt0[0]) * (pt2[0] - pt0[0]) + (pt2[1] - pt0[1]) * (pt2[1] - pt0[1]));

        double al = (l1 + l2 + l3) / 2;

        double area = sqrt(al * (al - l1) * (al - l2) * (al - l3));

        return area;
    }

    void test() {

    }
};
