//
// Created by Saijun Hu on 2019-02-24.
// TODO DFS 有坑。。BFS的解法我倒是看懂了
// copy from bfs
#include <cstdio>
#include <queue>

#define MAXN 101
using namespace std;

int N, M, T;
int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool visited[MAXN][MAXN][300];
int start[MAXN][MAXN];
int ends[MAXN][MAXN];

struct Node {
    int x;
    int y;
    int g;
    Node(int x_, int y_, int g_) : x(x_), y(y_), g(g_) {}
};

bool legal(int n, int m) {
    return n>=1 && n<=N && m>=1 && m<=M;
}

int main() {
    scanf("%d%d%d", &N, &M, &T);
    for(int t=0; t<T; t++) {
        int r, c, a, b;
        scanf("%d%d%d%d", &r, &c, &a, &b);
        start[r][c] = a;
        ends[r][c] = b;
    }

    queue<Node> q;
    q.push(Node(1,1,0));
    visited[1][1][0] = true;

    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        if(top.x==N && top.y==M) {
            printf("%d", top.g);
            break;
        }
        for(int d=0; d<4; d++) {
            int nx = top.x + dirs[d][0];
            int ny = top.y + dirs[d][1];
            int ng = top.g + 1;
            if(legal(nx,ny) && (ng<start[nx][ny] || ng>ends[nx][ny]) && !visited[nx][ny][ng]) {
                visited[nx][ny][ng] = true;
                q.push(Node(nx,ny,ng));
            }
        }
    }
}
/* DFS waiting debug
#include <iostream>
#include <vector>

using namespace std;
int n,m;
//int graph[100][100];
bool visited[100][100][300];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int min_t=10000;
vector<pair<int,int>> danger[10000];

bool is_legal(int x,int y,int t){
    int flag=false;
    for (int i = 0; i < danger[t].size(); ++i) {
        if(danger[t][i].first==x && danger[t][i].second==y) flag=true;
    }
    if(!flag && x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}
void dfs(int x,int y,int t,bool visit[100][100][300]){
    visited[x][y][t]=true;
    if(x==n-1 && y==m-1) {
        cout<<"reach the end"<<endl;
        min_t=min(t,min_t);
        return;
    }
    for (int i = 0; i < 4 ; ++i) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(is_legal(nx,ny,t+1) && !visit[nx][ny][t+1]) dfs(nx,ny,t+1,visit);
    }
}
int main(){
    int d;
    cin>>n>>m>>d;
    while(d--){
        int r,c,a,b;
        cin>>r>>c>>a>>b;
        while(a<=b){
            danger[a].push_back(make_pair(r-1,c-1));
            a++;
        }
    }

    dfs(0,0,0,visited);
    cout<<min_t<<endl;
    return 0;
}
*/