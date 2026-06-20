#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 20;
const int INF = 2e9;
int dp[1<<MAXN][MAXN];
int grid[MAXN][MAXN];

void solve() {
    int n = 4;
    for(int mask=0;mask<(1<<n);mask++) {
        for(int i=0;i<n;i++) { dp[mask][i] = INF; }
    }

    dp[1][0] = 0;
    for(int mask = 1; mask < (1<<n); mask++) {
        for(int i = 0; i < n; i++) if(mask & (1<<i)) {
            for(int j = 0; j < n; j++) {
                if(mask & (1<<j)) { continue; }
                dp[mask ^ (1<<j)][j] = min(dp[mask ^ (1<<j)][j], dp[mask][i] + grid[i][j]);
            }
        }
    }

    int best = INF;
    for(int i = 1; i < n; i++) {
        best = min(best, dp[(1<<n) - 1][i] + grid[i][0]);
    }
}
