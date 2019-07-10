#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int stacks[1000001];
int pre[1000001];
int main(){
    int a, b;
    cin >> a >> b;
    for(int j=0; j<b; j++){
        int c, d;
        cin >> c >> d;
        pre[c]++;
        pre[d+1]--;
    }
    int ongoing=0;
    for(int i=0; i<a; i++){
        ongoing=ongoing+pre[i];
        stacks[i]=stacks[i]+ongoing;
    }
    sort(stacks,stacks+a);
    cout << stacks[a/2] << endl;
    // for(int i=0; i<a; i++){
    //     cout << stacks[i] << endl;
    // }
}
