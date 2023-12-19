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
    int findMinArrowShots(vector<vector<int>>&& points) {
        int len = points.size();
        if(len == 0)
            return 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){return a[0]<=b[0];});
        vector<int> resign = points[0];
        int res = 1;

        for(int i = 1; i != len; ++i){
            if(points[i][0] <= resign[1]){
                resign[0] = points[i][0];
                resign[1] = points[i][1] <= resign[1] ? points[i][1] : resign[1];
            }else{
                resign = points[i];
                ++res;
            }
        }
        return res;
    }
};

int main() {

    Solution s;

    cout<<s.findMinArrowShots({{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}})<<endl;

    return 0;
}

