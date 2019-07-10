#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
int main(){
    int cows, value;
    cin >> cows;
    char cowregister;
    vector<int>registers[cows];
    queue<int>line;
    while(cin >> cowregister){
        cin >> value;
        if(cowregister=='C'){
            line.push(value);
        }
        else{
            registers[value-1].push_back(line.front());
            line.pop();
        }
    }
    for(int i=0; i<cows; i++){
        int length=registers[i].size();
        cout << length << " ";
        for(int j=0; j<registers[i].size(); j++){
            cout << registers[i][j] << " ";
        }
        cout << endl;
    }
}
