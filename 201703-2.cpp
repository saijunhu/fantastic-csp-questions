
//
// Created by Saijun Hu on 2019-02-26.
//

#include <iostream>
#include <list>
#include <iterator>

using namespace std;
list<int> queue;
list<int>::iterator find_person(int x){
    for (auto it = queue.begin(); it!=queue.end() ; ++it) {
        if(*it==x) return it;
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for (int i = 1; i <= n; ++i) {
        queue.push_back(i);
    }
    while(m--){
        int p,q;cin>>p>>q;
        //adjust
        auto begin = queue.begin();
        auto end = queue.end();
        auto it = find_person(p);
        if(q<0){
            int order=*it;
            auto tmp=it;
            if(q< -distance(begin,tmp) ) q=distance(begin,tmp);
            advance(tmp,q);
            queue.insert(tmp,order);
            queue.erase(it);
        }else{
            int order=*it;
            auto tmp=it;
            if(q>distance(tmp,end)) q=distance(tmp,end);
            q=q+1;
            advance(tmp,q);
            queue.insert(tmp,order);
            queue.erase(it);
        }
    }
    for (auto it=queue.begin();it!=queue.end();++it) {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}