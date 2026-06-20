#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)
#define all(a) (a).begin(),(a).end()

const int INF = 2e9;

void solve(){
    int n,q; cin>>n>>q;
    
    vector<int> A(n);
    FORi(n) { cin>>A[i]; }

    FORi(q) {
        int a,b; cin>>a>>b;

        int Minimo = INF;
        for(int j=a-1;j<b;j++) { Minimo = min(Minimo, A[j]); }
        cout << Minimo << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    solve();
}