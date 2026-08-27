#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)
#define all(a) (a).begin(),(a).end()
#define printn(v,n) for(int i=0;i<n;i++) cout << v[i] << (i == n-1 ? "\n" : " ")

const int MAXN = 1e5 + 7;
vector<int> adj[MAXN];

void solve() {
    int n,m; cin>>n>>m;
    
    vector<int> A(n);
    FORi(n) { cin>>A[i]; }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    // cout << fixed << setprecision(9); ************************

    int t; cin>>t; FORi(t) { solve(); }
}