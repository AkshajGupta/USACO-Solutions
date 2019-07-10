#include <iostream>
#include <string>
using namespace std;
int main(){
    string s, s2;
    cin >> s >> s2;
    int number=1, number2=1;
    for(int i=0; i<s.length(); i++){
        number=number*(s[i]-'A'+1);
    }
    for(int i=0; i<s2.length(); i++){
        number2=number2*(s2[i]-'A'+1);
    }
    if(number2%47==number%47){
        cout << "GO" << endl;
        return 0;
    }
    else{
        cout << "STAY" << endl;
        return 0;
    }
}
