#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>

const int MAXN = 1001;

int n,m;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};

bool inRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs(){
    queue<pii> q;
    memset(vis, false, sizeof(vis));
    vis[0][0] = true;
    q.push({0,0});

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            int ax = x + dx[i], ay = y + dy[i];
            if(inRange(ax,ay) && !vis[ax][ay] && grid[ax][ay]!='#') {
                vis[ax][ay] = true;
                q.push({ax,ay});
            }
        }
    }
}