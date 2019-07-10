#include <iostream>
using namespace std;
int main(){
    int n, m, mid, k;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    // for(int i=0; i<m; i++){
    //     cin >> array[i];
    // }
    int low=0, high=n-1;
    for(int i=0; i<m; i++){
        cin >> k;
    if(arr[low]!=k){
        while(low<high){
            mid=(low+high+1)/2;
            if(arr[mid]<k){
                low=mid;
            }
            else{
                high=mid-1;
            }
            // cout << mid << endl;
        }
        if(mid<(n)/2){
            if(arr[low+1]!=k){
                cout << -1 << endl;
            }
            else{
                cout << low+1 << endl;
            }
        }
        else{
            if(arr[high+1]!=k){
                cout << -1 << endl;
            }
            else{
                cout << high+1 << endl;
            }
        }
        low=0;
        high=n-1;
        }
        else{
        cout << 0 << endl;
    }
    }
}
