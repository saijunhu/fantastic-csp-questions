//
// Created by Saijun Hu on 2019-02-28.
//

#include <iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int stalls[n+2];
    stalls[0]=0;stalls[n+1]=0;
    for (int i = 1; i <=n ; ++i) {
        cin>>stalls[i];
    }
    for (int i = 1; i <=n ; ++i) {
        if(i==1)
            cout<<(stalls[i-1]+stalls[i]+stalls[i+1])/2<<" ";
        else if(i==n)
            cout<<(stalls[i-1]+stalls[i]+stalls[i+1])/2<<" ";
        else
            cout<<(stalls[i-1]+stalls[i]+stalls[i+1])/3<<" ";
    }
    return 0;
}