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
    vector<int> path{};
    int numsLen = 0;

    void comeS(vector<int>& nums, int startIndex){
        ret.push_back(path);

        if(startIndex == numsLen){
            return;
        }

        for(int i = startIndex; i != numsLen; ++i){
            path.push_back(nums[i]);
            comeS(nums,i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>&& nums) {
        numsLen = nums.size();
        comeS(nums,0);
        return ret;
    }
};

int main() {

    Solution s;

    for(auto e : s.subsets({1,2,3})){
        for(auto n : e)
            cout<<n<<" ";
        cout<<endl;
    }


    return 0;
}
