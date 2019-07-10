
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    long long a, counter=0;
    string s;
    cin >> s >> a;
    long long temp=s.length();
    while(true){
        if(temp>a){
            while(counter>0){
                temp=temp/2;
                if(temp<a){
                    if(a-temp==1){
                        a=temp;
                    }
                    else{
                        a = a-temp-1;
                    }
                }
                counter--;
            }
            cout << s[a-1] << endl;
            return 0;
        }
        counter++;
        temp=temp*2;
    }
}
