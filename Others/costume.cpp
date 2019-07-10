#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, m, counter=0, mid, high, low, answer=0;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        int max=m-arr[i];
        high=n-1;
        low=i;
        if(arr[low]<=max){
            while(high>low){
                mid=(high+low+1)/2;
                    if(arr[mid]<=max){
                    low=mid;
                }
                else{
                    high=mid-1;
                }
            }
        }
        answer= answer+low-i;
    }
    cout << answer << endl;
}
