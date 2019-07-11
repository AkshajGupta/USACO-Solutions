#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
string str="";
void d(int a){
    if(a==1){
        str+="*\n";
    }
    else{
        d(a-1);
        for(int i=0; i<a; i++){
            str+="*";
        }
        str+="\n";
        d(a-1);
    }
    return;
}
int main(){
    int n;
    string answer = "";
    cin >> n;
    d(n-1);
    for(int i=0; i<n; i++){
        cout << '*';
    }
    cout << endl;
    cout << str;
    for(int i=0; i<n; i++){
        cout << '*';
    }
}
