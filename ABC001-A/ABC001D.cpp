//atcoder.jp/contests/abc001/submissions/31714816
#include <bits/stdc++.h>
using namespace std;
string ch(int x){
  if(x >= 10) return to_string(x);
  else return "0" + to_string(x);
}
int main(void){
    int n,st,en;
    string a;
    bool flag=false;
    array<bool, 290> check;//289 is 60/5*24+1
    array<bool, 290> endcheck;
    for(int i=0;i<290;i++){
        check.at(i)=false;
        endcheck.at(i)=true;
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        st=stoi(a.substr(0,2))*60+stoi(a.substr(2,2));
        en=stoi(a.substr(5,2))*60+stoi(a.substr(7,2));
        st=floor(st/5.0);
        en=ceil(en/5.0);
        for(int i=st;i<=en;i++){
            check.at(i)=true;
            if(i!=en){
                endcheck.at(i)=false;
            }
        }
    }
    for(int i=0;i<290;i++){
        if(check.at(i)){
            if(!flag){
                cout << ch(floor(i/12)) << ch((i*5)%60) << "-";
                flag=true;
            }
        }
        if(endcheck.at(i)){
            if(flag){
                cout << ch(floor(i/12)) << ch((i*5)%60) << endl;
                flag=false;
            }
        }
    }
}