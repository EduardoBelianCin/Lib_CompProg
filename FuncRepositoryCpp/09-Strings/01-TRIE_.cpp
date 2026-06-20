#include <bits/stdc++.h>
using namespace std;

// Memória: O(N * log(ALPHA) + M)
// Tempo: O((N + M) * log(ALPHA))


// Podemos lidar com mais letras além de a..z
const int ALPHA = 26;

// Ex: maiusculas e minusculas
int idx_trie(char c) {
    if('a' <= c && c <= 'z') { return c-'a'; }
    else if('A' <= c && c <= 'Z') { return c-'A' + 26; }
}

// nxt = proximos pontos que vem desse atual
// pref_qtd = quantas strings tem aquele prefixo
// str_qtd = quantas strings terminam ali
struct Node { int nxt[ALPHA] {}; int pref_qtd = 0; int str_qtd = 0; };

struct TRIE {
    vector<Node> tr;

    TRIE() : tr(1) {}

    void add_palavra(string s) {
        int cur = 0;

        for(char c : s) {
            int pos = c - 'a';
            if(tr[cur].nxt[pos] == 0) {
                int len = tr.size();
                tr[cur].nxt[pos] = len;
                tr.emplace_back();
            }

            tr[cur].pref_qtd += 1;
            cur = tr[cur].nxt[pos];
        }
        tr[cur].pref_qtd += 1;
        tr[cur].str_qtd += 1;
    }
    int query_prefix(string s) {
        int cur = 0;

        for(char c : s) {
            int pos = c - 'a';
            if(tr[cur].nxt[pos] == 0) { return 0; }
            cur = tr[cur].nxt[pos];
        }
        return tr[cur].pref_qtd;
    }
    int query_palavras(string s) {
        int cur = 0;

        for(char c : s) {
            int pos = c - 'a';
            if(tr[cur].nxt[pos] == 0) { return 0; }
            cur = tr[cur].nxt[pos];
        }
        return tr[cur].str_qtd;
    }
};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    TRIE Trie;
    Trie.add_palavra("mesa");
    Trie.add_palavra("mesada");
    Trie.add_palavra("casebre");
    Trie.add_palavra("casa");
    Trie.add_palavra("casaco");
}