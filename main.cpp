#include <iostream>
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

void MyPrint(std::string &n) {
    std::cout << n << " ";
}

class MyCompare {
public:
    bool operator()(double a, double b) const {
        return a > b;
    }
};

class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    vector<bool> used;
    int numsLen;

    void comeS(vector<int>& nums, int startIndex){
        ret.push_back(path);
        if(startIndex == numsLen)
            return;
        for(int i = startIndex; i != numsLen; ++i){
            if(i > 0 && nums[i - 1] == nums[i] && used[i - 1] == 0)
                continue;
            used[i] = 1;
            path.emplace_back(nums[i]);
            comeS(nums, i + 1);
            path.pop_back();
            used[i] = 0;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>&& nums) {
        sort(nums.begin(),nums.end());
        numsLen = nums.size();
        used.resize(numsLen,0);
        comeS(nums,0);
        return ret;
    }
};

int main() {

    Solution s;

    for(auto e : s.subsetsWithDup({1,1,2,2})){
        for(auto n : e)
            cout<<n<<" ";
        cout<<endl;
    }


    return 0;
}
