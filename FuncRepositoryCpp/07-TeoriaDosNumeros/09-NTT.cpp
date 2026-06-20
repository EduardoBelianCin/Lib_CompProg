#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int G = 3; // Raiz primitiva para o MOD 998244353

ll fexp(ll base, ll pot) {
	ll ans = 1;
	while(pot) {
		if(pot & 1) { ans = ans * base % MOD; }
		base = base * base % MOD;
		pot >>= 1;
	}
	return ans;
}

// Algoritmo NTT (Number Theoretic Transform)
void ntt(vector<ll>& a, bool invert) {
    int n = a.size();
    
    // Inversão de bits (Bit-reversal permutation)
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    
    // Borboleta do NTT (Butterfly operation)
    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = fexp(G, (MOD - 1) / len);
        if (invert) wlen = fexp(wlen, MOD - 2); // Inverso modular
        
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j];
                ll v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v < MOD ? u + v : u + v - MOD);
                a[i + j + len / 2] = (u - v >= 0 ? u - v : u - v + MOD);
                w = (w * wlen) % MOD;
            }
        }
    }
    
    // Se for a NTT Inversa, divide pelo tamanho do vetor N
    if (invert) {
        ll n_inv = fexp(n, MOD - 2);
        for (ll& x : a) {
            x = (x * n_inv) % MOD;
        }
    }
}

// Multiplica dois polinômios usando NTT e limita o tamanho ao N_alvo
vector<ll> multiply(vector<ll> a, vector<ll> b, int max_degree) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    
    a.resize(n, 0);
    b.resize(n, 0);
    
    ntt(a, false);
    ntt(b, false);
    
    for (int i = 0; i < n; i++) {
        a[i] = (a[i] * b[i]) % MOD;
    }
    
    ntt(a, true);
    
    // Corta o polinômio para não carregar graus desnecessários maiores que N
    if (a.size() > max_degree + 1) {
        a.resize(max_degree + 1);
    }
    return a;
}

// Exponenciação Binária de Polinômios: Eleva P(x) à potência D
vector<ll> poly_pow(vector<ll> P, ll D, int max_degree) {
    // Começa com o polinômio identidade: 1 (ou seja, 1 * x^0)
    vector<ll> res = {1}; 
    
    while (D > 0) {
        if (D % 2 == 1) {
            res = multiply(res, P, max_degree);
        }
        P = multiply(P, P, max_degree);
        D /= 2;
    }
    return res;
}



int main() {
    // Exemplo do problema:
    // P(x) = x^1 + x^3 + x^4 + x^6
    // Representação por coeficientes: índice é o expoente
    // P[0]=0, P[1]=1 (x^1), P[2]=0, P[3]=1 (x^3), P[4]=1 (x^4), P[5]=0, P[6]=1 (x^6)
    vector<ll> P = {0, 1, 0, 1, 1, 0, 1};
    
    ll D = 2;   // 2 dias
    int N_alvo = 7;    // Queremos saber de quantas formas somamos 7 ienes
    
    // Calcula P(x)^D limitando o polinômio resultante ao grau N_alvo
    vector<ll> resultado = poly_pow(P, D, N_alvo);
    
    // O coeficiente no índice N_alvo é a nossa resposta
    if (N_alvo < resultado.size()) {
        cout << "Formas de conseguir " << N_alvo << " ienes em " << D << " dias: " << resultado[N_alvo] << endl;
    } else {
        cout << "Formas de conseguir " << N_alvo << " ienes em " << D << " dias: 0" << endl;
    }
    
    return 0;
}