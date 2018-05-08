// https://leetcode.com/problems/is-graph-bipartite/description/
// 785. Is Graph Bipartite?
/*
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation:
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation:
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.


Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
 */
#import <iostream>
#import "helper.hpp"
#import <map>

class Solution114 {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        if (graph.empty()) {
            return false;
        }

        map<int, int> groupMap;
        for (int i = 0; i < graph.size(); ++i) {
            if (groupMap[i] == 0) {
                groupMap[i] = 1;
            }
            if (!isBipartiteToGroup(graph, i, groupMap)) {
                return false;
            } else if (groupMap.size() == graph.size()) {
                return true;
            }
        }

        return true;
    }

    bool isBipartiteToGroup(vector<vector<int>> &graph, int curIndex, map<int, int> &groupMap) {
        vector<int> &item = graph[curIndex];
        for (int i = 0; i < item.size(); ++i) {
            int nextIndex = item[i];
            if (groupMap[nextIndex] == groupMap[curIndex]) {
                return false;
            } else if (groupMap[nextIndex] == 0) {
                groupMap[nextIndex] = (groupMap[curIndex] == 1) ? 2 : 1;
                if (!this->isBipartiteToGroup(graph, nextIndex, groupMap)) {
                    return false;
                }
            }
        }

        return true;
    }

    void test() {
        typedef vector<vector<int>> Inputs;
        typedef bool Outputs;
        vector<pair<Inputs, Outputs >> tests = {
                {{{1, 3},    {0, 2},    {1, 3},       {0, 2}},                                                                                        true},
                {{{1, 2, 3}, {0, 2},    {0, 1, 3},    {0, 2}},                                                                                        false},
                {{{},        {2, 4, 6}, {1, 4, 8, 9}, {7, 8}, {1, 2, 8, 9}, {6, 9}, {1, 5, 7, 8, 9}, {3, 6, 9}, {2, 3, 4, 6, 9}, {2, 4, 5, 6, 7, 8}}, false},
                {{{1},       {0},       {4},          {4},    {2, 3}},                                                                                true},
        };
        runUnitTest("114 : 785. Is Graph Bipartite?", tests, [&](Inputs inputs) {
            return this->isBipartite(inputs);
        });
    }
};
