#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <numeric>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.emplace_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] > res.back()[1]){
                res.emplace_back(intervals[i]);
            }else{
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        return res;
    }
};

int main() {

    Solution s;

    return 0;
}

