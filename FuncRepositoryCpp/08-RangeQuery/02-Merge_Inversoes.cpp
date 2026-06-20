#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> Merge(vector<ll>& A, vector<ll>& B) {
    vector<ll> C;
    int l = 0, r = 0;
    while(l < A.size() && r < B.size()) {
        if(A[l] <= B[r]) { C.push_back(A[l]); l++; }
        else { C.push_back(B[r]); r++; }
    }
    while(l < A.size()) {
        C.push_back(A[l]); l++;
    }
    while(r < B.size()) {
        C.push_back(B[r]); r++;
    }
    return C;
}


// O(N * log N)

void Merge_Inv(int l, int r, ll& inversions, vector<ll>& A) {
    if(l >= r) { return; }

    int m = (l+r) / 2;
    Merge_Inv(l, m, inversions, A);
    Merge_Inv(m+1, r, inversions, A);

    // Os ranges [l,m] e [m+1,r] tao ordenados
    vector<ll> Left;
    for(int i=l;i<=m;i++) { Left.push_back(A[i]); }
    vector<ll> Right;
    for(int i=m+1;i<=r;i++) { Right.push_back(A[i]); }

    int R = 0;
    for(auto x : Left) {
        while(R < Right.size() && Right[R] <= x) { R++; }
        inversions += R;
    }

    vector<ll> C = Merge(Left, Right);
    for(int i=l;i<=r;i++) { A[i] = C[i-l]; }
}


// Dado um array, queremos contar a quantidade de inversões.

// Uma inversão em um array é quando para um par de índices i < j, acontece a[i] > a[j]. Exemplo [1,4,5,7,2].

// Array ordenado não decrescentemente possui 0 inversões.
// [1, 2, 3, 5, 6] = 0 inversões

// Array ordenado decrescentemente possui o máximo de inversões.
// [6, 5, 3, 2, 1] = 10 inversões
