//
// Created by Saijun Hu on 2019/2/20.
//
//可计层数的bfs
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
struct Node{
    int x,y;
    int seq_number;
    int counts;
    Node(int x,int y,int order,int counts):x(x),y(y),seq_number(order),counts(counts){}
};
vector<Node> v;
bool matrix[256][256];//Graph adjacent matrix
bool visitd[256];
bool isConnected(const Node& a,const Node& b,int r){
    return (ll)(a.x-b.x)*(a.x-b.x)+(ll)(a.y-b.y)*(a.y-b.y) <= (ll)r*r;
}
int main(){
    int n,m,k,r;
    cin>>n>>m>>k>>r;
    for (int i = 0; i < n+m; ++i) {
        int x,y;
        cin>>x>>y;
        v.push_back(Node(x,y,i,0));
    }
    for (int i = 0; i < n+m; ++i) {
        for (int j = 0; j < n+m ; ++j) {
            matrix[i][j] = isConnected(v[i],v[j],r);
        }
    }

    //bfs
    queue<Node> q;
    q.push(v[0]);
    int level_cnt=1,level=1;
    while(level_cnt>0){
        int next_level_cnt=0;
        for (int i = 0; i < level_cnt; ++i) {
            Node cur = q.front();
            q.pop();
            if(cur.seq_number==1){
                cout<<level-2<<endl;
                return 0;
            }
            int seq_num = cur.seq_number;
            int j=0;
            while(j<n+m){
                if(matrix[seq_num][j] && !visitd[j] && cur.counts<=k){
                    visitd[j]=true;
                    v[j].counts=(j>=n)?cur.counts+1: cur.counts;//confused
                    q.push(v[j]);
                    next_level_cnt++;
                }
                ++j;
            }
        }
        level_cnt = next_level_cnt;
        ++level;
    }
    return 0;
}
