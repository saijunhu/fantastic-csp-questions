//
// Created by Saijun Hu on 2019/2/21.
//

#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int case_sensitive_flag;
    string pattern_str;
    int n;
    cin>>pattern_str;
    cin>>case_sensitive_flag;
    cin>>n;
    string str;
    while(n--){
        cin>>str;
        string str_2=str,pattern_str_2=pattern_str;
        if(!case_sensitive_flag){
            str_2=str;pattern_str_2=pattern_str;
            std::transform(str_2.begin(),str_2.end(),str_2.begin(),::tolower);
            std::transform(pattern_str_2.begin(),pattern_str_2.end(),pattern_str_2.begin(),::tolower);
        }
        auto n = str_2.find(pattern_str_2);
        if(n!=string::npos){
            cout<<str<<endl;
        }
    }
    return 0;
};
