#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main(){
    int a;
    stack<int>lookup;
    stack<int>index;
    vector<int>cows;
    cin >> a;
    int answer[a];
    for(int i=0; i<a; i++){
        answer[i]=0;
    }
    for(int i=0; i<a; i++){
        int x;
        cin >> x;
        cows.push_back(x);
    }
    for(int i=0; i<a; i++){
        if(i>0 and cows[i]>lookup.top()){
            while(index.size()>0 and cows[i]>lookup.top()){
                lookup.pop();
                answer[index.top()]=i+1;
                index.pop();
            }
        }
        lookup.push(cows[i]);
        index.push(i);
    }
    for(int i=0; i<a; i++){
        cout << answer[i] << endl;
    }
}
