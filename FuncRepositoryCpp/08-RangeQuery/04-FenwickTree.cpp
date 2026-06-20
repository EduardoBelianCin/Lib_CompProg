#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
	vector<ll> bit;
	int N;

	BIT() {}
	BIT(int n) : N(n+1), bit(n+1) {}

	void update(int pos, ll val) {
		for(;pos<N;pos+=pos & (-pos)) { bit[pos] += val; }
	}
	// Quantos são menores ou iguais a pos
	ll query(int pos) {
		ll sum = 0;
		for(;pos>0;pos-=pos & (-pos)) { sum += bit[pos]; }
		return sum;
	}
};