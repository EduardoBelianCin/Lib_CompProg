#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FORi(n) for(int i=0;i<n;i++)
#define all(a) (a).begin(),(a).end()

void solve(){
    int n;
    cin>>n;
    
    vector<int> K(n);
    FORi(n) { cin>>K[i]; }

    ll max_area = 1LL * n * *min_element(all(K));
    stack<int> Stack_Mono;
    K.push_back(0);

    FORi(n+1) {
        while(!Stack_Mono.empty() && K[i] < K[Stack_Mono.top()]) {
            ll h = K[Stack_Mono.top()];
            Stack_Mono.pop();

            if(Stack_Mono.empty()) {
                max_area = max(max_area, h*i);
            }
            else {
                int largura = i -Stack_Mono.top() -1;
                max_area = max(max_area, h*largura);
            }
        }
        Stack_Mono.push(i);
    }
    cout << max_area << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}