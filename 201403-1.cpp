//
// Created by Saijun Hu on 2019/2/20.
//

#include <iostream>
#include <set>
using namespace std;

int main(){
    int N,tmp,cnt;
    cin>>N;
    set<int> s;
    while(N--){
        cin>>tmp;
        if(s.count(-tmp)) cnt++;
        s.insert(tmp);
    }
    cout<<cnt<<endl;
    return 0;
}