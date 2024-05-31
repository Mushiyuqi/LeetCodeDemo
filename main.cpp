#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>
using namespace std;

queue<pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int x, y, ans = 0;

void bfs(long long sx, long long sy, vector<vector<bool>>& vis, vector<string>& arr){
    pair<int, int> nt{sx, sy};
    vis[nt.first][nt.second] = true;
    q.push(nt);
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        for(int i = 0; i != 4; ++i){
            int tx = tmp.first + dx[i];
            int ty = tmp.second + dy[i];
            if(tx >= 0 && tx < x && ty >= 0 && ty < y && arr[tx][ty] == '1'  && !vis[tx][ty]){
                vis[tx][ty] = true;
                q.emplace(tx, ty);
            }
        }
        q.pop();
    }
}

int main() {
    vector<string> arr {
        "0101",
        "1001",
        "0101",
        "1111"
    };
    x = arr.size();
    y = arr[0].size();
    vector<vector<bool>> vis(x, vector<bool>(y, false));

    for(int i = 0; i != x; ++i){
        for(int j = 0; j != y; ++j){
            if(vis[i][j] || arr[i][j] == '0')
                continue;
            bfs(i, j, vis, arr);
            ++ans;
        }
    }

    for(const auto& e : arr){
        for(auto u : e){
            cout<< u << " ";
        }
        cout<<endl;
    }
    cout<< ans << endl;
    return 0;
}