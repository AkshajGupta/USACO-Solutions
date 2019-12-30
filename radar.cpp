#include <iostream>
#include <string>
using namespace std;
int addreverse(int a){
    string s = to_string(a);
    string reverse;
    for(int i=s.length()-1; i>=0; i--){
        reverse+=s[i];
    }
    int done=stoi(reverse);
    return done;
}

int size(int a){
    int counter=0;
    while(a>0){
        a/=10;
        counter++;
    }
    return counter;
}

bool randcheck(int a){
    int newsize=size(a);
    string s = to_string(a);
    if(newsize%2==1){
        newsize--;
    }
    newsize/=2;
//    cout << newsize << endl;
    for(int i=0; i<newsize; i++){
        if(s[i]!=s[size(a)-i-1]){
//            cout << s[i] << " " << s[size(a)-1] << endl;
            return false;
        }
    }
    return true;
}

int main(){
    int n, counter=0;
    cin >> n;
//    cout << addreverse(n) << endl;
    while(randcheck(n)==false){
        n+=addreverse(n);
        counter++;
    }
    cout << counter << endl;
    cout << n << endl;
    return 0;
}
