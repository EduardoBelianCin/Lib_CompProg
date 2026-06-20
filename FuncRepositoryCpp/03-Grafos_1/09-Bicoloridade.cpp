#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<bool> vis, color;

// Retorna True se for Bipartivel
bool dfs(int v){
    vis[v] = true;
    for(int u : adj[v]){
        if(!vis[u]) {
            color[u] = !color[v];
            if(!dfs(u)) { return false; }
        }
        else if(color[v] == color[u]) { return false; }
    }
    return true;
}
