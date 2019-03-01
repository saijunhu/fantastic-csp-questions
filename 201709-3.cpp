//
// Created by Saijun Hu on 2019-02-27.
// TODO 文本处理问题，找规律

#include <iostream>
#include <string>
#include <map>
using namespace std;

int n,m;
string s,key;
map<string,string> json;
int state;//0 init; 1- ready to key;2- ready to value

void handle(string& s)
{
    for(int i = 0; s[i]; i++) {
        if(s[i] == '{') {
            if(state == 0) {
                key = "";
            } else {
//                cout << "map: " << t << " " << "OBJECT" << endl;
                json[key] = "OBJECT";
            }
            state = 1;
        } else if(s[i] == '}') {
            int j;
            for(j = (int)key.size() - 1; j >= 0; j--) {
                if(key[j] == '.')
                    break;
            }
            if(j >= 0)
                key = key.substr(0, j);
            else
                key = "";
        } if(s[i] == ':') {
            state = 2;
        } if(s[i] == ',') {
            state = 1;
        } if(s[i] == '"') {  // 双引号
            string tmp;
            for(i++; s[i]; i++) {
                if(s[i] == '\\')
                    tmp += s[++i];
                else if(s[i] == '"')    // 双引号
                    break;
                else
                    tmp += s[i];
            }
            if(state == 1) {
                if(key == "")
                    key = tmp;
                else
                    key += '.' + tmp;
                state = 2;
            } else if(state == 2) {
//                cout << "map: " << t << " " << "STRING " + tmp << endl;
                json[key] = "STRING " + tmp;
                int j;
                for(j = (int)key.size() - 1; j >= 0; j--) {
                    if(key[j] == '.')
                        break;
                }
                if(j >= 0)
                    key = key.substr(0, j);
                else
                    key = "";
                state = 1;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    getchar();
    state=0;
    while(n--){
        getline(cin,s);
        handle(s);
    }
    while(m--){
        cin>>s;
        cout<<(json[s]=="" ? "NOTEXIST" : json[s])<<endl;
    }
    return 0;
}




// 正则表达式处理的，不好懂，保留
//#include <iostream>
//#include <unordered_map>
//#include <sstream>
//#include <regex>
//using namespace std;
//unordered_map<string,string>ans;//存储键值对
//stringstream all;//按空格字符分割字符串
//bool DFS(string key){//递归处理函数
//    string value;
//    all>>value;//读取当前的值
//    if(value=="}")//是右括号
//        return false;//返回false，表示当前值对象已读取完毕
//    if(value=="{"){//是左括号
//        if(key!="")//键不是空字符串
//            ans[key]="{}";//该键对应的值是一个对象
//        while(DFS(key));//递归处理值对象
//    }else{
//        string v=value.substr(1,value.rfind('"')-1);//除去两端的无用字符后剩余的真正的字符串
//        if(value.back()==':')//末尾是:字符，表示该字符串是键
//            DFS((key=="")?v:(key+"."+v));//递归处理其值
//        else//该字符串是值
//            ans[key]=v;//将键和值映射起来
//    }
//    return true;
//}
//int main(){
//    int n,m;
//    scanf("%d%d%*c",&n,&m);
//    string s="";
//    while(n--){//将n行JSON文本读取到字符串s中
//        string line;
//        getline(cin,line);
//        s+=line;
//    }
//    s=regex_replace(s,regex(" "),"");//去掉s中所有的空格字符
//    s=regex_replace(s,regex("\\\\\""),"\"");//将两个连续的\"字符转换为单个"字符
//    s=regex_replace(s,regex("\\\\\\\\"),"\\");//将两个连续的\\字符转换为单个\字符
//    s=regex_replace(s,regex(","),", ");//在每个,字符后添加一个空格字符
//    s=regex_replace(s,regex(":"),": ");//在每个:字符后添加一个空格字符
//    s=regex_replace(s,regex("\\{")," { ");//在每个{字符左右均添加空格字符
//    s=regex_replace(s,regex("},?")," } ");//在每个}字符左右均添加空格字符
//    all<<s;//将字符串s送入all中按空格分割
//    DFS("");//递归处理
//    while(m--){//进行查询
//        cin>>s;
//        if(ans.find(s)==ans.end())
//            puts("NOTEXIST");
//        else if(ans[s]=="{}")
//            puts("OBJECT");
//        else
//            printf("STRING %s\n",ans[s].c_str());
//    }
//    return 0;
//}
