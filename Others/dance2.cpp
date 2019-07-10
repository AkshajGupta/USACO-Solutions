#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int a;
    cin >> a;
    int numbers[a], counter=0;
    bool counter1=false;
    string cb[a];
    for(int i=0; i<a; i++){
        cin >> numbers[i] >> cb[i];
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<numbers[i]; j++){
            if(cb[i][j]=='>'){
                counter++;     
            }
            else{
                counter--;
            }
            if(counter<0){
                cout << "illegal" << endl;
                counter1=true;
                break;
            }
        }
        if(counter==0){
            cout << "legal" << endl;
        }
        else if(counter!=0 and counter1==false){
            cout << "illegal" << endl;
        }
        counter1=false;
        counter=0;
    }
}
