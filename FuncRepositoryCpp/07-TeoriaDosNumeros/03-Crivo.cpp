#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Complexidade Temporal: O(Nlog(log(N)))
// Complexidade Espacial: O(N)

const int LIM = 1e6 + 5;
bool isPrime[LIM];

vector<int> sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for(ll i=2;i*i<LIM;i++) {
        if(isPrime[i]) {
            for(ll j=i*i;j<LIM;j+=i) { isPrime[j] = false; }
        }
    }

    vector<int> primes;
    for(int i=2;i<LIM;i++) {
        if(isPrime[i]) { primes.push_back(i); }
    }

    return primes;
}

// MARCA PRA TODOS OS VALORES DE 1 ATÉ LIM
// QUAIS OS FATORES PRIMOS CONTEM NA FATORAÇÃO DELE

const int LIM = 2e5 + 5;
vector<bool> vis(LIM+1, false);
vector<vector<int>> primos(LIM);

void sieve2() {
    for(int i=2;i<=LIM;i++) {
        if(vis[i]) { continue; }
        vis[i] = true;
        for(int j=i;j<=LIM;j+=i) {
            vis[j] = true;
            primos[j].push_back(i);
        }
    }
}




const int LIM = 1e6 + 5;
bool isPrime[LIM];

vector<int> sieve3() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    vector<int> primes;
    for(int i=2;i<LIM;i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j=i+i;j<LIM;j+=i) { isPrime[j] = false; }
        }
    }

    return primes;
}