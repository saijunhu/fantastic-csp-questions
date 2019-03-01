//
// Created by Saijun Hu on 2019-02-26.
// emmm有点乱，，不会,,,好吧，又会了，当把思路涉及到设计cmp函数时，问题就解决了

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int FETCH = 0;
const int SET = 1;

struct oper{
    int time,key,state;
    oper(int state,int t,int k):state(state),time(t),key(k){}
};
bool cmp(const oper& a,const oper& b){
     if(a.time < b.time){ return true;}
     else if(a.time==b.time){
         if(a.state==FETCH && b.state==SET) return false;
         if(a.state==SET && b.state==FETCH) return true;
         if(a.key<b.key) return true;
         else return false;
     }else{return false;}

}
vector<oper> operations;

int main(){
    int n,k;cin>>n>>k;
    int box[n+1];
    for (int i = 1; i <= n; ++i) {
        box[i]=i;
    }

    while(k--){
        int w,s,d;cin>>w>>s>>d;
        operations.emplace_back(oper(FETCH,s,w));
        operations.emplace_back(oper(SET,s+d,w));
    }
    //
    sort(operations.begin(),operations.end(),cmp);
    for (auto op: operations) {
       int s = op.state;
       if(s==SET){
           for (int i = 1; i <=n ; ++i) {
               if(box[i]==-1) { box[i]=op.key; break;}
           }
       }else{//fetch
           for (int i = 1; i <=n ; ++i) {
               if(box[i]==op.key) {box[i]=-1;break;}
           }
       }
    }
    for (int i = 1; i <=n; ++i) {
        cout<<box[i]<<" ";
    }
    return 0;
}