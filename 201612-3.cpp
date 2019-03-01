//
// Created by Saijun Hu on 2019-02-25.
// 本题一开始的错误点是int n = s.back();忘记了进行char to int的转换

#include <iostream>
#include <map>
#include <cctype>
#include <vector>

using namespace std;
map<string,int> items;
map<string,vector<pair<string,int>>> roles;
map<string,vector<string>> users;

string query(string user,string item,int level){
    //level=-1 means no param or is a no-param item
    int hi_level=-2;
    for(auto role: users[user]){
        for(auto it: roles[role]){
            if(it.first==item) hi_level=max(hi_level,it.second);
        }
    }
    if(hi_level==-2) return "false";
    if(level==-1 && hi_level==-1) return "true";
    if(level==-1 && hi_level>=0) return to_string(hi_level);
    if(level!=-1 && hi_level>=level) return "true";
    if (level!=-1 && hi_level<level) return "false";
}
int main(){
    int p;cin>>p;
    while(p--){
        string s;cin>>s;
        if(!isalpha(s[s.length()-1])){
            int n = static_cast<int>(s.back())-48;
            s.erase(s.length()-2,2);
            items[s]=n;
        }else{
            items[s]=-1;
        }
    }

    int r;cin>>r;

    while(r--) {
        string role;int n;
        cin>>role>>n;
        vector<pair<string,int>> v;
        for (int j = 1; j <= n; ++j) {
            string s;cin>>s;
            pair<string,int> tmp;
            if(!isalpha(s[s.length()-1])){
                int n = static_cast<int>(s.back())-48;
                s.erase(s.length()-2,2);
                tmp.first=s;tmp.second=n;
            }else{
                tmp.first=s;tmp.second=-1;
            }
            v.push_back(tmp);
        }
        roles[role]=v;
    }

    int u;cin>>u;
    while(u--) {
        string user;int n;
        cin>>user>>n;
        vector<string> v;
        for (int j = 1; j <= n ; ++j) {
            string s;cin>>s;
            v.push_back(s);
        }
        users[user]=v;
    }

    int q;cin>>q;
    while(q--){
        string user,item;int level;
        cin>>user>>item;
        if(isdigit(item.back())){
            level = static_cast<int>(item.back()) - 48;
            item.erase(item.length()-2,2);
        }else{
            level=-1;
        }
        cout<<query(user,item,level)<<endl;
    }

    return 0;
}
