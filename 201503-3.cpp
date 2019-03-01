//
// Created by Saijun Hu on 2019-02-23.
// 此题不太会写，学习，尤其是本题对函数的分析抽离很好
#include <iostream>
#include <vector>
using namespace std;
int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleapyear(int y){
    return (y%4==0&&y%100) || (y%400==0);
}
int sumdays(int begin_year,int end_year,int m){//
    int sumdays=0;
    while(begin_year<end_year){
        sumdays+=isleapyear(begin_year++)?366:365;
    }
    if(isleapyear(end_year)) month[2]=29;
    for (int i = 1; i < m; ++i) {
        sumdays+=month[i];
    }
    return sumdays;
}

int thisdaybyweek(int w,int c,int b){//第几个星期的日期数
    int day=1;
    while (w!=c){
        ++day;
        ++w;
        if(w==8) w=1;
    }
    return day+(b-1)*7;

}
int main(){

    int a,b,c,y1,y2;
    cin>>a>>b>>c>>y1>>y2;
    while(y1<=y2){
        int w = (sumdays(1850,y1,a)+2)%7;
        if(w==0) w=7;
        int day=thisdaybyweek(w,c,b);
        if(day>month[a]) printf("none\n");
        else printf("%d/%02d/%02d\n",y1,a,day);
        month[2]=28;
        ++y1;
    }
    return 0;
}


