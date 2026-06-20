#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FORi(n) for(int i=0;i<n;i++)
#define all(a) (a).begin(),(a).end()

// O(n^2);
// da pra fazer com O(n*log n)

int solve() {
    int n = 9;
    vector<int> A = {10, 9, 2, 5, 3, 7, 101, 9, 20};

    int ans = 0;
    vector<int> dp(n);
    for(int j=0;j<n;j++) {
        dp[j] = 1;
        for(int i=j-1;i>=0;i--) {
            if(A[i] < A[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        ans = max(ans, dp[j]);
    }
    return ans;
}

// O que é o LIS (Longest Increasing Subsequence)?
// Dado um array, queremos achar o tamanho da maior subsequência
// estritamente crescente.

// Importante: subsequência != subarray (podemos pular elementos).



// O(n*log n)
// SÓ SERVE PRA GARANTIR O TAMANHO, E NAO A SUBSEQ EM SI

int solve2() {
    int n = 9;
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 9, 20};

    vector<int> lis;
    for(int x : a) {
        // lower_bound faz a busca binária: 
        // encontra o primeiro elemento >= x
        auto it = lower_bound(lis.begin(), lis.end(), x);

        // if - Se não encontrou ninguém >= x, x é o maior de todos
        // else - Se encontrou, substitui aquele valor por x
        // else - Isso mantém a "cauda" a menor possível
        if(it == lis.end()) { lis.push_back(x); }
        else { *it = x; }
    }

    return lis.size();
}

// LIS de consecutivos
// O(n*log n)
int lis_consecutive() {
    int n = 9;
    vector<int> A = {10, 9, 2, 5, 3, 7, 101, 9, 20};

    map<int,int> dp;
    int ans = 0;
    int prev = -1;  // print seq

    FORi(n) {
        int x = A[i];
        dp[x] = dp[x-1] + 1;
        if(dp[x] > ans) {
            ans = dp[x];
            prev = x;  // print seq
        }
    }

    // Printando a maior Seq
    vector<int> res;
    int count = 0;
    for(int i=n-1;i>=0;i--) {
        if(A[i]==prev) {
            res.push_back(i+1);
            prev--;
            count++;
        }
        if(count>=ans) { break; }
    }
    reverse(all(res));
}