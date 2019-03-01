//
// Created by Saijun Hu on 2019-02-24.
//

#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int sum=0;
    for (int i = 0; i < s.length(); ++i) {
        int t = static_cast<int>(s[i])-48;
        sum+=t;
    }
    cout<<sum<<endl;
    return 0;
}