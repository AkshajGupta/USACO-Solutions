#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int n, counter=0;
    cin >> n;
    int x[n], y[n], r[n], possibilities[2], itemp=0;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> r[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j and sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]))==r[i]+r[j]){
                counter++;
            }
        }
        if(counter==1){
            possibilities[itemp]=i;
            itemp++;
        }
        else{
            counter=0;
        }
    }
    for(int i=0; i<2; i++){
        if(x[possibilities[i]]!=0 and y[possibilities[i]]!=0){
            cout << x[possibilities[i]] << " " << y[possibilities[i]] << endl;
            return 0;
        }
    }
}
