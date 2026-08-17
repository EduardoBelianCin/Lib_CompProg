// converte uma permutação pra um idx unico
// O(n) mas o resultado pode ser gerado no range [0, n!-1]
// para n > 12 resultado precisa de LL

int permutation_to_int(vector<int> &p) {
    int mask = 0;
    int i = 0, r = 0;
    for(int x : p) {
        r = r * ++i + __builtin_popcountll(mask & -(1LL << x));
        mask |= 1LL << x;
    }
    return r;
}


const int MAXN = 1e3 + 7, MOD = 1e9 + 7;
ll fact[MAXN];

void precompute() {
    fact[0] = 1;
    for(int i=1;i<MAXN;i++) { fact[i] = (fact[i-1] * i) % MOD; }
}

// Indice da permutacao 0-idx de [0, n!-1]
ll permutation_to_idx(vector<int> &p) {
    int n = p.size();
    if(n == 0) return 0;

    int min_val = *min_element(p.begin(), p.end());
    ll mask = (1LL << n) - 1;
    ll rank = 0;

    for(int i = 0; i < n; i++) {
        int x = p[i] - min_val;
        
        ll small_disp = mask & ((1LL << x) - 1);
        int cnt = __builtin_popcountll(small_disp);

        rank += cnt * fact[n - 1 - i];

        mask &= ~(1LL << x);
    }

    return rank;
}
