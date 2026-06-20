#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pli pair<ll,int>

// complexidade temporal: O(sqrt(n))
// complexidade espacial: O(qnt_fatores_primos(n))

vector<pli> getprimes(ll n) {
    vector<pli> primes;
    for(ll i=2;i*i<=n;i++) {
        int cnt = 0;

        while(n%i == 0) {
            n /= i;
            cnt++;
        }

        if(cnt > 0) { primes.push_back({i, cnt}); }
    }

    if(n > 1) { primes.push_back({n, 1}); }
    return primes;
}