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
    int eraseOverlapIntervals(vector<vector<int>>&& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        vector<int> tmp = {intervals[0][0], intervals[0][0]};
        for(int i = 0; i != intervals.size(); ++i){
            if(intervals[i][0] >= tmp[1]){
                tmp = intervals[i];
                continue;
            }else{
                tmp = {intervals[i][0], min(tmp[1], intervals[i][1])};
                ++res;
            }
        }
        return res;
    }
};

int main() {

    Solution s;

    cout<<s.eraseOverlapIntervals({{1,100},{11,22},{1,11},{2,12}})<<endl;

    return 0;
}

