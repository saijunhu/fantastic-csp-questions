//
// Created by Saijun Hu on 2019-02-26.
//
#include <iostream>
using namespace std;

int main(){
    int money;cin>>money;
    int cnt=0;
    int n = money/50;cnt+=n*7;
    int r = money%50;
    if(r/30!=0){
        cnt+=4;r=r%30;cnt+=(r/10);
    }else{ cnt+=(r/10);}
    cout<<cnt<<endl;
    return 0;
}