//
// Created by Saijun Hu on 2019-02-23.
//

#include <iostream>
using namespace std;
bool is_leapyear(int y){
    return (y%4==0&&y%100) ||(y%400==0);
}
int main(){
    int y,d;
    int month[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
    cin>>y>>d;
    int mon=0,day=0,sum=0;
    if(is_leapyear(y)) month[2]=29;
    for (int i = 1; i <=12 ; ++i) {
        if(sum<d && sum+month[i]>=d) {
            mon=i;int j=1;
            while(j+sum<d) j++;
            day=j;
            cout<<mon<<endl;
            cout<<day<<endl;
        }
        sum+=month[i];
    }
    return 0;
}