#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int minutes, location, countingminutes=0, cur=0, minn=1000000000, placeholder=0, counter=0, oldcur=0;
    cin >> minutes >> location;
    int arr[location];
    for(int i=0; i<location; i++){
        cin >> arr[i];
    }
    while(countingminutes<=minutes){
        for(int i=0; i<location; i++){
            if(abs(arr[i])<minn and arr[i]!=0){
                minn=abs(arr[i]);
                placeholder=i;
            }
        }
        cur=arr[placeholder];
        // cout << cur << endl;
        if(cur<0 and oldcur>=0){
        countingminutes=countingminutes+abs(cur)+abs(oldcur);
//            cout << countingminutes << endl;
        }
        else if(cur>0 and oldcur>=0){
            countingminutes=countingminutes+abs(cur-oldcur);
//            cout << countingminutes << endl;
        }
        else if(cur<0 and oldcur<=0){
            countingminutes=countingminutes+abs(cur-oldcur);
//            cout << countingminutes << endl;
        }
        else if(cur>0 and oldcur<=0){
            countingminutes=countingminutes+abs(cur-oldcur);
        }
        oldcur=arr[placeholder];
        minn=1000000000;
        arr[placeholder]=0;
        counter++;
    }
    cout << counter-1 << endl;
}
