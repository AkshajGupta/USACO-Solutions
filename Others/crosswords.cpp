#include <iostream>
using namespace std;
int main(){
    int n, m, counter=0;
    cin >> n >> m;
    char arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='.' and (arr[i][j-1]=='#' or j==0) and arr[i][j+1]=='.' and arr[i][j+2]=='.' and j+2<m){
                counter++;
                arr[i][j]='*';
            }
            else if(arr[i][j]=='.' and (arr[i-1][j]=='#' or i==0) and arr[i+1][j]=='.' and arr[i+2][j]=='.' and i+2<n){
                counter++;
                arr[i][j]='*';
            }
        }
    }
    cout << counter << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='*'){
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }
}
