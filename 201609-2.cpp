//
// Created by Saijun Hu on 2019-02-25.
// TODO 90分原因，20个人买了三张票，第二十一个人买3张票，啊？还没有对？我已经改过了还不是100.
// ..以后再看

#include <iostream>
#include <map>
#include <vector>

using namespace std;
//int seats[21][6];
map<int,int> m;
vector<pair<int,int>> arrange(int n) {
    vector<pair<int, int>> ans;
    int line = 0;
    for (auto iter=m.begin();iter!=m.end();++iter) {
        auto e= *iter;
        if (e.second >= n) {
            int i = 1;
            while (i <= n) {
                ans.push_back(make_pair(line, 5 - e.second + i));
                i++;
            }
            iter->second= e.second-n;
            break;
        }
        if(line==20 && e.second<n){//90->100改进点，
            int pad_line=0;
            for (auto iter=m.begin();iter!=m.end();++iter){
                auto e= *iter;
                if(e.second>0 && n>0){
                    int i = 1;
                    while (i <= n && iter->second>0) {
                        ans.push_back(make_pair(pad_line, 5 - e.second + i));
                        i++;
                        iter->second--;
                        n--;
                    }
                }
                pad_line++;
            }

        }
        line++;
    }
    return ans;
}
int main(){
    int n;cin>>n;
    m[0]=0;
    for (int i = 1; i <= 20; ++i) {
        m[i]=5;
    }
    while (n--){
        int t;cin>>t;
        auto v=arrange(t);
        for (auto e : v) {
            cout<<(e.first-1)*5+e.second<<" ";
        }
        cout<<endl;
    }
    return 0;
}