//
// Created by Saijun Hu on 2019-02-28.
//

#include <iostream>
using namespace std;

int main(){
    int t,score=0,flag=1;
    while(cin>>t){
        if(t==0) break;
        if(t==1){
            score+=1;
            flag=1;
        }
        if(t==2){
            score+=flag*2;
            flag++;
        }

    }
    cout<<score<<endl;

    return 0;
}