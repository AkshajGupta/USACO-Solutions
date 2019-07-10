#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, total=0, minn=10000000000;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n-1; i++){
        int temp1=i;
        while(arr[i]>arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            i--;
        }
        i=temp1;
    }
    if(arr[n-1]-arr[0]<=17){
        cout << 0 << endl;
        return 0;
    }
    for(int a=0; a<84; a++){
        int b=a+17;
        for(int i=0; i<n; i++){
            if(arr[i]<a){
                total = total + (a-arr[i])*(a-arr[i]);
            }
            if(arr[i]>b){
                total= total + (arr[i]-b)*(arr[i]-b);
                // cout << arr[i] << endl;
            }
            // cout << total << " " << a << " " << b << endl;
        }
        if(total<minn and total!=0){
            minn=total;
        }
        total=0;
    }
    cout << minn << endl;
}
