//
// Created by Saijun Hu on 2019-02-25.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> nums;
bool check(int i){
    int gt=0,lt=0;
    for (int j = 0; j < n; ++j) {
        if(nums[j]>nums[i]) gt++;
        if(nums[j]<nums[i]) lt++;
    }
    if(lt==gt) return true;
    return false;
}
int main(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int t;cin>>t;
        nums.push_back(t);
    }
    sort(nums.begin(),nums.end());
    int mid1=n/2,mid2=n/2+1;
    if(check(mid1)) { cout<<nums[mid1]<<endl;}
    else if(check(mid2)) { cout<<nums[mid2]<<endl;}
    else { cout<<-1<<endl;}
    return 0;
}
