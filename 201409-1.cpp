//
// Created by Saijun Hu on 2019/2/21.
//

#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,tmp,cnt=0;
    cin>>n;
    set<int> s;
    while(n--){
        cin>>tmp;
        if(s.count(tmp-1)) cnt++;
        if(s.count(tmp+1)) cnt++;
        s.insert(tmp);
    }
    cout<<cnt<<endl;
    return 0;
}