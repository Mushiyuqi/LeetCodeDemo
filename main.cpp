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

class Solution {
public:
    bool canJump(vector<int>&& nums) {
        int end = nums.size() - 1;
        int maxFoot = nums[0];
        for(int i = 0; i < end; ++i){
            maxFoot = max(maxFoot, i + nums[i]);
            if(nums[i] == 0 && maxFoot <= i)
                return false;
        }
        return true;
    }
};

int main() {

    Solution s;

    cout << s.canJump({3,2,1,0,4}) << endl;

//    for (auto e: board) {
//        for (auto n: e)
//            cout << n << ' ';
//        cout << endl;
//    }

    return 0;
}
