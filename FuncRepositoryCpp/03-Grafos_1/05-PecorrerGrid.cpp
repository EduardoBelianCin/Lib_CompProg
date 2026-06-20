#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 7;
int n,m;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
char grid[MAXN][MAXN];

bool valid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#';
}

void rec(int x, int y){
    grid[x][y] = '#'; // Se for usar grid depois usar uma matriz de visitas (bool)
    for(int d=0;d<4;d++) {
        int ax = x + dx[d], ay = y + dy[d];
        if(!valid(ax,ay)) { continue; }
        rec(ax,ay);
    }
}
