//
// Created by Saijun Hu on 2019-02-28.
// 不太会，先以正则表达式作为学习例子,通过，作为案例吧

#include <iostream>
#include <regex>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<string,regex>> rules;
    vector<pair<regex,string>> trans = {
            {regex("<int>"),"([0-9]+)"},{regex("<str>"),"([^/]+)"},
            {regex("<path>"),"(.+)"}
    };
    string p,r;
    while(n--){
       cin>>p>>r;
       //此处使用正则表达式来生成正则表达式，非常棒
       for(auto& i: trans) p=regex_replace(p,i.first,i.second);
       rules.push_back({r,regex(p)});
    }
    smatch results;//smatch可以理解为regex_match结果的迭代器
    while(m--){
        cin>>p;
        for(auto i:rules){
            if(regex_match(p,results,i.second)){
                cout<<i.first<<" ";
                for (int i = 1; i <= results.size(); ++i) {
                    p = results.str(i);
                    while(p[0]=='0') p.erase(0,1);
                    cout<<p<<" ";
                }
                cout<<endl;
                goto loop;
            }
        }
        cout<<"404"<<endl;
        loop:;
    }
    return 0;
}