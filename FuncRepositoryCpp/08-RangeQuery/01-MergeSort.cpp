#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(),(a).end()

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

vector<ll> Merge2(vector<ll>& A, vector<ll>& B) {
    vector<ll> C;
    merge(all(A), all(B), back_inserter(C));
    return C;
}

// Tendo os arrays A e B ordenados, queremos construir C ordenado possuindo todos elementos de A e B.
// Two pointers! O(n)
