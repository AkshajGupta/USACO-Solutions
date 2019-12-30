#include <iostream>
#include <vector>
using namespace std;
int nonloopy[10000];
int main(){
    int n, counter=0;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if (arr[i] == 0) nonloopy[i] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (nonloopy[arr[j] - 1] == 1) nonloopy[j] = 1;
        }
    }
    
    for(int i=0; i<n; i++){
        cout << nonloopy[i] << " ";
    }
   
    for (int i=0; i<n; i++){
        if(nonloopy[i]==1){
            counter++;
        }
    }
    
    cout << counter << endl;
    return 0;
}
