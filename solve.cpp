#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)

const int INF = 2e9;

int Bits(int n) {
    int sz = 1;
    while(n>1) {
        n = (n + 2 - 1) / 2;
        sz++;
    }
    return sz;
}

int query(int no, int l, int r, int lq, int rq, vector<int>& Minimos) {
    if(rq < l || r < lq) { return INF; }
    if(lq <= l && r <= rq) { return Minimos[no]; }

    int m = (l+r)/2;
    int e = no*2;
    int d = no*2 + 1;

    return min(query(e, l, m, lq, rq, Minimos), query(d, m+1, r, lq, rq, Minimos));
}

void solve() {
    int n,q; cin>>n>>q;
    
    int H = Bits(n);
    int size_A = (1 << H-1);
    vector<int> A(size_A, INF);
    FORi(n) { cin>>A[i]; }

    vector<int> Minimos((1 << H), INF);

    for(int j=H;j>0;j--) {
        int start = (1 << j-1);
        for(int i=start;i<start*2;i++) {
            if(j==H) { Minimos[i] = A[i-start]; }
            else { Minimos[i] = min(Minimos[2*i], Minimos[2*i+1]); }
        }
    }

    FORi(q) {
        int a,b; cin>>a>>b;

        cout << query(1,1,size_A, a,b, Minimos) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    solve();
}