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
    int largestSumAfterKNegations(vector<int> &&nums, int k) {
        sort(nums.begin(), nums.end(), [](int a,int b){
            a = a < 0 ? -a : a;
            b = b < 0 ? -b : b;
            return a > b;
        });
        int sum = 0;
        for(int i = 0; i != nums.size(); ++i){
            if(nums[i] < 0 && k > 0){
                nums[i] *= -1;
                --k;
            }
            sum += nums[i];
        }

        if(k % 2){
            sum -= *nums.rbegin();
            *nums.rbegin() *= -1;
            sum += *nums.rbegin();
        }
        return sum;
    }
};

int main() {

    Solution s;

    cout << s.largestSumAfterKNegations({-4, -2, -3}, 1) << endl;// -8 -5 -5 -3 -2 3

    return 0;
}
