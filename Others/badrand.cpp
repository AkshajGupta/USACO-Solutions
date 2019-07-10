#include <iostream>
using namespace std;
int main(){
    int x, counter=0;
    cin >> x;
    int seen[10000];
    for(int i=0; i<10000; i++){
        seen[i]=0;
    }
    while(true){
        x=x/10;
        x=x%100;
        x=x*x;
        counter++;
        if(x==0){
            break;
        }
        for(int i=0; i<10000; i++){
            if(x==seen[i]){
                cout << counter << endl;
                return 0;
            }
            else if(seen[i]==0){
                break;
            }
        }
        seen[counter-1]=x;
    }
    cout << counter+1 << endl;
    return 0;
}
