#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll fexp(ll base, ll pot){
	ll ans = 1;
	while(pot) {
		if(pot & 1) { ans = ans * base % MOD; }
		base = base * base % MOD;
		pot >>= 1;
	}
	return ans;
}

ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }

ll mod_sub(ll a, ll b) { return (((a % MOD) - (b % MOD)) + MOD) % MOD; }

ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

ll mod_div(ll a, ll b) { return mod_mul(a, fexp(b, MOD-2)); }