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
    int candy(vector<int> &&ratings) {
        int n = ratings.size();
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i != n; ++i) {
            if (ratings[i] - ratings[i - 1] > 0)
                candies[i] = candies[i - 1] + 1;
        }

        for (int i = n - 2; i != -1; --i) {
            if (ratings[i] - ratings[i + 1] > 0 && candies[i] <= candies[i + 1])
                candies[i] = candies[i + 1] + 1;
        }

        int sum = accumulate(candies.begin(), candies.end(),0);

        return sum;
    }
};

int main() {

    Solution s;

    cout << s.candy({1, 2, 3, 4, 1}) << endl;// 1 2 3 4 1

    return 0;
}
