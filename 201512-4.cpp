//
// Created by Saijun Hu on 2019-02-24.
// TODO 欧拉回路问题，不会，fluery 算法。学习代码尝试理解.判定是否存在欧拉路径的条件是：无向图的所有结点的出入度
//  均为偶数，或者有2个出入度为奇数的结点。满足这个条件的图，必然能够找到欧拉路径。由于是从结点1出发，
//  如果有2个出入度为奇数的结点，1的出入度必须为奇数。

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int degree[10001];
bool exist_arc[10001][10001];
int main(){
    int n,m,odd=0;
    vector<int> ans,v[10001];
    stack<int> stk;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int u,w;cin>>u>>w;
        v[u].push_back(w);
        v[w].push_back(u);
        degree[u]++;
        degree[w]++;
    }
    for (int i = 1; i <=n; ++i) {
        sort(v[i].begin(),v[i].end());
        if(degree[i]&1) odd++;//calcul the odd degree's vertex count
    }
    stk.push(1);
    while (!stk.empty()){
        int u = stk.top();
        bool flag=false;
        for (int i = 0; i < v[u].size(); ++i) {
            int w=v[u][i];
            if(!exist_arc[w][u]){
                flag=true;
                stk.push(w);
                exist_arc[u][w]=true;
                exist_arc[w][u]=true;
                break;
            }
        }
        if(!flag){
            ans.push_back(u);
            stk.pop();
        }
    }
    if(ans.size()==m+1&&(odd==0||(odd==2&&degree[1]&1))){
        for(int i=ans.size()-1;i>-1;--i) cout<<ans[i]<<" ";
    }else {cout<<-1<<endl;}
    return 0;
}