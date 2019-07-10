#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
struct dd{
    int point;
    bool endpoint;
};

bool ddcomp(dd a, dd b){
    return a.point<b.point;
}
int main(){
    int a, cur=0, layers=0, prevcur=0, answer=0, curholder=0;
    cin >> a;
    char direction;
    int distance;
    dd values[2*a];
    for(int i=0; i<2*a; i+=2){
        cin >> distance >> direction;
        values[i].point=cur;
        curholder=cur;
        if(direction=='L'){
            cur-=distance;
        }
        else{
            cur+=distance;
        }
        prevcur=cur;
        values[i+1].point=prevcur;
        if(prevcur<curholder){
            values[i+1].endpoint=false;
            values[i].endpoint=true;
        }
        else{
            values[i].endpoint=false;
            values[i+1].endpoint=true;
        }
    }
    sort(values, values+2*a, ddcomp);
    cur=0;
    for(int i=0; i<2*a-1; i++){
        cur=abs(values[i].point);
        prevcur=abs(values[i+1].point);
        if(values[i].endpoint==1){
            layers++;
        }
        else{
            layers--;
        }
        if(abs(layers)>=2){
            answer+=abs(prevcur-cur);
        }
    }
    cout << answer << endl;
}
