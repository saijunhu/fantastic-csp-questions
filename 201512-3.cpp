//
// Created by Saijun Hu on 2019-02-24.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int HENG=1;
const int SHU=2;
const int JIA=3;
int n,m,q;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
char paper[100][100];
int flag[100][100]={ {0} };


bool is_legal(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m&&(flag[x][y]==0);
}
void fill(int x,int y,char c,int visit[][100]){
    visit[x][y]=1;
    if(is_legal(x,y)) { paper[x][y]=c;}
    else{return;}
    for (int i = 0; i < 4; ++i) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(is_legal(nx,ny)&&!visit[nx][ny]) fill(nx,ny,c,visit);
    }
}

template <typename T>
void debug(T a[][100]){
    cout<<endl;
    for (int i = n-1; i >-1; --i) {
        for (int j = 0; j < m; ++j) {
           cout<<a[i][j];
        }
        cout<<endl;
    }
}
int main(){

    cin>>m>>n>>q;
    for (int k = 0; k < 100; ++k) {
        for (int i = 0; i < 100; ++i) {
            paper[k][i]='.';
        }
    }
    while(q--){
        int opt;cin>>opt;
        if(opt==0){//draw line
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2){
                if(y1>y2) swap(y1,y2);
                for(int i=y1;i<=y2;i++){
                    if(flag[i][x1]==JIA) continue;//一开始90分的原因，遗漏了三线相交的情况
                    if(flag[i][x1]==HENG){
                        flag[i][x1]=JIA;
                    }else{
                        flag[i][x1]=SHU;
                    }
                }
            }else{
                if(x1>x2) swap(x1,x2);
                for (int j = x1; j <= x2; ++j) {
                    if(flag[y1][j]==JIA) continue;
                    if(flag[y1][j]==SHU){
                        flag[y1][j]=JIA;
                    }else{
                        flag[y1][j]=HENG;
                    }
                }
            }
//            debug(flag);
        }
        if(opt==1){
            int x,y;
            char c;
            cin>>y>>x>>c;
            int visited[100][100]={{0}};
            fill(x,y,c,visited);
            paper[x][y]=c;
//            debug(flag);
//            debug(paper);
        }
    }
    for (int i = n-1; i >-1; --i) {
        for (int j = 0; j < m; ++j) {
            switch(flag[i][j]){
                case HENG:
                    cout<<'-';break;
                case SHU:
                    cout<<'|';break;
                case JIA:
                    cout<<'+';break;
                default:
                    cout<<paper[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}