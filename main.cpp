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
    int jump(vector<int> &&nums) {
        int footprint = 0;
        int index = nums[0];
        int maxStep = nums[0];
        for(int i = 0; i != nums.size() - 1; ++i){
            maxStep = max(maxStep, nums[i] + i);
            if(i == index){
                ++footprint;
                index = maxStep;
            }
            if(index>=nums.size() - 1){
                return ++footprint;
            }
        }
        return footprint;
    }
};

int main() {

    Solution s;

    cout << s.jump({2,3,1,1,1,4}) << endl;

    return 0;
}
