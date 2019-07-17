#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, counter=0, minn=10000000;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        if(arr[i]==2){
            for(int j=i+1; j<n; j++){
                if(arr[j]==1){
                    counter++;
                }
            }
            for(int j=i-1; j>=0; j--){
                if(arr[j]==2){
                    counter++;
                }
            }
        }
        else{
            counter=1000000;
        }
        if(counter<minn and counter!=1000000){
            minn=counter;
        }
        counter=0;
    }
    int counter1=0, counter2=0;
    for(int i=0; i<n; i++){
        if(arr[i]==1){
            counter1++;
        }
        else{
            counter2++;
        }
    }
    if(minn==10000000){
        cout << 0;
        return 0;
    }
    if(counter1<minn){
        cout << counter1;
        return 0;
    }
    else if(counter2<minn){
        cout << counter2;
        return 0;
    }
    cout << minn;
}
