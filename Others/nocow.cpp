#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, noa[30], nop;
string adj[30][100], fj[100];
bool duplicate=false;
int possiblechoices(int a, int b){
    int counting=1;
    for(int i=a; i<b+1; i++){
        counting*=noa[i];
    }
    return counting;
}
string gettinganswer(int a){
    string s="";
    for(int i=0; i<nop; i++){
        if(i>0){
            s +=" ";
        }
        s+=adj[i][a/possiblechoices(i+1,nop-1)];
        a=a%possiblechoices(i+1, nop-1);
    }
    return s;
}
int overcount(string s){
    int counting=0;
    for(int i=0; i<n; i++){
        if(fj[i]<=s){
            counting++;
        }
    }
    return counting;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string uselesswords[4], adjective;
        for(int j=0; j<4; j++){
            cin >> uselesswords[j];
        }
        cin >> adjective;
        int pos=0;
        fj[i]="";
        while(adjective!="cow."){
            if(pos>0){
                fj[i]+=" ";
            }
            fj[i]+=adjective;
            for(int a=0; a<noa[pos]; a++){
                if(adj[pos][a]==adjective){
                    duplicate=true;
                    break;
                }
            }
            if(!duplicate){
                adj[pos][noa[pos]]=adjective;
                noa[pos]++;
            }
            pos++;
            cin >> adjective;
            nop=pos;
            duplicate=false;
        }
    }
    for(int i=0; i<nop; i++){
        sort(adj[i], adj[i]+noa[i]);
    }
    int k=m-1;
    m--;
    while(m-(overcount(gettinganswer(m)))<k){
        m++;
    }
    cout << gettinganswer(m) << endl;
}
