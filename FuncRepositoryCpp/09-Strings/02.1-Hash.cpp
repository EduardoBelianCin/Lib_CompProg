#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)
#define all(a) (a).begin(),(a).end()
#define printn(v,n) for(int i=0;i<n;i++) cout << v[i] << (i == n-1 ? "\n" : " ")

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q; cin>>n>>q;
    
    vector<int> A(n), B(n);
    FORi(n) { cin>>A[i]; }
    FORi(n) { cin>>B[i]; }

    vector<ll> Random(n);
    FORi(n) { Random[i] = rng(); }

    vector<ll> Pre_Hash_A(n+1, 0), Pre_Hash_B(n+1, 0);
    FORi(n) {
        Pre_Hash_A[i+1] = Pre_Hash_A[i] + Random[A[i]-1];
        Pre_Hash_B[i+1] = Pre_Hash_B[i] + Random[B[i]-1];
    }

    FORi(q) {
        int l,r,L,R; cin>>l>>r>>L>>R;

        ll soma_A = Pre_Hash_A[r] - Pre_Hash_A[l-1];
        ll soma_B = Pre_Hash_B[R] - Pre_Hash_B[L-1];

        if(soma_A == soma_B) { cout << "Yes\n"; }
        else { cout << "No\n"; }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    solve();
}