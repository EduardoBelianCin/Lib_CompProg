#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    int t = 1;
    vector<int> a = {3, 4, 7, 2};

    vector<bool> dp(t + 1);
    dp[0] = true;

    for (int x : a) {
        for (int i = t - x; i >= 0; --i) {
            if (dp[i]) {
                dp[i + x] = true;
            }
        }
    }

    return dp[t];
}

// O que é o Subset Sum?
// É o problema de decidir se existe algum subconjunto de um conjunto de
// inteiros que some exatamente um valor-alvo T.