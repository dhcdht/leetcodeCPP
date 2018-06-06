// https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
// 599. Minimum Index Sum of Two Lists
/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
 */
#import <iostream>
#import "helper.hpp"
#import <vector>
#import <string>
#import <unordered_map>

class Solution130 {
public:
    vector <string> findRestaurant(vector <string> &list1, vector <string> &list2) {
        int list1size = list1.size();
        int list2size = list2.size();
        vector<string> result;
        if (0 == list1size || 0 == list2size) {
            return result;
        }

        struct MapValue {
            int value = -1;
        };
        unordered_map<string, MapValue> list1map(list1size);
        for (int i = 0; i < list1size; ++i) {
            string str = list1[i];
            list1map[str].value = i;
        }

        unordered_map<string, int> strMap;
        for (int i = 0; i < list2size; ++i) {
            string str = list2[i];
            if (list1map[str].value >= 0) {
                strMap[str] = list1map[str].value + i;
            }
        }

        int minCount = INT_MAX;
        for (auto item : strMap) {
            string str = item.first;
            int count = item.second;
            if (count < minCount) {
                result.clear();

                result.push_back(str);
                minCount = count;
            } else if (count == minCount) {
                result.push_back(str);
            }
        }

        return result;
    }

    void test() {
        typedef pair <vector<string>, vector<string>> Input;
        typedef vector <string> Output;
        vector <pair<Input, Output>> tests = {
                {{{"Shogun", "Tapioca Express", "Burger King", "KFC"}, {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"}}, {"Shogun"}},
                {{{"Shogun", "Tapioca Express", "Burger King", "KFC"}, {"KFC",    "Shogun",                    "Burger King"}},                        {"Shogun"}}
        };
        runUnitTest("130 : 599. Minimum Index Sum of Two Lists", tests, [&](Input input) {
            return this->findRestaurant(input.first, input.second);
        });
    }
};
