#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        sort(arr[i], arr[i]+n);
    }
    int average[n];
    for(int i=0; i<n; i++){
        average[i]=arr[i][n/2];
    }
    sort(average, average+n);
    cout << average[n/2] << endl;
    return 0;
    // for(int i=0; i<n; i++){
    //     cout << average[i];
    // }
    //  for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }
}
