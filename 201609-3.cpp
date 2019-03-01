//
// Created by Saijun Hu on 2019-02-25.
// TODO 60分。。。气人，没找到哪错了
#include <iostream>
#include <vector>
#include <list>

using namespace std;

enum STATE{ LOSE=-1,TIE=0,WIN=1};
struct person{
    int atk;int health;int state;
    person(int a=0,int b=0,STATE s=STATE::TIE):atk(a),health(b),state(s){}
};
list<person> player_a;
list<person> player_b;
void attack(list<person>& cur_player, list<person>& rival_player,
        int attacker_num,int defender_num){
    auto attacker= cur_player.begin();advance(attacker,attacker_num);
    auto defender= rival_player.begin();advance(defender,defender_num);
    defender->health -= attacker->atk;
    if(defender_num==0 && defender->health<=0){
        cur_player.front().state=STATE::WIN;
        rival_player.front().state=STATE::LOSE;
    }
    if(defender_num!=0 && defender->health<=0){
        rival_player.erase(defender);
    }
    attacker->health -= defender->atk;
    if(attacker->health <=0) cur_player.erase(attacker);
}

void capture(list<person>& player){
    cout<<player.front().health<<endl;
    cout<<player.size()-1<<" ";
    auto iter=player.begin();
    advance(iter,1);
    while(iter != player.end()){
        cout<<iter->health;++iter;
    }
    cout<<endl;
}

 int main(){
     int n;cin>>n;
     player_a.emplace_back(person(0,30));
     player_b.emplace_back(person(0,30));
     bool round=false;
     while (n--){
         string s;cin>>s;
         if(s=="summon"&&!round){
             int p,a,h;cin>>p>>a>>h;
             auto it= player_a.begin();
             advance(it,p);
             player_a.insert(it,person(a,h));
         }else if(s=="summon"&& round){
             int p,a,h;cin>>p>>a>>h;
             auto it= player_b.begin();advance(it,p);
             player_b.insert(it,person(a,h));
         }
         if(s=="end") {
             round = !round;
         }
         if(s=="attack" && !round){
             int at,d;
             cin>>at>>d;
             attack(player_a,player_b,at,d);
             if(player_a.front().state!=TIE) break;
         }else if(s=="attack" && round){
             int at,d;
             cin>>at>>d;
             attack(player_b,player_a,at,d);
             if(player_a.front().state!=TIE) break;
         }
     }
     //lose or win
     switch (player_a.front().state){
         case STATE::TIE:
             cout<<TIE<<endl;break;
         case STATE::LOSE:
             cout<<LOSE<<endl;break;
         case STATE ::WIN:
             cout<<WIN<<endl;break;
         default:
             break;
     }
     capture(player_a);
     capture(player_b);
     return 0;
 }
