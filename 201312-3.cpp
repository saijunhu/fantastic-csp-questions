//
// Created by Saijun Hu on 2019/2/19.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
//此题的哨兵使用堪称经典，通过引入头尾哨兵极大简化了编程
int main(){
    int n;
    cin>>n;
    int j=n;
    vector<int> nums;
    while(j--){
        int tmp;cin>>tmp;
        nums.push_back(tmp);
    }
    nums.push_back(0);
    stack<int> s;
    int max_area=0;
    int i=0;
    while(i<=n){
        if(s.empty() || nums[s.top()] <= nums[i]){
            s.push(i++);
        }else{
            int h = s.top();
            s.pop();
            if(s.empty()){
                max_area=max(max_area,nums[h]*i);
            }else{
                max_area=max(max_area,nums[h]*(i-s.top()-1));
            }
        }
    }
    cout<<max_area<<endl;
    return 0;
}