#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define FORi(n) for(int i=0;i<n;i++)
#define all(a) (a).begin(),(a).end()

void solve() {
    int n,k;
    cin>>n>>k;
    
    vector<pii> Momentos(n);
    int start,end;
    FORi(n) {
        cin>>start>>end;
        Momentos[i] = {start,end};
    }

    auto f = [] (const auto &a, const auto &b) {
        if(a.second != b.second) { return a.second < b.second; }
        else { return a.first >= b.first; }
    };
    stable_sort(all(Momentos), f);

    multiset<int> Hora_Livre;
    FORi(k) { Hora_Livre.insert(-1); }
    int qtd_max = 0;
    FORi(n) {
        pii atual = Momentos[i];
        // Primeira pessoa Indisponivel
        auto Ub = Hora_Livre.upper_bound(atual.first);

        // Se tem alguem Disponivel
        if(Ub != Hora_Livre.begin()) {
            // Primeira pessoa Disponivel
            Ub = prev(Ub);
            Hora_Livre.erase(Ub);
            Hora_Livre.insert(atual.second);
            qtd_max++;
        }
    }
    cout << qtd_max << "\n";
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}