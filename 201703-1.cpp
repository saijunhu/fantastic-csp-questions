//
// Created by Saijun Hu on 2019-02-26.
//
#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int cnt=0;int sum=0;
    for (int i = 0; i < n; ++i) {
        int t;cin>>t;
        sum+=t;
        if(sum>=k || (i==n-1&&sum<k)) { cnt++;sum=0;}
    }
    cout<<cnt<<endl;
    return 0;
}
