#include <iostream>
#include <algorithm>
using namespace std;
struct happy{
    float cost;
    float value;
};

bool happycomp(happy a, happy b){
    return (a.value/a.cost)<(b.value/b.cost);
}
int main(){
    int n, cost=0, index, arrcost[3];
    cin >> n;
    happy arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].value >> arr[i].cost;
    }
    int originalarray[n][2];
    for(int i=0; i<n; i++){
        originalarray[i][0]=arr[i].value;
        originalarray[i][1]=arr[i].cost;
    }
    //     for(int i=0; i<n; i++){
    //     cout << originalarray[n][0] << " " << originalarray[n][1] << endl;
    // }
    sort(arr, arr+n, happycomp);
//    for(int i=0; i<n; i++){
//        cout << arr[i].value << " " << arr[i].cost << endl;
//    }
    cost=arr[n-1].cost + arr[n-2].cost + arr[n-3].cost;
    cout << cost << endl;
    for(int i=0; i<n; i++){
        if(originalarray[i][1]==arr[n-3].cost and originalarray[i][0]==arr[n-3].value){
            arrcost[2]=i;
        }
        else if(originalarray[i][1]==arr[n-2].cost and originalarray[i][0]==arr[n-2].value){
            arrcost[1]=i;
        }
        else if(originalarray[i][1]==arr[n-1].cost and originalarray[i][0]==arr[n-1].value){
            arrcost[0]=i;
        }
    }
    for(int i=0; i<3; i++){
        cout << arrcost[i]+1 << endl;
    }
}
