#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define printn(v,n) for(int i=0;i<n;i++) cout << v[i] << (i == n-1 ? "\n" : " ")

// GERA A ENTRADA DA QUESTÃO
// PRINTA O QUE VAI SER USADO DE INPUT

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(int n){
    vector<int> V(n);
    for(int i=0;i<n;i++) { V[i] = uniform_int_distribution<int>(1,64)(rng); }

    // RANDOMIZAR O VECTOR
    // shuffle(V.begin(), V.end(), rng);

    cout << n << " 1\n";
    printn(V, n);

    ll a = uniform_int_distribution<ll>(1,n)(rng);
    ll b = uniform_int_distribution<ll>(1,n)(rng);

    if(a>b) { swap(a,b); }
    cout << a << " " << b << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t = uniform_int_distribution<int>(1,64)(rng);
    solve(t);
}