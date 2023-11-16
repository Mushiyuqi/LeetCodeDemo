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
    int maxSubArray(vector<int>&& nums) {
        int res = 0;
        int sum = 0;

        for(int i = 0; i != nums.size(); ++i){
            if(sum < 0)
                sum = 0;
            sum += nums[i];
            res = max(sum ,res);
        }
        return res;
    }
};

int main() {

    Solution s;

    cout << s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) << endl;

//    for (auto e: board) {
//        for (auto n: e)
//            cout << n << ' ';
//        cout << endl;
//    }


    return 0;
}
