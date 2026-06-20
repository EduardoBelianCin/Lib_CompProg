#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define FORi(n) for(int i=0;i<n;i++)
#define all(a) (a).begin(),(a).end()

void solve() {
    int n; cin>>n;
    
    vector<pii> Momentos(n);
    int start,end;
    FORi(n) {
        cin>>start>>end;
        Momentos[i] = {start,end};
    }

    // SORT PELO QUE TERMINA PRIMEIRO
    auto f = [] (const auto &a, const auto &b) {
        if(a.second != b.second) { return a.second < b.second; }
        else { return a.first >= b.first; }
    };
    stable_sort(all(Momentos), f);

    // VERIFICA SE O PROXIMO DA FILA COMEÇA DEPOIS DO FIM DO ATUAL,
    // SE SIM ESCOLHE ELE E TESTA O PROXIMO...
    pii prev = {-1,-1};
    int qtd_max = 0;
    FORi(n) {
        pii atual = Momentos[i];
        if(atual.first >= prev.second) { prev = atual; qtd_max++; }
    }
    cout << qtd_max << "\n";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) { solve(); }
}

// OBS: Ficar atento que tem questões que não consideram que se pode assistir um evento que começa em X depois de um que terminou em X
// Nesses casos troca o >= por >