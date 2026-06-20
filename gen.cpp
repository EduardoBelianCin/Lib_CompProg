#include <bits/stdc++.h>
using namespace std;
#define printn(v,n) for(int i=0;i<n;i++) cout << v[i] << (i == n-1 ? "\n" : " ")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(int n){
    vector<int> V(n);
    for(int i=0;i<n;i++) { V[i] = uniform_int_distribution<int>(1,64)(rng); }

    cout << n << " 1\n";
    printn(V, n);

    int a = uniform_int_distribution<int>(1,n)(rng);
    int b = uniform_int_distribution<int>(1,n)(rng);

    if(a>b) { swap(a,b); }
    cout << a << " " << b << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t = uniform_int_distribution<int>(1,64)(rng);
    solve(t);
}