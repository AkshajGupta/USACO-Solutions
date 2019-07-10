#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a, b, total=0, maxx=-1, c, d;
    cin >> a >> b;
    int arr[a][b];
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<a-2; i++){
        for(int j=0; j<b-2; j++){
           total = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i][j+2] + arr[i+1][j+2] + arr[i+2][j+2];
           if(total>maxx){
               maxx=total;
               c=i;
               d=j;
           }
        }
    }
    cout << maxx << endl;
    cout << c+1 << " " << d+1 << endl;
}
