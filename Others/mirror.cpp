#include <iostream>
using namespace std;
int n, m, counter=0, a;
int l[4],r[4],dx[4],dy[4], ans=0;
char graph[1000][1000];
void bounces(int x, int y, int cur){
    l[0]=3; l[1]=2; l[2]=1; l[3]=0; r[0]=1; r[1]=0; r[2]=3; r[3]=2; dx[0]=1; dx[1]=0; dx[2]=-1; dx[3]=0; dy[0]=0; dy[1]=1; dy[2]=0; dy[3]=-1;
    counter=0;
    while(x>=0 and y>=0 and x<n and y<m){
        counter++;
        if(graph[x][y]=='/'){
            cur=l[cur];
        }
        else{
            cur=r[cur];
        }
        //            cout << cur << endl;
        x=x+dx[cur];
        y=y+dy[cur];
        //            cout << x << " " << y << endl;
    }
    a=counter;
    return;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
        }
    }
    for(int i=0; i<n; i++){
        bounces(i,0,1);
        if(a>ans){
            ans=a;
        }
        bounces(i,m-1,3);
        if(a>ans){
            ans=a;
        }
        //        cout << c1 << " " << c2 << endl;
    }
    //    cout << "eeeeeeeeee" << endl;
    for(int i=0; i<m; i++){
        bounces(0,i,0);
        if(a>ans){
            ans=a;
        }
        bounces(n-1, i, 2);
        if(a>ans){
            ans=a;
        }
        //        cout << c3 << " " << c4 << endl;
    }
    cout << ans << endl;
}
