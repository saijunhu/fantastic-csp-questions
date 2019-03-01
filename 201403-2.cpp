//
// Created by Saijun Hu on 2019/2/20.
//
#include <iostream>
#include <sstream>
#include <list>
#include <map>
using namespace std;

struct Rec{
    int x1,y1,x2,y2,order;
    Rec(int x1=0,int y1=0,int x2=0,int y2=0,int order=0):x1(x1),y1(y1),x2(x2),y2(y2),order(order){}
    bool operator== (const Rec& r2) const{
        return x1==r2.x1 && y1==r2.y1 && x2==r2.x2 && y2==r2.y2;
    }
};
struct Point{
    int x,y;
    Point(int x, int y):x(x),y(y){}
};
int N,M;
list<Rec> windows;
bool inRec(Rec rec,Point point){
    if(point.x>=rec.x1 && point.x<=rec.x2
       && point.y >= rec.y1 && point.y <=rec.y2){
        return true;
    }
    else{ return false;}
}
string simulate(Point point){
    int i=1;int cur_layer=0;
    Rec target_rec;
    for(auto iter = windows.begin();iter!=windows.end();++iter){
        if(inRec(*iter,point)) {
            cur_layer=i;
            target_rec=*iter;
        }
        i++;
    }
    if(cur_layer==0){ return "IGNORED";}
    else{
        //bring this window to front
        windows.remove(target_rec);
        windows.push_back(target_rec);
        return to_string(target_rec.order);
    }

}

int main(){

    cin>>N>>M;
    string line;int x1,y1,x2,y2;
    for(int i=0;i<=N;i++) {
        getline(cin, line);
        stringstream ss(line);
        ss >> x1 >> y1 >> x2 >> y2;
        Rec rec(x1, y1, x2, y2,i);
        windows.push_back(rec);
    }
    windows.pop_front();
    int j=M;int x,y;
    while(j--) {
        getline(cin, line);
        stringstream ss(line);
        ss >> x >> y;
        Point p(x,y);
        cout << simulate(p) << endl;
    }
    return 0;
}


