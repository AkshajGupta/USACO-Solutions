#include <iostream>
using namespace std;
int main(){
    int n, m, counter=0, maxx=-1, temp=-1;
    cin >> n >> m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i-1][j]==arr[i][j] and i>0){
                counter++;
            }
            if(arr[i+1][j]==arr[i][j] and i<n-1){
                counter++;
            }
            if (arr[i][j-1]==arr[i][j] and j>0){
                counter++;
            }
            if(arr[i][j+1]==arr[i][j] and j<m-1){
                counter++;
            }
            if(arr[i-1][j-1]==arr[i][j] and i>0 and j>0){
                counter++;
            }
            if(arr[i+1][j+1]==arr[i][j] and i<n-1 and j<m-1){
                counter++;
            }
            if(arr[i+1][j-1]==arr[i][j] and i<n-1 and j>0){
                counter++;
            }
            if(arr[i-1][j+1]==arr[i][j] and i>0 and j<m-1){
                counter++;
            }
            counter++;
            if(counter>1){
                if(arr[i][j]>temp){
                    temp=arr[i][j];
                }
            }
            counter=0;
        }
    }
    cout << temp << endl;
}
