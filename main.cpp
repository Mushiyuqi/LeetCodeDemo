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

    bool isOk(vector<vector<char>> &board, int l, int r) {
        for (int i = 0; i != 9; ++i) {
            if (i == r)
                continue;
            if (board[l][i] == board[l][r])
                return false;
        }

        for (int i = 0; i != 9; ++i) {
            if (i == l)
                continue;
            if (board[i][r] == board[l][r])
                return false;
        }

        int _l = (l / 3) * 3;
        int _r = (r / 3) * 3;
        for (int i = _l; i != _l + 3; ++i) {
            if (i == l)
                continue;
            for (int j = _r; j != _r + 3; ++j) {
                if (j == r)
                    continue;
                if (board[i][j] == board[l][r])
                    return false;
            }
        }

        return true;
    }

    bool backTrack(vector<vector<char>> &board) {

        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                if(board[i][j] != '.')
                    continue;

                for(char m = '1'; m != '9' + 1; ++m){
                    board[i][j] = m;
                    if(isOk(board, i, j)){
                        if(backTrack(board))
                            return true;
                    }
                    board[i][j] = '.';
                }

                return false;
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board) {
        backTrack(board);
    }
};

int main() {

    Solution s;

    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    s.solveSudoku(board);
    for (auto e: board) {
        for (auto n: e)
            cout << n << ' ';
        cout << endl;
    }


    return 0;
}
