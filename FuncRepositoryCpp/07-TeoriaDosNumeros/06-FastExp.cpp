#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll fexp(ll base, ll pot) {
	ll ans = 1;
	while(pot) {
		if(pot & 1) { ans = ans * base % MOD; }
		base = base * base % MOD;
		pot >>= 1;
	}
	return ans;
}