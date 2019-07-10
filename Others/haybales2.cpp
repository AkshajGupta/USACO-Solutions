#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int stacks[1000001];
int main(){
    int a, b;
    cin >> a >> b;
    int haybales[a], q1[b], q2[b];
    for(int i=0; i<a; i++){
        cin >> haybales[i];
    }
    for(int i=0; i<b; i++){
        cin >> q1[i] >> q2[i];
    }
    sort(haybales, haybales+a);
    for(int j=0; j<b; j++){
         int upper1 = upper_bound(haybales, haybales+a, q1[j]) - haybales-1;
//         if(haybales[upper1]>q1[j]){
//             upper1++;
//         }
        if(haybales[upper1]==q1[j]){
            upper1--;
        }
//        cout << upper1 << " ";
        if(q1[j]>haybales[a-1]){
            cout << 0 << endl;
            continue;
        }
        int lower1 = lower_bound(haybales, haybales+a, q2[j]) - haybales-1;
        if(haybales[lower1+1]==q2[j]){
            lower1++;
        }
        cout << lower1-upper1<< endl;
    }
}
