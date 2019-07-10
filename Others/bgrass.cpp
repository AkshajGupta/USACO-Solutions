#include <iostream>
using namespace std;
int main(){
    int a, b, counter=0;
    cin >> a >> b;
    char arr[a][b];
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(arr[i][j]=='#'){
                counter++;
                arr[i][j]='.';
                arr[i+1][j]='.';
                arr[i][j+1]='.';
            }
        }
    }
    cout << counter << endl;
}
