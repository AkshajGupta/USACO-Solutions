#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, m, meetcounter=0;
    bool met=false;
    cin >> n >> m;
    char elsie, bessie;
    int emove, bmove, elsiecounter=0, bessiecounter=0, elsieoob=0, bessieoob=0;
    vector <char> newelsie, newbessie;
    for(int i=0; i<n; i++){
        cin >> emove >> elsie;
        for(int j=0; j<emove; j++){
            newelsie.push_back(elsie);
        }
    }
    for(int i=0; i<m; i++){
        cin >> bmove >> bessie;
        for(int j=0; j<bmove; j++){
            newbessie.push_back(bessie);
        }
    }
    while(true){
        if(bessieoob>newbessie.size()-1){
            //do nothing
        }
        else if(newbessie[bessieoob]=='L'){
            bessiecounter--;
        }
        else{
            bessiecounter++;
        }
        if(elsieoob>newelsie.size()-1){
            //do nothing
        }
        else if(newelsie[elsieoob]=='L'){
            elsiecounter--;
        }
        else{
            elsiecounter++;
        }
        bessieoob++;
        elsieoob++;
        if(bessieoob==1 and elsieoob==1 and elsiecounter==-1 and bessiecounter==-1){
            meetcounter--;
        }
        if(bessieoob>newbessie.size() and elsieoob>newelsie.size()){
            cout << meetcounter << endl;
            return 0;
        }
//                cout << elsiecounter << " " << bessiecounter << endl;
        if(elsiecounter==bessiecounter and !met){
            meetcounter++;
            met=true;
        }
        if(elsiecounter!=bessiecounter and met){
            met=false;
        }
    }
}
