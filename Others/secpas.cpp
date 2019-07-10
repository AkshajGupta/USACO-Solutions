#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, counter=0;
    cin >> n;
    for(int i=0; i<=sqrt(n); i++){
        for(int j=0; j<=sqrt(n); j++){
            for(int k=0; k<=sqrt(n); k++){
                for(int f=0; f<=sqrt(n); f++){
                    if(i*i + j*j + k*k + f*f == n){
                        counter++;
                    }
                }
            }
        }
    }
    cout << counter << endl;
}
