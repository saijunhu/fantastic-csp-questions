//
// Created by Saijun Hu on 2019-02-23.
// 一开始只得了70分，要意识到不管有没有变量，{{}}都是要被删去的，而且将流作为一个整体效率更高
// 我的编译器确实有问题，在调试的时候，但是运行的时候没有好像。。。

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string instr,outstr;
    map<string,string> vars;

    cin.get();
    while (n--){
        string line;
        getline(cin,line);
        instr+=line+'\n';//作为整体的流处理
    }

    while(m--){
        string name,value;
        cin>>name;cin.get();
        getline(cin,value);
        vars[name]=value.substr(1,value.size()-2);
    }

    size_t pos,nextpos;
    while((pos=instr.find("{{ "))!=string::npos){
        nextpos=instr.find(" }}")+3;
        string var(instr.begin()+pos+3,instr.begin()+nextpos-3);
        outstr+=instr.substr(0,pos);
        instr=instr.substr(nextpos);
        string val=vars.count(var)?vars[var]:"";
        outstr+=val;
    }
    outstr+=instr;
    cout<<outstr<<endl;
    return 0;
}
