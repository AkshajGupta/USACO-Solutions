#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, arr[10], needcheck=0, counter=0, newnum;
bool isprime(int a){
    int squareroot=sqrt(a);
    if(a==2){
        return true;
    }
    if(a<2){
        return false;
    }
    for(int i=2; i<=squareroot; i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
void gen(int num, int digits){
    if(digits==n){
        if(isprime(newnum)){
            cout << newnum << endl;
        }
        return;
    }
    else{
        for(int i=1; i<=9; i++){
            newnum=num*10+i;
            if(isprime(newnum)){
                gen(newnum, digits+1);
            }
        }
    }
    return;
}
int main(){
    cin >> n;
    gen(0, 0);
}
