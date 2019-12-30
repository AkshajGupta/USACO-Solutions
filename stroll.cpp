#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int traversals[1000][1000];
int main(){
    bool one=false;
    int r, c, startr, startc;
    cin >> r >> c;
    char map[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
            if(one==false and map[i][j]=='B'){
                startr=i;
                startc=j;
                one=true;
//                cout << startr << " " << startc << endl;
//                cout << "hi" << endl;
            }
        }
    }
//    for(int i=0; i<r; i++){
//        for(int j=0; j<c; j++){
//            cout << map[i][j] << " ";
//        }
//        cout << endl;
//    }
    if(map[startr+1][startc]=='.'){
        traversals[startr+1][startc]=1;
    }
    if(map[startr][startc+1]=='.'){
//        cout << "hi" << endl;
        traversals[startr][startc+1]=1;
    }
//    cout << startr << " " << startc << endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j]=='.'){
                if(i>=1){
                    traversals[i][j]+=traversals[i-1][j];
                }
                if(j>=1){
                    traversals[i][j]+=traversals[i][j-1];
                }
            }
            else if(map[i][j]=='B' and i!=startr and j!=startc){
                traversals[i][j]=traversals[i-1][j]+traversals[i][j-1];
                cout << traversals[i][j] << endl;
                return 0;
            }
            else if(map[i][j]=='R'){
                traversals[i][j]=0;
            }
        }
    }
}
