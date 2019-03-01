//
// Created by Saijun Hu on 2019-02-24.

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> nums;
    cin>>n;
    while (n--){
        int t;
        cin>>t;
        nums.push_back(t);
    }
    int cnt=0;
    for (int i = 1; i < nums.size()-1; ++i) {
        if(nums[i]<nums[i-1]&&nums[i]<nums[i+1]) cnt++;
        if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
