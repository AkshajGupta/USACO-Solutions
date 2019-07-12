#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, m, size=1, arr[1001], digits[1001], counter=0, total=0, maxx=-10000000;
void gen(int index, int lastindex){
    if(index==size){
        for(int i=0; i<size; i++){
            total+=arr[i];
            // cout << total << endl;
            if(total<n and total>maxx){
                maxx=total;
            }
        }
        total=0;
        return;
    }
    else{
        for(int i=lastindex; i<m; i++){
            arr[index]=digits[i];
            gen(index+1, i+1);
        }
    }
    return;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> digits[i];
    }
    for(int i=0; i<m; i++){
        size=i+1;
        gen(0,0);
    }
    cout << maxx << endl;
}
