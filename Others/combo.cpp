#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, f1, f2, f3, m1, m2 ,m3, counter=0;
    cin >> n >> f1 >> f2 >> f3 >> m1 >> m2 >>m3;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int m=1; m<=n; m++){
                if(((abs(i-f1)<=2 or abs(i-f1)>=n-2) and (abs(j-f2)<=2 or abs(j-f2)>=n-2) and (abs(m-f3)<=2 or abs(m-f3)>=n-2)) or ((abs(i-m1)<=2 or abs(i-m1)>=n-2) and (abs(j-m2)<=2 or abs(j-m2)>=n-2) and (abs(m-m3)<=2 or abs(m-m3)>=n-2))){
                    counter++;
                }
            }
        }
    }
    cout << counter << endl;
}
