#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int a;
    stack<int>wetdishes;
    stack<int>drydishes;
    stack<int>done;
    cin >> a;
    for(int i=1; i<=a; i++){
        wetdishes.push(a-i+1);
    }
        // for(int i=0; i<a; i++){
        //     int x=wetdishes.top();
        //     wetdishes.pop();
        //     cout << x << endl;
        // }
    for(int i=0; i<a-1; i++){
        int wet, dry;
        cin >> dry >> wet;
        if(dry==1){
            for(int j=0; j<wet; j++){
                if(wetdishes.size()>0){
                int x=wetdishes.top();
                wetdishes.pop();
                drydishes.push(x);
                // cout << x << " wet ";
                }
                else{
                    break;
                }
            }
        }
        else{
            for(int j=0; j<wet; j++){
                if(drydishes.size()>0){
                int x=drydishes.top();
                drydishes.pop();
                done.push(x);
                // cout << x << " dry ";
                }
                else{
                    break;
                }
            }
        }
    }
    for(int i=0; i<a; i++){
        int x=done.top();
        done.pop();
        cout << x << endl;
    }
}
