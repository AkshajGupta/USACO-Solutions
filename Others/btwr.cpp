#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int n, counter=0, total=0, maxx=-100000, prevcur=10000000;
struct hw{
    int height;
    int width;
};
bool hwcomp(hw a, hw b){
    return a.width>b.width;
}
hw haybales[20];
bool picked[20];
void recur(int cur){
    if(cur==n){
        counter=0;
        for(int i=0; i<n; i++){
            if(picked[i]==true and haybales[i].height<prevcur){
                prevcur=haybales[i].height;
                counter++;
            }
            else if(picked[i]==true and haybales[i].height>prevcur){
                counter=maxx;
                break;
            }
        }
        prevcur=1000000;
//        cout << haybales[i].height << " " << haybales[prevcur].height << endl;
        // cout << counter << endl;
        if(counter>maxx){
            maxx=counter;
        }
        return;
    }
    else{
            picked[cur]=true;
            recur(cur+1);
            picked[cur]=false;
            recur(cur+1);
    }
    return;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> haybales[i].height >> haybales[i].width;
    }
    sort(haybales, haybales+n, hwcomp);
    recur(0);
    cout << maxx << endl;
}
