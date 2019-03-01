//
// Created by Saijun Hu on 2019-02-25.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n,ans=INT_MIN;
    cin>>n;
    vector<int > nums;
    while (n--){
        int t;cin>>t;
        nums.push_back(t);
    }

    for (int i = 0; i < nums.size()-1; ++i) {
        int t=abs(nums[i+1]-nums[i]);
        ans=max(t,ans);
    }
    cout<<ans<<endl;
    return 0;
}
