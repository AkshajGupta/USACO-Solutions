#include <iostream>
using namespace std;
int arr[1000][1000];
bool visited[1000][1000];
int main(){
    int n, curx=0, cury=0;
    cin >> n;
    int counter=1;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    while(true){
        while(curx<=n-1){
            if(!visited[cury][curx]){
                arr[cury][curx]=counter;
                counter++;
                visited[cury][curx]=true;
                curx++;
            }
            else{
                break;
            }
        }
            curx--;
            cury++;
        if(visited[cury][curx]){
            for(int l=0; l<n; l++){
                for(int m=0; m<n; m++){
                    cout << arr[l][m] << " ";
                }
                cout << endl;
            }
            return 0;
        }
        while(cury<=n-1){
            if(!visited[cury][curx]){
                arr[cury][curx]=counter;
                counter++;
                visited[cury][curx]=true;
                cury++;
            }
            else{
                break;
            }
        }
            cury--;
            curx--;
        if(visited[cury][curx] and visited[cury-1][curx] and visited[cury+1][curx] and visited[cury][curx-1] and visited[cury][curx+1]){
            for(int l=0; l<n; l++){
                for(int m=0; m<n; m++){
                    cout << arr[l][m] << " ";
                }
                cout << endl;
            }
            return 0;
        }
        while(curx>=0){
            if(!visited[cury][curx]){
                arr[cury][curx]=counter;
                counter++;
                visited[cury][curx]=true;
                curx--;
            }
            else{
                break;
            }
        }
            curx++;
            cury--;
        if(visited[cury][curx] and visited[cury-1][curx] and visited[cury+1][curx] and visited[cury][curx-1] and visited[cury][curx+1]){
            for(int l=0; l<n; l++){
                for(int m=0; m<n; m++){
                    cout << arr[l][m] << " ";
                }
                cout << endl;
            }
            return 0;
        }
        while(cury>=0){
            if(!visited[cury][curx]){
                arr[cury][curx]=counter;
                counter++;
                visited[cury][curx]=true;
                cury--;
            }
            else{
                break;
            }
        }
            curx++;
            cury++;
//        cout << cury << endl;
        if(visited[cury][curx] and visited[cury-1][curx-1]){
            for(int l=0; l<n; l++){
                for(int m=0; m<n; m++){
                    cout << arr[l][m] << " ";
                }
                cout << endl;
            }
            return 0;
        }
    }
}
