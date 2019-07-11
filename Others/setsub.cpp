#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, size=1, arr[1001], digits[1001], counter=0;
void gen(int index, int lastindex){
    if(index==size){
        for(int i=0; i<size; i++){
            cout << arr[i];
        }
        cout << endl;
        return;
    }
    else{
        for(int i=lastindex; i<n; i++){
            arr[index]=digits[i];
            gen(index+1, i+1);
        }
    }
    return;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> digits[i];
    }
    for(int i=0; i<n; i++){
        size=i+1;
        gen(0,0);
    }
}
