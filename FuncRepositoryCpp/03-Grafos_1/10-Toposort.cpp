#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>

const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int deg[MAXN];

vector<int> toposort(int n) {
    memset(deg, 0, sizeof(deg));

    for(int u=1;u<=n;u++) {
        for(int v : adj[u]) { deg[v]++; }
    }

    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(deg[i] == 0) { q.push(i); }
    }

    vector<int> ord;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ord.push_back(u);
        for(int v : adj[u]) {
            deg[v]--;
            if(deg[v] == 0) { q.push(v); }
        }
    }

    // se ord.size() < n, não há ordenação possível!
    return ord;
}




// edges redundantes

vector<int> toposort_old(vector<pii>& edges, int& n){
    memset(deg, 0, sizeof(deg));

    for(auto [u,v] : edges) {
        deg[v]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(deg[i] == 0) { q.push(i); }
    }

    vector<int> ord;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ord.push_back(u);
        for(int v : adj[u]) {
            deg[v]--;
            if(deg[v] == 0) { q.push(v); }
        }
    }

    // se ord.size() < n, não há ordenação possível!
    return ord;
}