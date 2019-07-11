#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int factorial=n;
    for(int i=1; i<n; i++){
        factorial=factorial*(n-i);
    }
    cout << factorial << endl;
}
