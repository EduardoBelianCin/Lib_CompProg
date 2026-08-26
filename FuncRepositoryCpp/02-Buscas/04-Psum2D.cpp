#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> Psum2D(vector<vector<ll>> &A) {
    int n = A.size();
    int m = A[0].size();

    vector<vector<ll>> Pre(n, vector<ll>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            Pre[i][j] = A[i][j];

            if(i > 0) {
                Pre[i][j] += Pre[i-1][j];
            }
            if(j > 0) {
                Pre[i][j] += Pre[i][j-1];
            }
            if(i > 0 && j > 0) {
                Pre[i][j] -= Pre[i-1][j-1];
            }
        }
    }
    return Pre;
}

ll SubmatSum(vector<vector<ll>> &Pre, int r1, int c1, int r2, int c2) {
    ll soma = Pre[r2][c2];

    if(r1 > 0) {
        soma -= Pre[r1-1][c2];
    }
    if(c1 > 0) {
        soma -= Pre[r2][c1-1];
    }
    if(r1 > 0 && c1 > 0) {
        soma += Pre[r1-1][c1-1];
    }
    return soma;
}