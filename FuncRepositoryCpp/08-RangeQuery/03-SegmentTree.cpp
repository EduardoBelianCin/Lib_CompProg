#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// NÓ CUSTOMIZADO
struct Node { int freq = 0; ll soma = 0; };

template<typename T> struct SegTree {
    vector<T> Seg;
    int N;
    // Valor Neutro (Trocar de acordo com o Tipo da Seg)
    T NEUTRO = 2e9;

    SegTree(int n) { 
        N = 1; while(N < n) { N *= 2; }
        Seg.assign(N*2, NEUTRO);
    }
    SegTree(vector<T> &Lista) { 
        N = 1; while(N < Lista.size()) { N *= 2; }
        Seg.assign(N*2, NEUTRO); build(1, 0, N-1, Lista); 
    }
    // União da Seg (Trocar a Operação de acordo com o Tipo da Seg)
    T join(T lv, T rv) { return min(lv, rv); }

	T query(int no, int l, int r, int a, int b){
		if(b < l || r < a) { return NEUTRO; }
		if(a <= l && r <= b) { return Seg[no]; }
		int m = (l+r)/2, e = no*2, d = e+1;
		
		return join(query(e, l, m, a, b), query(d, m+1, r, a, b));
	}
	void update(int no, int l, int r, int pos, T v){
		if(pos < l || r < pos) { return; }
		// Se quiser fazer um update que soma, Altera aqui
		if(l == r) { Seg[no] = v; return; }
		int m = (l+r)/2, e = no*2, d = e+1;

		update(e, l, m, pos, v);
		update(d, m+1, r, pos, v);

		Seg[no] = join(Seg[e], Seg[d]);
	}
	void build(int no, int l, int r, vector<T> &Lista){
		if(l == r) {
            if(l < Lista.size()) { Seg[no] = Lista[l]; }
            else { Seg[no] = NEUTRO; }
            return;
        }
		int m = (l+r)/2, e = no*2, d = e+1;
		build(e, l, m, Lista);
		build(d, m+1, r, Lista);
		Seg[no] = join(Seg[e], Seg[d]);
	}

	T query(int ls, int rs) { return query(1, 0, N-1, ls, rs); }
	void update(int pos, T v) { update(1, 0, N-1, pos, v); }
};


int main() {
    vector<int> a = {5, 8, 2, 9, 3, 7};

    SegTree<int> Seg(a);

	// Query de 0 até 2
	Seg.query(0, 2);

	// Atualiza o idx 2 para 10
	Seg.update(2, 10);
}