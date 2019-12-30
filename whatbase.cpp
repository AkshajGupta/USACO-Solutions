#include <iostream>
using namespace std;

int baseconversion(int n, int base){
    int total=0, multfact=1;
    while(n>0){
        total+=(n%10)*multfact;
        multfact*=base;
        n/=10;
    }
    return total;
}


int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x=10, y=10, num1, num2;
        cin >> num1 >> num2;
        int newnum1=num1;
        int newnum2=num2;
        while(newnum1!=newnum2){
            newnum1=baseconversion(num1, x);
            newnum2=baseconversion(num2, y);
            if(newnum1<newnum2){
                x++;
            }
            else{
                y++;
            }
        }
        cout << x << " " << y-1 << endl;
    }
    return 0;
}
