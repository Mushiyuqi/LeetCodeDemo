#include <iostream>
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

//并查集
class UnionFind{
private:
    vector<int> fa;
    vector<int> size;
public:
    UnionFind(int n) : fa(n), size(n,1){
        iota(fa.begin(),fa.end(),0);
    }

    int Find(int i){
        if(i == fa[i]){
            return i;
        }else{
            return fa[i] = Find(fa[i]);
        }
    }

    void Union(int i, int j){
        int i_fa = Find(i);
        int j_fa = Find(j);
        fa[i_fa] = j_fa;
        if(i_fa != j_fa){
            size[j_fa] += size[i_fa];
        }

    }

    long long getSize(int i){
        return size[i];
    }
};

