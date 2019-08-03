#include <iostream>
using namespace std;
int m, maxx=-1, total=0, p=0, pmax=0;
bool visited[1000][1000];
char graph[1000][1000];
void photosize(int x, int y){
    int a[4] = {x, x, x+1, x-1};
    int b[4] = {y-1, y+1, y, y};
    for(int i=0; i<4; i++){
        int nx=a[i];
        int ny=b[i];
        if(nx>=0 and ny>=0 and nx<m and ny<m and graph[nx][ny]=='#' and !visited[nx][ny]){
//                        cout << nx << " " << ny << " " << endl;
            total++;
            visited[nx][ny]=true;
            for(int j=0; j<4; j++){
                int c[4] = {0, 0, 1, -1};
                int d[4] = {-1, 1, 0, 0};
                int nx2=nx+c[j];
                int ny2=ny+d[j];
                if(graph[nx2][ny2]=='.' or nx2==m or ny2==m or nx2==-1 or ny2==-1){
                    p++;
//                    cout << nx << " " << ny << " " << nx2 << " " << ny2 << endl;
                }
            }
            photosize(nx, ny);
        }
    }
    if(total>maxx){
        maxx=total;
        pmax=p;
    }
    else if(total==maxx and pmax>p){
        pmax=p;
    }
    
    return;
}
int main(){
    int hastagcountermax=0;
    cin >> m;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
            if(graph[i][j]=='#'){
                hastagcountermax++;
            }
        }
    }
    if(hastagcountermax==m*m){
        cout << m*m << " " << m*4 << endl;
        return 0;
    }
//        for(int i=0; i<n; i++){
//            for(int j=0; j<m; j++){
//                cout << graph[i][j];
//            }
//            cout << endl;
//        }
//    return 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]=='#' and !visited[i][j]){
                total=1;
                p=0;
                visited[i][j]=true;
                for(int h=0; h<4; h++){
                    int c[4] = {0, 0, 1, -1};
                    int d[4] = {-1, 1, 0, 0};
                    int nx2=i+c[h];
                    int ny2=j+d[h];
                    if(graph[nx2][ny2]=='.' or nx2==m or ny2==m or nx2==-1 or ny2==-1){
                        p++;
                        //                    cout << nx << " " << ny << " " << nx2 << " " << ny2 << endl;
                    }
                }
                photosize(i,j);
            }
        }
    }
    cout << maxx << " " << pmax << endl;
    return 0;
}
