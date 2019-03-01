//
// Created by Saijun Hu on 2019-02-23.
//

#include<iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> PAIR;
bool cmp(const PAIR& l,const PAIR& r){
    if(l.second > r.second) return true;
    if(l.second==r.second) return l.first < r.first;
    return false;
}

int main(){
    int n;
    map<int,int> m;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        m[t]++;
    }

    vector<PAIR> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    for (int i = 0; i < v.size() ; ++i) {
        auto t = v[i];
        cout<<t.first<<" "<<t.second<<endl;
    }
    return 0;
}
