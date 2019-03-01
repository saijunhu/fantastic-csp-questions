//
// Created by Saijun Hu on 2019-02-23.
//

#include<iostream>
using namespace std;
int matrix[1024][1024];
int main(){
    int m,n;
    cin>>m>>n;
    for (int i = 0; i < m ; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>matrix[i][j];
        }
    }
    for (int i = n-1; i > -1 ; --i) {
        for (int j = 0; j < m; ++j) {
            cout<<matrix[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}