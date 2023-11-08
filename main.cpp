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
using namespace std;

class MyCompare {
public:
    bool operator()(double a, double b) const {
        return a > b;
    }
};

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    int numsLen;

    void backTrack(vector<int> &nums, int startIndex) {
        if (path.size() > 1) {
            res.push_back(path);
        }

        unordered_set<int> used;

        for (int i = startIndex; i != numsLen; ++i) {
            //去重
            if(used.count(nums[i]) == 1)
                continue;
            used.insert(nums[i]);
            //递增
            if (path.size() != 0 && nums[i] < *path.rbegin())
                continue;
            path.push_back(nums[i]);
            backTrack(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &&nums) {
        numsLen = nums.size();
        backTrack(nums, 0);
        return res;
    }
};

int main() {

    Solution s;

    for (auto e: s.findSubsequences({1,1,1,2,2,2,3,3,3})) {
        for (auto n: e)
            cout << n << " ";
        cout << endl;
    }


    return 0;
}
