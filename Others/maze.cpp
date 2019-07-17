bool visited[100][100];
int n, m, charpositionx, charpositiony, charcounter=0, nx, ny;
char graph[100][100];
char s[100000];
string a;
bool bfs(int x, int y){
//    cout << x << " " << y << endl;
    if(graph[x][y]=='F'){
//        for(int i=0; i<charcounter; i++){
//            a+=s[i];
//        }
        return true;
    }
    else{
        int dx[4] = {x+1, x, x, x-1};
        int dy[4] = {y, y+1, y-1, y};
        for(int i=0; i<4; i++){
            nx=dx[i];
            ny=dy[i];
//                          cout << nx << " " << ny << endl;
            if(nx!=-1 and ny!=-1 and nx!=n and ny!=m and (graph[nx][ny]=='.' or graph[nx][ny]=='F') and !visited[nx][ny]){
                if(i==0){
                    visited[nx][ny]=true;
                    s[charcounter]='D';
                    charcounter++;
                    if(bfs(nx, ny))
                        return true;

                    visited[nx][ny]=false;
                    s[charcounter]='-';
                    charcounter--;
                    
                }
                else if(i==1){
                    visited[nx][ny]=true;
                    s[charcounter]='R';
                    charcounter++;
                    if(bfs(nx, ny))
                        return true;

                    visited[nx][ny]=false;
                    s[charcounter]='-';
                    charcounter--;
                    
                }
                else if(i==2){
                    visited[nx][ny]=true;
                    s[charcounter]='L';
                    charcounter++;
                    if(bfs(nx, ny))
                        return true;

                    visited[nx][ny]=false;
                    s[charcounter]='-';
                    charcounter--;
                    
                }
                else if(i==3){
                    visited[nx][ny]=true;
                    s[charcounter]='U';
                    charcounter++;

                    if(bfs(nx, ny))
                        return true;
                    visited[nx][ny]=false;
                    s[charcounter]='-';
                    charcounter--;
                    
                }
            }
           
        }
        graph[nx][ny]='#';
         return false;
    }
}
string solve(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
            if(graph[i][j]=='S'){
                charpositionx=i;
                charpositiony=j;
            }
        }
    }
    bfs(charpositionx,charpositiony);
//    cout << a << endl;
    return s;
}
