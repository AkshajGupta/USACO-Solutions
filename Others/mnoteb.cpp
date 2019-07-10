#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, m, counter=1, timer=0;
    cin >> n >> m;
    int arr[1000000], array[n], solution[m];
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    for(int i=0; i<m; i++){
        cin >> solution[i];
    }
    for(int i=0; i<1000000; i++){
        arr[i]=0;
    }
    for(int i=0; i<n; i++){
        while(array[i]>0){
            arr[timer]=counter;
            timer++;
            array[i]--;
        }
        counter++;
    }
    for(int i=0; i<m; i++){
        cout << arr[solution[i]] << endl;
    }
}
