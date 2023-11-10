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
    vector<bool> used;
    int numsLen;

    void backTrack(vector<int>& nums){
        if(path.size() == numsLen) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i != numsLen; ++i){
            //树枝去重 和 树层去重
            if(used[i] || i > 0 && nums[i - 1] == nums[i] && used[i - 1] == 0)
                continue;

            used[i] = true;
            path.emplace_back(nums[i]);
            backTrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>&& nums) {
        sort(nums.begin(), nums.end());
        numsLen = nums.size();
        used.resize(numsLen, false);
        backTrack(nums);
        return res;
    }
};

int main() {

    Solution s;

    for (auto e: s.permuteUnique({1,1,2})) {
        for (auto n: e)
            cout << n << " ";
        cout << endl;
    }


    return 0;
}
