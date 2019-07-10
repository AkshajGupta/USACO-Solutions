#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int cow, total=0, distance=0, index=0;
    cin >> cow;
    bool paydebt=false;
    vector<int>cows;
    for(int i=0; i<cow; i++){
        int x;
        cin >> x;
        cows.push_back(x);
    }
    for(int i=0; i<cow; i++){
        total+=cows[i];
        distance++;
        if(total<0 and paydebt==false){
            index=i;
            paydebt=true;
        }
        if(total>0 and paydebt){
            distance+=2*(i-index);
            paydebt=false;
        }
    }
    cout << distance << endl;
}
