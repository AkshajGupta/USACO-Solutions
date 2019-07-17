#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool visited[100][100];
int n, minn=1000000, m, k, answercounter=0;
char graph[100][100];
int shortestpath=1;
void bfs(int x, int y){
    if(x==0 and y==m-1){
        if(shortestpath<=k){
            answercounter++;
        }
        return;
    }
    else{
        int dx[4] = {x-1, x, x, x+1};
        int dy[4] = {y, y-1, y+1, y};
        for(int i=0; i<4; i++){
            int nx=dx[i];
            int ny=dy[i];
            if(nx>=0 and ny>=0 and nx<n and ny<m and graph[nx][ny]!='T' and !visited[nx][ny]){
//                cout << nx << " " << ny << endl;
                visited[nx][ny]=true;
                shortestpath++;
                bfs(nx, ny);
                visited[nx][ny]=false;
                shortestpath--;
            }
        }
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
        }
    }
    visited[n-1][0]=true;
bfs(n-1,0);
    cout << answercounter << endl;
    return 0;
}
