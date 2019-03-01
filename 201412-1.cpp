//
// Created by Saijun Hu on 2019/2/21.
//

#include<iostream>
#include <map>
using namespace std;
int main(){
    int n,t;
    cin>>n;
    map<int,int> m;
    while(n--){
        cin>>t;
        m[t]++;
        cout<<m[t]<<" ";
    }
    return 0;
}