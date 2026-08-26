#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)

/**
 * pi[i] armazena o tamanho do MAIOR prefixo próprio de s[0..i] 
 * que também é um sufixo dessa mesma substring s[0..i].
 * 
 * - Complexidade: O(N) em tempo e O(N) em memória.
 * - Aplicações principais:
 *   1. Busca de padrão em texto (KMP matching).
 *   2. Identificação do menor período cíclico: 
 *      k = N - pi[N - 1] (periódico se N % k == 0).
 *   3. Contagem de prefixos distintos e compressão de strings.
 */

vector<int> Pi(string &s) {
    int n = s.size();
    vector<int> pi(n, 0);

    for(int i=1;i<n;i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) { j = pi[j-1]; }
        if(s[i] == s[j]) { j++; }
        pi[i] = j;
    }
    return pi;
}

// ENCONTRA O MENOR PREFIXO QUE PODE SER REPETIDO
// PRA GERAR A STRING INTEIRA

void solve() {
    string s; cin>>s;
    int n = s.size();

    vector<int> PiArray = Pi(s);

    int k = n - PiArray[n-1];
    if(n%k == 0) {
        // n/k repetições da substring
        cout << n/k << "\n" << s.substr(0, k) << "\n";
    }
    else {
        cout << "1\n" << s << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    solve();
}