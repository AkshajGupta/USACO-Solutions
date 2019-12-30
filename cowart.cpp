#include <iostream>
using namespace std;
int n, m, maxx=-1, total=0;
bool visited[1000][1000];
char graph[1000][1000];
void photosizeR(int x, int y){
    int a[4] = {x, x, x+1, x-1};
    int b[4] = {y-1, y+1, y, y};
    for(int i=0; i<4; i++){
        int nx=a[i];
        int ny=b[i];
        if(nx>=0 and ny>=0 and nx<n and ny<n and graph[nx][ny]=='R' and !visited[nx][ny]){
//            cout << nx << " " << ny << " " << endl;
            visited[nx][ny]=true;
            photosizeR(nx, ny);
        }
    }
    return;
}
void photosizeB(int x, int y){
    int a[4] = {x, x, x+1, x-1};
    int b[4] = {y-1, y+1, y, y};
    for(int i=0; i<4; i++){
        int nx=a[i];
        int ny=b[i];
        if(nx>=0 and ny>=0 and nx<n and ny<n and graph[nx][ny]=='B' and !visited[nx][ny]){
//            cout << nx << " " << ny << " " << endl;
            visited[nx][ny]=true;
            photosizeB(nx, ny);
        }
    }
    return;
}
void photosizeG(int x, int y){
    int a[4] = {x, x, x+1, x-1};
    int b[4] = {y-1, y+1, y, y};
    for(int i=0; i<4; i++){
        int nx=a[i];
        int ny=b[i];
        if(nx>=0 and ny>=0 and nx<n and ny<n and graph[nx][ny]=='G' and !visited[nx][ny]){
//            cout << nx << " " << ny << " " << endl;
            visited[nx][ny]=true;
            photosizeG(nx, ny);
        }
    }
    return;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }
    int Rcounter=0, Bcounter=0, Gcounter=0, CRcounter=0, CBcounter=0;
    //Red Human
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j]=='R' and !visited[i][j]){
                photosizeR(i,j);
                Rcounter++;
            }
        }
    }
    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j]=='B' and !visited[i][j]){
                    photosizeB(i,j);
                    Bcounter++;
                }
            }
        }
    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j]=='G' and !visited[i][j]){
                    photosizeG(i,j);
                    Gcounter++;
                }
            }
        }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j]=false;
            if(graph[i][j]=='G'){
                graph[i][j]='R';
            }
        }
    }
    
    //cow
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j]=='R' and !visited[i][j]){
                photosizeR(i,j);
                CRcounter++;
            }
        }
    }
    for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
               if(graph[i][j]=='B' and !visited[i][j]){
                   photosizeB(i,j);
                   CBcounter++;
               }
           }
       }
    cout << Rcounter+Bcounter+Gcounter << " " << CBcounter + CRcounter << endl;
    return 0;
}
