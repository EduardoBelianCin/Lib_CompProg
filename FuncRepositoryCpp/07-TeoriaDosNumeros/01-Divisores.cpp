#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// complexidade temporal: 0 (sqrt(n))
// complexidade espacial: 0 (qntdivisores (n))

vector<ll> getdivisors(ll n) {
    vector<ll> divisors;
    for(ll i=1;i*i<=n;i++) {
        if(n%i == 0) {
            divisors.push_back(i);
            if(i != n/i) { divisors.push_back(n/i); }
        }
    }
    return divisors;
}