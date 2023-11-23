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
    int canCompleteCircuit(vector<int>&& gas, vector<int>&& cost) {
            int curSum = 0;
            int total = 0;
            int start = 0;
            for(int i = 0; i != gas.size(); ++i){
                curSum += gas[i] - cost[i];
                total += gas[i] - cost[i];
                if(curSum < 0){
                    curSum = 0;
                    start = i + 1;
                }
            }
            if(total < 0)
                return -1;
            return start;
    }
};

int main() {

    Solution s;

    cout << s.canCompleteCircuit({1,2,3,4,5}, {3,4,5,1,2}) << endl;// -8 -5 -5 -3 -2 3

    return 0;
}
