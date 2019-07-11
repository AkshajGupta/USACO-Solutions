#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[1000000];
    arr[0]=1;

    arr[1]=1;
    for(int i=2; i<1000000; i++){
        arr[i]=arr[i-1]+arr[i-2];
        if(i==n-1){
            cout << arr[i] << endl;
            return 0;
        }
    }
}
