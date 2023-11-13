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

class MyCompare {
public:
    bool operator()(double a, double b) const {
        return a > b;
    }
};

class Solution {
    vector<vector<string>> res;
    vector<string> path;

    bool isOk(int l, int r, int n) {
        //列
        for (int i = 0; i != l; ++i) {
            if (path[i][r] == 'Q')
                return false;
        }
        for (int i = l - 1, j = r - 1; i >= 0 && j >= 0; --i, --j) {
            if (path[i][j] == 'Q')
                return false;
        }

        for (int i = l - 1, j = r + 1; i >= 0 && j < n ; --i, ++j){
            if (path[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backTrack(int n, int l) {
        if (l == n) {
            res.emplace_back(path);
            return;
        }

        for (int r = 0; r != n; ++r) {
            path[l][r] = 'Q';
            if (isOk(l, r, n))
                backTrack(n, l + 1);
            path[l][r] = '.';
        }

    }

public:
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i != n; ++i) {
            path.push_back("");
            for (int j = 0; j != n; ++j) {
                path.rbegin()->push_back('.');
            }
        }

        backTrack(n, 0);

        return res;
    }
};

int main() {

    Solution s;

    for (auto e: s.solveNQueens(1)) {
        for (auto n: e)
            cout << n << " ";
        cout << endl;
    }


    return 0;
}
