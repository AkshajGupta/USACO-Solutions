#include <iostream>
using namespace std;
int main(){
    int n, m, counter=0;
    cin >> n >> m;
    int arr[n+1];
    for(int i=0; i<n+1; i++){
        arr[i]=0;
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        for(int i=a; i<n+1; i+=b){
            arr[i]=1;
        }
    }
    for(int i=0; i<n+1; i++){
        if(arr[i]==0){
            counter++;
        }
    }
    cout << counter-1 << endl;
}
