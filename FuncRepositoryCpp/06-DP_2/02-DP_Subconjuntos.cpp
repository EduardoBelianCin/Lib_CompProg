#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18; // número arbitrariamente grande

void solve() {
    int n;
    int BITS = 3;
    string juice;

    vector<ll> dp(1 << BITS, INF);
    dp[0] = 0; // não é necessário nenhum custo para obter o conjunto vazio

    for (int i=0;i<n;i++) {
        int mask = 0;
        for(char vitamin : juice) {
            if(vitamin == 'A') mask |= 1;   // liga o primeiro bit
            else if(vitamin == 'B') mask |= 2; // liga o segundo bit
            else if(vitamin == 'C') mask |= 4; // liga o terceiro bit
        }

        int cost;
        for(int j=0;j<(1 << BITS);j++) {
            int x = j | mask; // para cada possível estado, liga os bits do mask
            dp[x] = min(dp[x], dp[j] + cost);
        }
    }

    if(dp[7] == INF) { cout << -1 << "\n"; }
    else { cout << dp[7] << "\n"; }
}