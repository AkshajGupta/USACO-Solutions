#include <iostream>
using namespace std;
int main(){
    int cows, diff, maxx=-1;
    cin >> cows >> diff;
    int arr[cows];
    for(int i=0; i<cows; i++){
        cin >> arr[i];
    }
    for(int i=0; i<cows; i++){
        for(int j=1; j<=diff; j++){
            if(i+j<cows and arr[i]==arr[i+j]){
                if(arr[i]>maxx){
                    maxx=arr[i];
                }
                arr[i]=0;
                arr[i+j]=0;
                break;
            }
        }
    }
    cout << maxx << endl;
    return 0;
}
