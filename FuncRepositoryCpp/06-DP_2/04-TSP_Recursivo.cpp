#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)

// MENOR SOMA DOS PARES DE DISTANCIAS 

int n;
const int MOD = 1e9 + 7;
const int MAXN = 21;
int grid[MAXN][MAXN];
int dp[MAXN][1<<MAXN];
const int INF = 2e9;

int DP(int i, int mask) {
    if(mask == (1<<n) - 1) { return dp[i][0]; }

    int& ans = dp[i][mask];
    if(ans != -1) { return ans; }

    ans = INF;
    FORj(n) {
        // Se o Bit j ja foi usado (continue)
        if(mask & (1<<j)) { continue; }
        ans = min(ans, grid[i][j] + DP(j, mask ^ (1<<j)));
    }
    return ans;
}

void solve(){
    // Inicializacao da dp
    FORi(n) {
        FORj(1<<n) {
            dp[i][j] = -1;
        }
    }
}