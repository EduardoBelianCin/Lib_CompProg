#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)
#define all(a) (a).begin(),(a).end()
#define printn(v,n) for(int i=0;i<n;i++) cout << v[i] << (i == n-1 ? "\n" : " ")

bool check(ll x) { return true; }

void solve() {
    ll low = 0, high = 9e18;
    ll ans = -1; // Guarda a melhor resposta encontrada

    while(low <= high) {
        ll mid = low + (high-low) / 2;

        // Condição: É (Verdadeiro)?     // ans = mid; no que for salvar
        if(check(mid)) { high = mid - 1; ans = mid; } // Salva o índice / Tenta achar um índice MENOR à esquerda.
        else { low = mid + 1; } // Falso. Preciso aumentar o valor.
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}