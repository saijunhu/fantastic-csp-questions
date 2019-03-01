//
// Created by Saijun Hu on 2019/2/21.
//
#include <iostream>
using namespace std;
int paper[100][100];
int paint(int x1,int y1,int x2,int y2){
    int cnt=0;
    for (int i = x1; i <x2 ; ++i) {
        for (int j = y1; j < y2; ++j) {
            if(paper[i][j]==0){
                cnt++;paper[i][j]=1;
            }
        }
    }
    return cnt;
}
int main(){
    int n,x1,y1,x2,y2,sum=0;
    cin>>n;
    while(n--){
        cin>>x1>>y1>>x2>>y2;
        sum+=paint(x1,y1,x2,y2);
    }
    cout<<sum<<endl;
    return 0;
}

