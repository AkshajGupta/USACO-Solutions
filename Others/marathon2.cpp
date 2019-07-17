#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, maxx=-10000, answer, total=0;
    cin >> n;
    int arr[n][2];
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i=1; i<n-1; i++){
        int distance=abs((arr[i+1][0]-arr[i][0]))+abs((arr[i+1][1]-arr[i][1]))+abs(arr[i][0]-arr[i-1][0])+abs(arr[i][1]-arr[i-1][1]);
        int originaldistance=abs((arr[i+1][0]-arr[i-1][0])) + abs((arr[i+1][1]-arr[i-1][1]));
        if(distance-originaldistance>maxx){
            maxx=distance-originaldistance;
            answer=i;
        }
    }
    for(int i=0; i<n-1; i++){
        int distance=abs((arr[i+1][0]-arr[i][0]))+abs((arr[i+1][1]-arr[i][1]));
        if(i==answer){
            distance=abs((arr[i+1][0]-arr[i-1][0]))+abs((arr[i+1][1]-arr[i-1][1]));
        }
        if(i+1!=answer){
            total+=distance;
        }
        //        cout << total << endl;
    }
    cout << total << endl;
}
