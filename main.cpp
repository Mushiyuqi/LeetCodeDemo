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
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<bool> found(27, false);
        int left ,right , end;

        for(int i = 0; i != s.size(); i = left + 1){
            left = i;
            end = -1;
            right = s.size() - 1;
            while(left != end){
                while(s[right] != s[left] && right != end){
                    --right;
                }
                end = right;
                if(left == right)
                    break;
                else{
                    found[s[left] - 'a'] = true;
                    ++left;
                    while(found[s[left] - 'a'] && left < end)
                        ++left;
                    right = s.size() - 1;
                }
                if(end == s.size())
                    break;
            }
            res.emplace_back(end - i + 1);
        }
        return res;
    }
};

int main() {

    Solution s;

    for(auto e : s.partitionLabels("ababcbacadefegdehijhklij"))
        cout<<e<<" "<<endl;

    return 0;
}

