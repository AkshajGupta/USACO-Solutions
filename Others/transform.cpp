#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int n;
struct graph{
    char character[100][100];
};
graph oggraph1, comparegraph;
//char graph[100][100], newgraph[100][100], tempgraph[100][100];
graph rotate90(graph oggraph){
    graph tempgraph;
//    cout << "hi " << n << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tempgraph.character[j][n-1-i]=oggraph.character[i][j];
        }
    }
    return tempgraph;
}
graph rotate180(graph oggraph){
    graph tempgraph;
    tempgraph = rotate90(oggraph);
    tempgraph = rotate90(tempgraph);
    return tempgraph;
}
graph rotate270(graph oggraph){
    graph tempgraph;
    tempgraph = rotate180(rotate90(oggraph));
    return tempgraph;
}
graph reflect(graph oggraph){
    graph tempgraph;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tempgraph.character[i][n-1-j]=oggraph.character[i][j];
        }
    }
    return tempgraph;
}
graph combination90(graph oggraph){
    graph tempgraph;
    tempgraph = reflect(oggraph);
    tempgraph = rotate90(tempgraph);
    return tempgraph;
}
graph combination180(graph oggraph){
    graph tempgraph;
    tempgraph = reflect(oggraph);
    tempgraph = rotate180(tempgraph);
    return tempgraph;
}
graph combination270(graph oggraph){
    graph tempgraph;
    tempgraph = reflect(oggraph);
    tempgraph = rotate270(tempgraph);
    return tempgraph;
}
int main(){
    int counter=0;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> oggraph1.character[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> comparegraph.character[i][j];
        }
    }
    //test case rotate 90
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(rotate90(oggraph1).character[i][j]==comparegraph.character[i][j]){
                counter++;
            }
//            cout << rotate90(oggraph1).character[i][j] << " " << comparegraph.character[i][j] << endl;
        }
    }
//    cout << counter << endl;
    if(counter==n*n){
        cout << 1 << endl;
        return 0;
    }
    counter=0;
    //test case rotate 180
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(rotate180(oggraph1).character[i][j]==comparegraph.character[i][j]){
                counter++;
            }
//            cout <<rotate180(oggraph1).character[i][j] << " ";
        }
//        cout << endl;
    }
    if(counter==n*n){
        cout << 2 << endl;
        return 0;
    }
    counter=0;
    //test case rotate 270
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(rotate270(oggraph1).character[i][j]==comparegraph.character[i][j]){
                counter++;
            }
        }
    }
    if(counter==n*n){
        cout << 3 << endl;
        return 0;
    }
    counter=0;
    //test case reflect
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(reflect(oggraph1).character[i][j]==comparegraph.character[i][j]){
                counter++;
            }
        }
    }
    if(counter==n*n){
        cout << 4 << endl;
        return 0;
    }
    counter=0;
    //test case combination1
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(combination90(oggraph1).character[i][j]==comparegraph.character[i][j]){
                counter++;
            }
        }
    }
    if(counter==n*n){
        cout << 5 << endl;
        return 0;
    }
    counter=0;
    //test case combination2
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(combination180(oggraph1).character[i][j]==comparegraph.character[i][j]){
                counter++;
            }
        }
    }
    if(counter==n*n){
        cout << 5 << endl;
        return 0;
    }
    counter=0;
    //test case combination3
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(combination270(oggraph1).character[i][j]==comparegraph.character[i][j]){
                counter++;
            }
        }
    }
    if(counter==n*n){
        cout << 5 << endl;
        return 0;
    }
    counter=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(oggraph1.character[i][j]==comparegraph.character[i][j]){
                counter++;
            }
        }
    }
    if(counter==n*n){
        cout << 6 << endl;
        return 0;
    }
    cout << 7 << endl;
    return 0;
}
