#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define FORi(n) for(int i=0;i<n;i++)

void solve() {
    int n,x; cin>>n>>x;
    
    vector<ld> P(n);
    FORi(n) {
        ld p; cin>>p;
        p /= 100;
        P[i] = p;
    }

    vector<vector<ld>> dp_Pr(n+1, vector<ld>(n+1, 0.0));
    // Probabilidade de um Pacote com i Cartas, ter exatamente j cartas raras
    for(int i=0;i<=n;i++) {
        if(i==0) { dp_Pr[0][0] = 1; }
        else { dp_Pr[0][i] = 0; }
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(j > 0) { dp_Pr[i][j] = dp_Pr[i-1][j-1] * P[i-1] + dp_Pr[i-1][j] * (-P[i-1] + 1); }
            else { dp_Pr[i][j] = dp_Pr[i-1][j] * (-P[i-1] + 1); }
        }
    }

    vector<ld> dp(x+1, 0.0);
    // Numero esperado de pacotes que eu preciso abrir, pra ter X raras, dado que eu tenho i raras
    for(int i=x-1;i>=0;i--) {
        dp[i] = 1;
        for(int j=1;j<=n;j++) {
            if(i+j <= x) { dp[i] += dp[i+j] * dp_Pr[n][j]; }
            else { break; }
        }
        dp[i] /= (-dp_Pr[n][0] + 1);
    }
    cout << dp[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cout << fixed << setprecision(9);

    solve();
}