//
// Created by Saijun Hu on 2019/2/19.
//
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int pos=1,num,sum=0;
    for (int i = 0; i <s.length()-1 ; ++i) {
        if(s[i]=='-') continue;
        num = static_cast<int>(s[i])-48;
        sum+=num*pos;
        pos++;
    }
    char id_char;
    int id = sum%11;
    (id==10) ? id_char='X' : id_char='0'+id;
    if(s[12] == id_char ) {
        cout<<"Right"<<endl;
    }
    else{
        s.erase(s.length()-1,1);
        s+=id_char;
        cout<<s<<endl;
    }
    return 0;
}
