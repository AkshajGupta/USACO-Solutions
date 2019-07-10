#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int h, l, counter=0;
    cin >> h >> l;
    int high[h], low[l];
    for(int i=0; i<h; i++){
        cin >> high[i];
    }
    for(int i=0; i<l; i++){
        cin >> low[i];
    }
    sort(high, high+h);
    sort(low, low+l);
    for(int j=0; j<h; j++){
        for(int i=0; i<l; i++){
            if(high[j]>low[i]){
                counter++;
                high[j]=-1;
                low[i]=10000000;
                break;
            }
        }
    }
    cout << counter+h << endl;
}
