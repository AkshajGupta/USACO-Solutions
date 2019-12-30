#include <iostream>
using namespace std;
int arr[1001][1001];
int main(){
    int size, evil, counter=0;
    cin >> size >> evil;
    for(int i=0; i<evil; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        arr[x][y]++;
        for(int k=1; k<size; k++){
            if(x+k<size and y+k<size)
            arr[x+k][y+k]++;
            if(x-k>=0 and y-k>=0)
            arr[x-k][y-k]++;
            if(x+k<size and y-k>=0)
            arr[x+k][y-k]++;
            if(x-k>=0 and y+k<size)
            arr[x-k][y+k]++;
            if(y+k<size)
            arr[x][y+k]++;
            if(y-k>=0)
            arr[x][y-k]++;
            if(x+k<size)
            arr[x+k][y]++;
            if(x-k>=0)
            arr[x-k][y]++;
        }
    }
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(arr[i][j]==evil)
                counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
