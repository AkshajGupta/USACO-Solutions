#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, board[25][25], total=0, anscounter=0, maxx=-100000, depthcounter=0;
void recurse(int depth, int index){
    if(depth==n){
        if(anscounter>maxx){
            maxx=anscounter;
        }
//        depthcounter--;
        return;
    }
    else{
//        if(depthcounter==depth+1){
//            depth++;
//        }
//        depthcounter++;
        anscounter+=board[depth+1][index];
        recurse(depth+1,index);
        anscounter-=board[depth+1][index];
        anscounter+=board[depth+1][index+1];
        recurse(depth+1,index+1);
        anscounter-=board[depth+1][index+1];
    }
}
int main(){
    cin >> n;
    for(int i=1; i<n+1; i++){
        for(int j=0; j<i; j++){
            cin >> board[i-1][j];
        }
    }
    recurse(0,0);
    cout << maxx+board[0][0]<< endl;
//    for(int i=0; i<n; i++){
//        int maxx=-100000;
//        for(int j=0; j<i+1; j++){
//            if(board[i][j]>maxx and (j-1==curx or j==curx)){
//                maxx=board[i][j];
//                curx=j;
//            }
//        }
//        cout << maxx << endl;
////        cout << maxx << endl;
//        cury++;
//        total+=maxx;
//    }
//    cout << total << endl;
}
