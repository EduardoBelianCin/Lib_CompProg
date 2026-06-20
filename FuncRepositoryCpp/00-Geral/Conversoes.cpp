#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)
#define all(a) (a).begin(),(a).end()
#define printn(v,n) for(int i=0;i<n;i++) cout << v[i] << (i == n-1 ? "\n" : " ")

ll fexp(ll base, ll pot) {
    ll ans = 1;
    while(pot) {
        if(pot & 1) { ans = ans * base; }
        base = base * base;
        pot >>= 1;
    }
    return ans;
}

ll bin_str_to_ll(string& s) {
    ll x = 0; int tamanho = s.size();
    for(int i=0;i<tamanho;i++) { if(s[i]=='1') { x += (ll(1) << (tamanho-i-1)); } }
    return x;
}
string ll_to_str_bin(ll n) {
    if(n==0) { return "0"; }
    string res = "";
    int idx = 0;
    while(n > 0) {
        if(n & (ll(1) << idx)) { res = res + '1'; n -= (ll(1) << idx); }
        else { res = res + '0'; }
        idx++;
    }
    reverse(all(res));
    return res;
}

ll hex_str_to_ll(string& s) {
    ll x = 0; int tamanho = s.size();
    for(int i=0;i<tamanho;i++) {
        if(s[i] <= '9') {
            x += fexp(16, (tamanho-i-1)) * (s[i]-'0');
        }
        else {
            x += fexp(16, (tamanho-i-1)) * (s[i]-'a'+10);
        }
    }
    return x;
}
string ll_to_str_hex(ll n) {
    if(n==0) { return "0"; }
    string res = "";
    while(n > 0) {
        int d = n%16;
        if(d < 10) { res += '0'+d; }
        else { res += 'a'+d-10; }
        n /= 16;
    }
    reverse(all(res));
    return res;
}

void solve() {
    string s,tipo; cin>>s>>tipo;

    if(tipo == "bin") {
        ll V = bin_str_to_ll(s);
        cout << V << " dec\n";
        cout << ll_to_str_hex(V) << " hex\n";
    }
    else if(tipo == "dec") {
        ll V = stoll(s);
        cout << ll_to_str_hex(V) << " hex\n";
        cout << ll_to_str_bin(V) << " bin\n";
    }
    else if(tipo == "hex") {
        ll V = hex_str_to_ll(s);
        cout << V << " dec\n";
        cout << ll_to_str_bin(V) << " bin\n";
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);

    int x = 0;
    int t; cin>>t; while(x<t) {
        cout << "Case " << x+1 << ":\n";
        solve();
        cout << "\n";
        x++;
    }
}