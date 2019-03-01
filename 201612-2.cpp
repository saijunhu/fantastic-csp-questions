//
// Created by Saijun Hu on 2019-02-25.
//

#include <iostream>
using namespace std;

int levy_tax(int exceed){
    if(exceed<=1500) return exceed*0.03;
    else if(1500<exceed && exceed<=4500) return levy_tax(1500)+(exceed-1500)*0.1;
    else if(4500<exceed && exceed<=9000) return levy_tax(4500)+(exceed-4500)*0.2;
    else if(9000<exceed && exceed<=35000) return levy_tax(9000)+(exceed-9000)*0.25;
    else if(35000<exceed && exceed<=55000) return levy_tax(35000)+(exceed-35000)*0.3;
    else if(55000<exceed && exceed<=80000) return levy_tax(55000)+(exceed-55000)*0.35;
    else if(80000<exceed ) return levy_tax(80000)+(exceed-80000)*0.45;
}

int deducted_tax(int money){
    if(money<=3500) return money;
    else return money - levy_tax(money-3500);
}
int main(){
    int money;cin>>money;
    int begin=(money-money%100);
    for (int i = begin; i < 2*begin ;) {
        int d = deducted_tax(i);
        if(d==money) {
            cout<<i<<endl;break;
        }
        i+=100;
    }

    return 0;
}