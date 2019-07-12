#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, arr[1001], total=0, k, cow1[10001], cow2[100001], counter=0;
char sd[100001];
void gen(int index){
    if(index==n){
        bool print=true;
        for(int i=0; i<k; i++){
            if(sd[i]=='S' and arr[cow1[i]-1]!=arr[cow2[i]-1]){
                print=false;
            }
            else if(sd[i]=='D' and arr[cow1[i]-1]==arr[cow2[i]-1]){
                print = false;
            }
        }
        if(print==true){
            //            for(int i=0; i<n; i++){
            //                cout << arr[i];
            //            }
//            cout <<arr[cow1[0]] <<" " << arr[cow2[0]] << endl;
//            cout << cow2[0] << endl;
            counter++;
        }
        return;
    }
    else{
        for(int i=1; i<=3; i++){
            arr[index]=i;
            gen(index+1);
        }
    }
    return;
}
int main(){
    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> sd[i] >> cow1[i] >> cow2[i];
    }
    gen(0);
    cout << counter << endl;
}
