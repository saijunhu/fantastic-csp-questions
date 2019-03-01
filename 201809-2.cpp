//
// Created by Saijun Hu on 2019-02-28.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;cin>>n;
    int t=n;
    vector<pair<int,int>> h;
    vector<pair<int,int>> w;
    while(n--){
        int s,e;
        cin>>s>>e;
        h.push_back({s,e});
    }
    while(t--){
        int s,e;
        cin>>s>>e;
        w.push_back({s,e});
    }
    int cnt=0;
    for(auto a : h){
        for(auto b: w){
            if(a.first>=b.first && a.first<=b.second)
            {
                cnt += min(a.second,b.second)-a.first;
                continue;
            }
            if(b.first>=a.first && b.first<=a.second)
            {
                cnt += min(a.second,b.second)-b.first;
                continue;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
