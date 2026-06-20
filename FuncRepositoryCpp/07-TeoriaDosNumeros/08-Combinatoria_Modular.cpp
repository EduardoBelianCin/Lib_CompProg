#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e3 + 7;
const int MOD = 1e9 + 7;
ll fact[MAXN], invFact[MAXN];

ll fexp(ll base, ll pot) {
	ll ans = 1;
	while(pot) {
		if(pot & 1) { ans = ans * base % MOD; }
		base = base * base % MOD;
		pot >>= 1;
	}
	return ans;
}

// APENAS PRA MOD PRIMO
ll inv(ll x) { return fexp(x, MOD-2); }

// Complexidade O(MAXN)
void precompute() {
    fact[0] = 1;
    for(int i=1;i<MAXN;i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    // Calcula o inverso do último fact
    invFact[MAXN-1] = inv(fact[MAXN-1]);

    // Preenche o resto de tras para frente
    for(int i=MAXN-2;i>=0;i--) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }
}

ll binomial(ll n, ll k) {
    if(k > n || k < 0) { return 0; }
    return ((fact[n] * invFact[k] % MOD) * invFact[n-k]) % MOD;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    // PRECOMPUTAR NO MAIN
    precompute();
}