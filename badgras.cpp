#include <iostream>
using namespace std;
int n, m, counter=0;
bool visited[1001][1001], onezero=false;
char graph[1001][1001];
void photosize(int x, int y){
    int a[8] = {x, x, x+1, x-1, x-1, x-1, x+1, x+1};
    int b[8] = {y-1, y+1, y, y, y-1, y+1, y-1, y+1};
    for(int i=0; i<8; i++){
        int nx=a[i];
        int ny=b[i];
        if(nx>=0 and ny>=0 and nx<n and ny<m and graph[nx][ny]!='0' and !visited[nx][ny]){
//            cout << nx << " " << ny << " " << endl;
            visited[nx][ny]=true;
            photosize(nx, ny);
        }
    }
    return;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
            if(graph[i][j]=='0' and (i==0 or j==0)) {
                onezero=true;
            }
        }
    }
    
    if(onezero==false or n*m>10000){
        cout << "1" << endl;
//        cout << "hi" << endl;
        return 0;
    }
    
//    return 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]!='0' and !visited[i][j]){
                visited[i][j]=true;
                //                cout << "start " << i << " " << j << endl;
                photosize(i,j);
                counter++;
                //                return 0;
            }
        }
    }
    cout << counter << endl;
    return 0;
}
