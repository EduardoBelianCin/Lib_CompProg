#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 2e9;
int best = INF;
int n = 4;
const int MAXN = 4;
int C[MAXN][MAXN];
vector<int> perm;
int cur_cost = 0;

void backtracking_tsp(int i, int used){
    int cnt = __builtin_popcount(used);
    if(cnt == n){
        best = min(best, cur_cost);
        return;
    }

    for(int j = 0; j < n; j++) if(!(used & (1<<j))){
        // faz
        used ^= (1<<j);
        perm.push_back(j);
        cur_cost += C[i][j];
        backtracking_tsp(j, used);
        // desfaz
        cur_cost -= C[i][j];
        perm.pop_back();
        used ^= (1<<j);
    }
}
