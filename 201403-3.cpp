//
// Created by Saijun Hu on 2019/2/20.
// 此题解答的巧妙之处在于，一开始用map把参数分为有参和无参两种，
// 后用map来保存但参数函数的参数，并且自动排序，

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

map<char, int> op;//sort up the params
map<string, string> res;
int whatis(string str){
    if(str.size()==2 && str[0]=='-'){
        return op[str[1]];
    }
    return 0;
}
void analyse(string line){
    string str,tmp;
    res.clear();
    stringstream ss(line);
    ss>>str;//skip the first command;
    while(ss>>str){
        switch (whatis(str)){
            case 1://no params
                res[str]="";break;
            case 2://have params
                if(ss>>tmp){
                    res[str]=tmp;
                }else{//the format is wrong,just return
                    return;
                }
                break;
            default: return;
        }
    }
}

int main(){

    int N;
    string tmp;
    cin>>tmp;
    //analyse the pattern string ,sort up the params
    for (int i = 0; i < tmp.size(); ++i) {
        if(tmp[i+1]==':'){
            op[tmp[i]]=2;
            i++;
        }else{
            op[tmp[i]]=1;
        }
    }
    cin>>N;
    getchar();
    for (int j = 0; j < N; ++j) {
        getline(cin,tmp);//
        analyse(tmp);
        //output
        cout<<"Case "<<j+1<<":";
        for(auto iter=res.begin();iter!=res.end();iter++){
            cout<<" "<<iter->first;
            if(iter->second!="") cout<<' '<<iter->second;
        }
        cout<<endl;
    }
    return 0;
}