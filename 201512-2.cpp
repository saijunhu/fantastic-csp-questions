//
// Created by Saijun Hu on 2019-02-24.
// 经过分析构造检验代码的特殊例子非常有必要，可以测试出哪个地方出了问题，精确修改
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int matrix[30][30]={{0}};
    int flag[30][30]={{0}};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int right=j;
            while(right<m && matrix[i][right]==matrix[i][j]) right++;
            if(right-j>=3) {
                while(j < right) { flag[i][j]=1; j++;}
                j--;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int right=j;
            while(right<n && matrix[right][i]==matrix[j][i]) right++;
            if(right-j>=3) {
                while(j < right) { flag[j][i]=1; j++;}
                j--;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m ; ++i) {
            if(!flag[k][i]){
                cout<<matrix[k][i]<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
