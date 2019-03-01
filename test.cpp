//
// Created by Saijun Hu on 2019/2/19.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string line;
    while(getline(cin,line)){
        int sum=0,x;
        stringstream ss(line);
        while(ss>>x) sum+=x;
        cout<<sum<<"\n";
    }
    return 0;
}

