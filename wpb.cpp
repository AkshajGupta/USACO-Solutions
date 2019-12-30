#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long size, n, num1int, num2int, arr[1001];

string num1, num2;

int sizeint(int a){
    int counter=0;
    while(a>0){
        a/=10;
        counter++;
    }
    return counter;
}

bool checkprime(int a){
    if(a==0 or a==1) return false;
    for(int i=2; i<=sqrt(a); i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int incrementation(int num){
    int a = sizeint(num);
    while(!checkprime(num) and sizeint(num)==a){
        num++;
    }
    return num;
}

int decrementation(int num){
    int a = sizeint(num);
    num=1;
    for(int i=0; i<a-1; i++){
        num*=10;
    }
    while(!checkprime(num)){
        num++;
    }
    return num;
}

void split(int size1, int size2, int num){
    int a = sizeint(num);
    
    num1="";
    num2="";
    
//    cout << a << endl;
    for(int i=0; i<a; i++){
        arr[i]=num%10;
        num/=10;
    }
    
    for(int i=size1-1; i>=0; i--){
        if(arr[i]==0 and i==size1-1){
            num1+='1';
        }
        else num1+=arr[i]+'0';
    }
    for(int i=a-1; i>=size1; i--){
        num2+=arr[i]+'0';
    }
    
    
    
    num1int=stoi(num1);
    num2int=stoi(num2);
    
    return;
}

int main(){
    cin >> size >> n;
    int sizetemp=1;
    for(int i=0; i<size*2-1; i++){
        sizetemp*=10;
    }
//    cout << sizetemp << endl;
    string mn = to_string(n);
    if(n<sizetemp){
        n=1;
        while(n<sizetemp){
            n*=10;
        }
    }
//    cout << mn.length() << " " << size << endl;
//    return 0;
//    cout << n << endl;
    long sizeofn=sizeint(n), incrementednum1, incrementednum2, minn=10000000000;
    for(int i=size; i<=sizeofn-size; i++){
        split(i, sizeofn-i, n);
        // cout << num2int << " " << num1int << endl;
        incrementednum1 = incrementation(num1int);
        incrementednum2=num2int;
//        cout << incrementednum1 << endl;
        if(incrementednum1%10==0){
//            cout << "happened" << endl;
            incrementednum2 = incrementation(num2int);
            incrementednum1 = decrementation(num1int);
        }
        if(!checkprime(incrementednum2)){
            incrementednum2 = incrementation(incrementednum2);
            incrementednum1 = decrementation(incrementednum1);
        }
        string a = to_string(incrementednum2);
        string b = to_string(incrementednum1);
        for(int m=0; m<b.length(); m++){
            incrementednum2*=10;
        }
//        cout << incrementednum2 << " " << incrementednum1 << endl;
//        cout << incrementednum2+incrementednum1 << endl;
        if(incrementednum2+incrementednum1<minn and incrementednum2+incrementednum1>n){
            minn=incrementednum2+incrementednum1;
        }
    }
    cout << minn;
    return 0;
}
