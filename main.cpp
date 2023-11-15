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
    int wiggleMaxLength(vector<int> &&nums) {
        int len = nums.size();
        int preDiff = 0;
        int curDiff = 0;
        int res = 1;

        for (int i = 0; i < len - 1; ++i) {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0))
                res++;
            if (curDiff != 0)
                preDiff = curDiff;
        }
        return res;
    }
};

int main() {

    Solution s;

    cout << s.wiggleMaxLength({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;

//    for (auto e: board) {
//        for (auto n: e)
//            cout << n << ' ';
//        cout << endl;
//    }


    return 0;
}
