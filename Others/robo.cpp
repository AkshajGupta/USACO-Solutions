#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
int main(){
    stack<int>haybales;
    vector<int>arr;
    int a, counter=0, length;
    string command;
    cin >> a;
    for(int i=0; i<a; i++){
        cin >> command;
        if(command=="ADD"){
            haybales.push(counter+1);
            arr.push_back(counter+1);
            counter++;
        }
        else{
            haybales.pop();
            arr.pop_back();
        }
        length=arr.size();
    }
    cout << arr.size() << endl;
    for(int i=0; i<length; i++){
        cout << arr[i] << endl;
    }
}
