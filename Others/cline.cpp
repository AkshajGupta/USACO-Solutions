#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int main(){
    int n, cowid=1;
    cin >> n;
    deque <int> line;
    for(int i=0; i<n; i++){
        char action, side;
        int number;
        cin >> action >> side;
        //        cout << action << " " << side << " ";
        if(action=='D'){
            cin >> number;
        }
        if(action=='A'){
            if(side=='L'){
                line.push_back(cowid);
                cowid++;
            }
            else{
                line.push_front(cowid);
                cowid++;
            }
        }
        if(action=='D'){
            if(side=='L'){
                for(int j=0; j<number; j++){
                    line.pop_back();
                }
            }
            else{
                for(int j=0; j<number; j++){
                    line.pop_front();
                }
            }
        }
    }
    // cout << line.size() << endl;
    // for(int i=0; i<line.size(); i++){
    //     cout << line.back() << endl;
    //     line.pop_back();
    // }
    while(!line.empty()){
        cout << line.back() << endl;
             line.pop_back();
    }
}
