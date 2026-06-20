#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> dp;
string a,b;

int best(int i, int j) {
    if(i < 0 or j < 0) { return 0; }
    if(dp[i][j] != -1) { return dp[i][j]; }

    dp[i][j] = 0;
    if(a[i] == b[j]) { dp[i][j] = 1 + best(i-1, j-1); }
    else { dp[i][j] = max(best(i-1, j), best(i, j-1)); }
    return dp[i][j];
}

int solve() {
    a = "acbd";
    int n = 4;
    b = "abed";
    int m = 4;

    dp = vector<vector<int>>(n, vector<int>(m, -1));

    return best(n-1, m-1);
}

// O que é o LCS (Longest Common Subsequence)?
// LCS = maior subsequência comum entre duas strings, preservando a
// ordem, mas não necessariamente contígua.