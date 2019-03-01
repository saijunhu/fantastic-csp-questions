//
// Created by Saijun Hu on 2019-02-23.
// MST problem,use the Kruskal，MST例题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{
    int start,end,weight;
    edge(int s,int e,int w):start(s),end(e),weight(w){}
};
int N,M;
vector<edge> edges;
vector<int>p;
vector<int>r;

int cmp(const int i,const int j){ return edges[i].weight < edges[j].weight;}
int find(int x){ return p[x]==x ? x : p[x]=find(p[x]);}//Union-Find's find

int kruskal(){
    int ans = 0;
    for (int i = 0; i < N; ++i) p.push_back(i);//初始化并查集
    for (int j = 0; j < M; ++j) r.push_back(j);//初始化边序号
    sort(r.begin(),r.end(),cmp);//给边排序，权重由小到大
    for (int i = 0; i < M; ++i) {
        int e = r[i];
        int x = find(edges[e].start);//找出边的端点所在的集合
        int y = find(edges[e].end);
        if(x!=y){ ans+= edges[e].weight; p[x]=y;}//如果在不同集合，合并，并累加权值
    }
    return ans;
}
int main(){
    cin>>N>>M;
    int i=M;
    while(i--){
        int v1,v2,weight;
        cin>>v1>>v2>>weight;
        edge e = edge(v1-1,v2-1,weight);
        edges.push_back(e);
    }
    cout<<kruskal()<<endl;
    return 0;
}

