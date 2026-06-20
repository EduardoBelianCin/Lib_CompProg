#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FORi(n) for(int i=0;i<n;i++)

const int MOD = 1e9 + 7;

ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

template<typename T> struct Matrix {
	vector<vector<T>> mat;
    // Linhas x Colunas
	int n,m;

	Matrix(int N, int M=0) : n(N), m(M?M:N){ mat.assign(n, vector<T>(m, 0)); }

	friend Matrix operator* (const Matrix &a, const Matrix &b){
		assert(a.m == b.n);
		Matrix ans(a.n, b.m);
		for(int i=0;i<a.n;i++)
			for(int j=0;j<b.m;j++)
				for(int k=0;k<a.m;k++)
					ans.mat[i][j] = mod_add(ans.mat[i][j], mod_mul(a.mat[i][k], b.mat[k][j]));
		return ans;
	}
};

Matrix<ll> mat_fexp(Matrix<ll> base, ll pot){
    // Matriz Identidade
    Matrix<ll> ans(base.n, base.m);
    FORi(base.n) { ans.mat[i][i] = 1; }

	while(pot) {
		if(pot & 1) { ans = ans * base; }
		base = base * base;
		pot >>= 1;
	}
	return ans;
}