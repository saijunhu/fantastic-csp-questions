//
// Created by Saijun Hu on 2019/2/19.
//
#include<iostream>
#include <cstring>
using namespace std;
#define N 10001
int main(){
    int n,tmp;
    cin>>n;
    int bucket[N];
    memset(bucket,0,sizeof(bucket));
    while(n--){
        cin>>tmp;
        bucket[tmp]++;
    }
    int times=0,res;
    for(int i=10000;i>0;i--){
        if(bucket[i]>=times){
            times=bucket[i];res=i;
        }
    }
    cout<<res<<endl;
    return 0;
}
