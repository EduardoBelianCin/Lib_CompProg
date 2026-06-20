#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int dist[MAXN];

void bfs(int b){
    memset(dist, -1, sizeof(dist));
    dist[b] = 0;
    queue<int> q;
    q.push(b);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}