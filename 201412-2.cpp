//
// Created by Saijun Hu on 2019/2/22.
//
//思路是，每次产生序列下个元素的坐标，注意到每次转向都发生在四条边界，于是可一一处理
#include <iostream>
using namespace std;

const int EAST=0;
const int SOUTH=1;
const int SOUTHWEST=2;
const int NORTHEAST=3;
int dx[] = {0,1,1,-1};
int dy[] = {1,0,-1,1};
int main(){
    int n,t;
    cin>>n;
    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>matrix[i][j];
        }
    }

    int row=0,col=0,next = EAST;
    cout<<matrix[row][col];
    while(row!=n-1 || col!=n-1){
        row += dx[next];
        col += dy[next];
        cout<<" "<<matrix[row][col];
        //the following order matters!!!
        if(next == EAST && row==0){
            next=SOUTHWEST;
        }else if(next==EAST && row==n-1){
            next=NORTHEAST;
        }else if(next== SOUTH && col==0){
            next=NORTHEAST;
        }else if(next==SOUTH && col==n-1){
            next = SOUTHWEST;
        }else if(next==SOUTHWEST && row==n-1){
            next =EAST;
        }else if(next==SOUTHWEST && col==0){
            next=SOUTH;
        }else if (next==NORTHEAST && col==n-1){
            next=SOUTH;
        }else if(next==NORTHEAST && row==0){
            next=EAST;
        }
    }
    cout<<endl;

    return 0;
}
