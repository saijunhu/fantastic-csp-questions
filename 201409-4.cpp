//
// Created by Saijun Hu on 2019/2/21.
//
//TODO 直接一开始将所有开始点入队，bfs即可，不能一个一个的bfs，用queue的bfs

#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
struct node{
    int x,y;
    ll dis;
    node(int x,int y,int dis):x(x),y(y),dis(dis){}
};
queue<node> q;
int weight[1024][1024];
bool visited[1024][1024];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,k,m,d;
bool isLegal(int x,int y){
    return x>=1 && x<=n && y>=1 && y<=n && !visited[x][y];
}
int main(){
    cin>>n>>k>>m>>d;
    for (int i = 0; i < k; ++i) {
        int x,y;
        cin>>x>>y;
        q.push(node(x,y,0));
        visited[x][y]=true;
    }
    for (int j = 0; j < m; ++j) {
        int x,y,nums;
        cin>>x>>y>>nums;
        weight[x][y]=nums;
    }
    for (int l = 0; l < d; ++l) {
        int x,y;
        cin>>x>>y;
        visited[x][y]=true;
    }
    ll ans=0;
    while(!q.empty()){
        node cur = q.front();q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = cur.x+dx[i];
            int y = cur.y+dy[i];
            int dis = cur.dis;
            if(isLegal(x,y)){
                q.push(node(x,y,dis+1));
                visited[x][y]=true;
                ans+=weight[x][y]*(dis+1);
            }
        }
    }
    cout<<ans;
    return 0;
};
