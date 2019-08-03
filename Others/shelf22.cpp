#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
int n, m;
    cin >> n >> m;
    int digits[n], counter=1, minn=10000000,total=0;
    for(int i=0; i<n; i++){
        cin >> digits[i];
    }
    for(int i=0; i<n; i++){
        counter*=2;
    }
    for(int i=0; i<counter; i++){
        total=0;
        for(int j=0; j<n; j++){
            if((i & (1<<j))>0){
                total+=digits[j];
            }
            if(total<minn and total>=m){
                minn=total;
            }
        }
//        cout << total << endl;
    }
//    cout << minn << " " << m << endl;
    cout << minn-m << endl;

}
