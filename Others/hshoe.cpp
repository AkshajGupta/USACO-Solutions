#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, anscounter=0;
char graph[100][100];
bool visited[100][100];
void recurse(int x, int y, int noo, int noc, bool done){
    if(done and noo*2<anscounter){
        return;
    }
    if(noo==noc and noo!=0 and noc!=0){
        anscounter=max(anscounter, noo+noc);
        return;
    }
    else{
        int dx[4] = {x+1, x, x, x-1};
        int dy[4] = {y, y+1, y-1, y};
        for(int i=0; i<4; i++){
            int nx=dx[i];
            int ny=dy[i];
            if(nx>=0 and ny>=0 and nx<n and ny<n and !visited[nx][ny]){
                if(graph[nx][ny]=='(' and !done){
                    visited[nx][ny]=true;
                    recurse(nx, ny, noo+1, noc, false);
                    visited[nx][ny]=false;
                }
                else if(graph[nx][ny]==')'){
                    visited[nx][ny]=true;
                    recurse(nx, ny, noo, noc+1, true);
                    visited[nx][ny]=false;
                }
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }
    visited[0][0]=true;
    if(graph[0][0]=='('){
        recurse(0,0,1,0,false);
    }
    else{
        cout << 0 << endl;
        return 0;
    }
    cout << anscounter << endl;
}
