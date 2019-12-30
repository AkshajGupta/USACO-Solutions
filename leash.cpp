#include <iostream>
#include <algorithm>
using namespace std;

bool cut[1000001];

struct input{
    int start;
    int end;
};

bool inputcomp(input a, input b){
    return a.end<b.end;
}

int main(){
    int n;
    cin >> n;
    input leash[n];
    for(int i=0; i<n; i++){
        cin >> leash[i].start >> leash[i].end;
        leash[i].end+=leash[i].start;
    }
    
    sort(leash, leash+n, inputcomp);
    
//    for(int i=0; i<n; i++){
//        cout << leash[i].start << " " << leash[i].end << endl;
//    }
    
    int counter=0;
    
    for(int i=0; i<n; i++){
        if(!cut[i]){
            cut[i]=true;
            for(int j=0; j<n; j++){
                if(leash[j].start < leash[i].end){
                    cut[j]=true;
                }
            }
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
