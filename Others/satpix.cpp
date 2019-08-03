#include <iostream>
using namespace std;
int n, m, maxx=-1, total=0;
bool visited[1000][1000];
char graph[1000][1000];
void photosize(int x, int y){
    int a[4] = {x, x, x+1, x-1};
    int b[4] = {y-1, y+1, y, y};
    for(int i=0; i<4; i++){
        int nx=a[i];
        int ny=b[i];
        if(nx>=0 and ny>=0 and nx<n and ny<m and graph[nx][ny]=='*' and !visited[nx][ny]){
//            cout << nx << " " << ny << " " << endl;
            total++;
            visited[nx][ny]=true;
            photosize(nx, ny);
        }
    }
    if(total>maxx){
        maxx=total;
    }
    return;
}
int main(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
        }
    }
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout << graph[i][j];
//        }
//        cout << endl;
//    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]=='*' and !visited[i][j]){
                //                cout << "start " << i << " " << j << endl;
                total=0;
                photosize(i,j);
                //                return 0;
            }
        }
    }
    cout << maxx << endl;
    return 0;
}
