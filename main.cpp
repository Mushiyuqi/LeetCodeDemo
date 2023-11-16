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
    int maxProfit(vector<int>&& prices) {
        int profit = 0;

        for(int i = 0, j = 1; i != prices.size() - 1; ++j, ++i){
            if(prices[j] > prices[i])
                profit += prices[j] - prices[i];
        }

        return profit;
    }
};

int main() {

    Solution s;

    cout << s.maxProfit({7,1,5,3,6,4}) << endl;

//    for (auto e: board) {
//        for (auto n: e)
//            cout << n << ' ';
//        cout << endl;
//    }


    return 0;
}
