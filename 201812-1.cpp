//
// Created by Saijun Hu on 2019-02-28.
//
#include <iostream>
using namespace std;

int main(){
    int r,y,g;
    cin>>r>>y>>g;
    int times[4] = {0,r,y,g};
    int n;cin>>n;
    int cnt=0;
    while(n--){
        int t1,t2;
        cin>>t1>>t2;
        switch (t1){
            case 0:
                cnt+=t2;break;
            case 1:
                cnt += t2;break;
            case 2:
                cnt += t2+r;break;
            case 3:break;
            default:break;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
