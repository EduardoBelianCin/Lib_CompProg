#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int LOGN = 10; // 2^10 = 1024 >= 1000

int st[LOGN][MAXN][LOGN][MAXN];
int lg[MAXN];

// 1. Pré-computar log2
void precompute_log(int n) {
    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
}

// 2. Construir Sparse Table 2D - O(N * M * log N * log M)
// CUIDADO COM OverFlow
void build_st2d(int n, int m, const vector<vector<int>> &a) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            st[0][i][0][j] = a[i][j];
        }
        for(int k2 = 1; (1 << k2) <= m; k2++) {
            for(int j = 0; j + (1 << k2) <= m; j++) {
                st[0][i][k2][j] = gcd( st[0][i][k2-1][j], st[0][i][k2-1][j + (1 << (k2-1))] );
            }
        }
    }
    for (int k1 = 1; (1 << k1) <= n; k1++) {
        for (int i = 0; i + (1 << k1) <= n; i++) {
            for (int j = 0; j < m; j++) {
                st[k1][i][0][j] = gcd( st[k1-1][i][0][j], st[k1-1][i + (1 << (k1-1))][0][j] );
            }
            for (int k2 = 1; (1 << k2) <= m; k2++) {
                for (int j = 0; j + (1 << k2) <= m; j++) {
                    st[k1][i][k2][j] = gcd( st[k1][i][k2-1][j], st[k1][i][k2-1][j + (1 << (k2-1))] );
                }
            }
        }
    }
}

// 3. Consulta em O(1) - apenas 4 chamadas de gcd
int query_gcd(int x1, int y1, int x2, int y2) {
    int k1 = lg[x2 - x1 + 1];
    int k2 = lg[y2 - y1 + 1];

    int g1 = st[k1][x1][k2][y1];
    int g2 = st[k1][x2 - (1 << k1) + 1][k2][y1];
    int g3 = st[k1][x1][k2][y2 - (1 << k2) + 1];
    int g4 = st[k1][x2 - (1 << k1) + 1][k2][y2 - (1 << k2) + 1];

    return gcd(gcd(g1, g2), gcd(g3, g4));
}