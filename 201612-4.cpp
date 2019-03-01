//
// Created by Saijun Hu on 2019-02-26.
// TODO 不会，是个石子问题，动态规划思想，设dp[i][j]为合并的最小代价，sum[i][j]为
// 第i堆到第j堆的石子的总数量，代码又进行了四边形优化，学习 。转移方程为：
// 1、dp[i][j]=0 (i==j)
// 2、dp[i][j]=min(dp[i][k]+dp[k][j])+sum[i][j] (i!=j)
// 最后我的代码飘超时。


#include <iostream>
#include <cstring>

using namespace std;
const int N=1000;
const int INT_MAX2=0x7F7F7F7F;

int stones[N+1];
int sum[N+1];
int dp[N+1][N+1];

int solve(int l,int r){
    if(dp[l][r]==INT_MAX2){
        for (int i = l; i < r; ++i) {
            dp[l][r] = min(dp[l][r], solve(l, i) + solve(i+1, r) + sum[r] - sum[l-1]);
        }
    }
    return dp[l][r];
}

int main(){
    int n;
    memset(dp,INT_MAX2, sizeof(dp));
    cin>>n;
    sum[0]=0;
    for (int i = 1; i <=n; ++i) {
        cin>>stones[i];
        //init the sum and dp
        sum[i]=sum[i-1]+stones[i];
        dp[i][i]=0;
    }
    solve(1,n);
    cout<<dp[1][n]<<endl;
    return 0;
}
