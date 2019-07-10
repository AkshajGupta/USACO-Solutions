#include <iostream>
using namespace std;
int main(){
    int n, average=0, answer=0;
    cin >> n;
    int haybales[n];
    for(int i=0; i<n; i++){
        cin >> haybales[i];
        average+=haybales[i];
    }
    average=average/n;
    for(int i=0; i<n; i++){
        if(haybales[i]>average){
            answer=answer+haybales[i]-average;
        }
    }
    cout << answer << endl;
}

