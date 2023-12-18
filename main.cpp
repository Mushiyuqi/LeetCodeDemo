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
    vector<vector<int>> reconstructQueue(vector<vector<int>>&& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){return a[0] == b[0] ? a[1] <= b[1] : a[0] > b[0];});
        for(int i = 0; i != people.size(); ++i){
            if(people[i][1] < i){
                vector<int> tmp = people[i];
                for(int j = i; j != tmp[1]; --j){
                    people[j] = people[j - 1];
                }
                people[tmp[1]] = tmp;
            }
        }
        return people;
    }
};

int main() {

    Solution s;
    //7 0
    //7 1
    //6 1
    //5 0
    //5 2
    for(auto &p : s.reconstructQueue({{7,0},{4,4},{7,1},{5,2},{6,1},{5,0}})){
        for(auto &i : p){
            cout << i << " " ;
        }
        cout<<endl;
    }
    return 0;
}

