#include <iostream>
#include <algorithm>
using namespace std;
int n, m, anscounter=0, total=0;
char graph[100][100];
bool visited[100][100];
void recurse(int x, int y){
    if(x==n-1 and y==n-1){
        total++;
        return;
    }
    else{
        for(int i=x+1; i<n; i++){
            for(int j=y+1;j<m; j++){
                if(graph[i][j]!=graph[x][y] and !visited[i][j]){
                    visited[i][j]=true;
                    anscounter++;
                    recurse(i,j);
                    visited[i][j]=false;
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n;  i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
        }
    }
    visited[0][0]=true;
    recurse(0, 0);
    cout << total << endl;
}
