/*
5 4
0 0 0 0 
255 0 0 0
255 255 255 0
0 255 0 255
0 0 0 0 
1 1
4 3
--------
5 4
0 0 0 0 
255 0 0 0 
255 255 255 0
0 255 0 0 
0 0 0 0
0 0 
4 3
两点之间的最短距离，使用bfs模板
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e3 + 10;
int dist[N][N], s[N][N], st[N][N];

PII start, ed;
int m, n;

void bfs(){
    
    memset(dist, 0x3f, sizeof dist);
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    queue<PII> q;
    q.push(start);
    
    dist[start.first][start.second] = 0;
    st[start.first][start.second] = 1;
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i ++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a < 0 || a >= m || b < 0 || b >= n) continue;
            if(s[a][b] == 255 || st[a][b]) continue;
            
            dist[a][b] = dist[t.first][t.second] + 1;
            st[a][b] = 1;
            if(a == ed.first && b == ed.second) return;
            q.push({a, b});
        }
    }
}

int main(){
    
    
    cin >> m >> n;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++) cin >> s[i][j];
    }
    
    cin >> start.first >> start.second;
    cin >> ed.first >> ed.second;
    
    bfs();
    cout << ed.first << ' ' << ed.second << endl;
    if(dist[ed.first][ed.second] == 0x3f3f3f3f) cout << -1 << endl;
    else cout << dist[ed.first][ed.second] << endl;
    
    
    return 0;
}
