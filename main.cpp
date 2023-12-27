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
#include <array>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int result = 0;
    int travel(TreeNode *root){
        if(root == nullptr) return 2;
        int left = travel(root->left);
        int right = travel(root->right);

        if(left == 2 && right == 2) return 0;
        if(left == 0 || right == 0) {++result; return 1;}
        return 2;
    }

public:
    int minCameraCover(TreeNode *root) {
        if(travel(root) == 0) return ++result;
        return result;
    }
};

int main() {

    Solution s;

    return 0;
}