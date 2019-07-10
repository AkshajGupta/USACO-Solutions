#include <iostream>
using namespace std;
int main(){
    int ttime, paths, up, flat, down, total=0, answer=0;
    char currentpath;
    cin >> ttime >> paths >> up >> flat >> down;
    for(int i=0; i<paths; i++){
        cin >> currentpath;
        if(currentpath == 'u'){
            total+=up;
            total+=down;
            answer++;
        }
        else if(currentpath == 'f'){
            total+=2*flat;
            answer++;
        }
        else{
            total+=down;
            total+=up;
            answer++;
        }
        if(total>ttime){
            cout << answer-1 << endl;
            return 0;
        }
    }
}
