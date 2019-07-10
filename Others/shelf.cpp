#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, m, total=0;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=n-1; i>=0; i--){
        total=total+arr[i];
        if(total>=m){
            cout << n-i << endl;
            return 0;
        }
    }
}
