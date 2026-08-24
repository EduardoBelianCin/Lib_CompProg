#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)

const int MAXN = 2026;

void solve() {
    int n,p; cin>>n>>p;

    // prob de pegar uma figurinha nova
    // prob[i][j], dado que eu tenho i figurinhas de j totais
    vector<vector<double>> prob(MAXN+1, vector<double>(MAXN+1, 0.0));
    for(int j=1;j<=MAXN;j++) {
        for(int i=0;i<j;i++) {
            double pb = j-i; pb /= j;
            prob[i][j] = pb;
        }
    }

    double j_novo = p; j_novo /= 100;

    // quantidade esperada de dias pra completar
    // dp[i][j], dado que eu tenho i figurinhas de j totais
    vector<vector<double>> dp(MAXN+1, vector<double>(MAXN+1, 0.0));
    for(int j=MAXN;j>=n;j--) {
        for(int i=j-1;i>=0;i--) {
            dp[i][j] = 1;

            double novo = j_novo;
            if(j == MAXN) { novo = 0.0; }

            // figurinha nova, sem jogador novo
            dp[i][j] += dp[i+1][j] * prob[i][j] * (-novo + 1);

            // figurinha nova, com jogador novo
            if(j < MAXN) { dp[i][j] += dp[i+1][j+1] * prob[i][j+1] * novo; }

            // figurinha repetida, com jogador novo
            if(j < MAXN) { dp[i][j] += dp[i][j+1] * (-prob[i][j+1] + 1) * novo; }


            // divide pela 1-prob de manter o estado
            double w = (-prob[i][j] + 1); // repetida
            w *= (-novo + 1); // sem novo
            dp[i][j] /= (-w + 1);
        }
    }
    cout << dp[0][n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cout << fixed << setprecision(12);

    solve();
}