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
    bool lemonadeChange(vector<int>&& bills) {
        int five = 0, ten = 0;
        int len = bills.size();
        for(int i = 0; i != len; ++i){
            if(bills[i] == 5) ++five;
            else if(bills[i] == 10){ ++ten; --five;}
            else if(ten){ --ten;--five;}
            else{five -= 3;}
            if(five < 0)return false;
        }
        return true;
    }
};

int main() {

    Solution s;

    cout << s.lemonadeChange({5,5,5,10,20}) << endl;// 1 2 3 4 1

    return 0;
}
