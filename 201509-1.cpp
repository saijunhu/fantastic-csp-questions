//
// Created by Saijun Hu on 2019-02-23.
//

#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;int last=-1; int cur;int cnt=0;
    for (int i = 0; i <n ; ++i) {
        cin>>cur;
        if(cur!=last) cnt++;
        last=cur;
    }
    cout<<cnt<<endl;
    return 0;
}