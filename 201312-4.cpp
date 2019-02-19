//
// Created by Saijun Hu on 2019/2/19.
//

//数位dp，最关键的是分析清楚初始状态
//教程：https://blog.csdn.net/u014679804/article/details/48212289

#include <iostream>
typedef long long llt;
using namespace std;

llt dp[1001][6],n;
const llt mod = 1000000007;

int main(){
    cin>>n;
    //dp[i][j] 表示i位数中状态为j的数的数量
    for (llt i = 1; i <= n; ++i) {
        dp[i][0]=1;//{2}
        dp[i][1] = (2*dp[i-1][1]+dp[i-1][0])%mod;//{2,0}, 0/2 ,0
        dp[i][2] = (dp[i-1][2]+dp[i-1][0])%mod;//{2,3}, 3, 3
        dp[i][3] = (dp[i-1][1]+ 2*dp[i-1][3])%mod;//{2,0,1}, 1, 1/2
        dp[i][4] = (dp[i-1][1]+dp[i-1][2] + 2*dp[i-1][4])%mod; //{2,0,3}, 3, 0, 0/3
        dp[i][5] = (dp[i-1][3]+dp[i-1][4] + 2*dp[i-1][5])%mod;//{2,0,1,3}, 3, 1, 1/3

    };
    cout<<dp[n][5];
    return 0;
}
