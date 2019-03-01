//
// Created by Saijun Hu on 2019-02-24.
//
#include <iostream>
#include <vector>

using namespace std;
int paper[15][10];
int block[4][4];
int main(){
    vector<pair<int,int>> points;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            cin>>paper[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4 ; ++j) {
            int t;cin>>t;
            if(t==1) points.push_back(make_pair(i,j));
        }
    }
    int offset;cin>>offset;
    int distance=16;
    for (int i = 0; i < 4; ++i) {
        int row=points[i].first;
        int col=points[i].second+offset-1;
        points[i].second=col;
        int dis=3-row;
        for(int j=3;j<15;j++) {
            if(paper[j][col]==1) break;
            dis++;
        }
        distance=min(distance,dis);
    }
    distance--;
    for (int i = 0; i < 4; ++i) {
        paper[points[i].first+distance][points[i].second]=1;
    }
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout<<paper[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
