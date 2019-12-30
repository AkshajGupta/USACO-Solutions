#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, counter=0;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    
    
    for(int i=n-1; i>=0; i--){
        if(arr[i]<counter){
        }
        else{
            counter++;
        }
    }
    cout << counter << endl;
}
