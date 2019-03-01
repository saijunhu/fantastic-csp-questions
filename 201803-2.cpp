//
// Created by Saijun Hu on 2019-02-28.
//

#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;
struct ball{
    int order,v,pos;
    ball(int o=0,int v=0,int p=0):order(o),v(v),pos(p){}
};

int main(){
    int n,l,t;
    cin>>n>>l>>t;
    vector<ball> balls;
    int lines[l+1];
    memset(lines,0, sizeof(lines));
    for (int i = 1; i <=n ; ++i){
        int t;cin>>t;
        balls.push_back(ball(i,1,t));
        lines[t]++;
    }

    for (int i = 1; i <= t ; ++i) {
        for (int j = 0; j < n; ++j) {
            auto tmp = balls[j];
            if(lines[tmp.pos]==2 ){
                for (int k=0;k<n;k++) {
                    if(balls[k].pos==tmp.pos) balls[k].v = -balls[k].v;
                }
            }else if(tmp.pos==0 || tmp.pos==l){
                balls[j].v = -tmp.v;
            }
            int np = tmp.pos + balls[j].v;
            lines[tmp.pos]--;
            lines[np]++;
            balls[j].pos = np;
        }
    }
    for(auto b: balls) cout<<b.pos<<" ";
    return 0;
}
