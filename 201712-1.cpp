//
// Created by Saijun Hu on 2019-02-27.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> nums;
    while(n--){
        int t;cin>>t;
        nums.push_back(t);
    }
    int res=INT_MAX;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size()-1; ++i) {
        int sub = abs(nums[i]-nums[i+1]);
        res=min(sub,res);
    }

    cout<<res<<endl;
    return 0;
}

