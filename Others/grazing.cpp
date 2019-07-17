#include <iostream>
#include <algorithm>
using namespace std;
int n, coordinates[100][2], ans=0, totalunmarked=0;
bool visited[100][100];
char graph[100][100];
void dfs(int x, int y, int eaten){
    if(x==4 and y==4 and eaten==totalunmarked){
//        cout << "happened" << endl;
        ans++;
        return;
    }
    else{
        int dx[4] = {x+1, x, x, x-1};
        int dy[4] = {y, y+1, y-1, y};
        for(int i=0; i<4; i++){
            int dxcur=dx[i];
            int dycur=dy[i];
            if(!visited[dxcur][dycur] and dxcur>=0 and dxcur<5 and dycur>=0 and dycur<5 and graph[dxcur][dycur]!='x'){
                visited[dxcur][dycur]=true;
                dfs(dxcur, dycur, eaten+1);
                visited[dxcur][dycur]=false;
            }
        }
    }
}
int main(){
    cin >> n;
//    if(n==0){
//        cout << 104 << endl;
//        return 0;
//    }
    for(int i=0; i<n; i++){
        cin >> coordinates[i][0] >> coordinates[i][1];
        graph[coordinates[i][0]-1][coordinates[i][1]-1]='x';
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(graph[i][j]!='x'){
                graph[i][j]='.';
                totalunmarked++;
            }
        }
    }
//    cout << totalunmarked << endl;
    visited[0][0]=true;
    dfs(0,0,1);
    cout << ans << endl;
}
