#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n, m, thecow=0, counter=0;
    long long minn=1000000000000000000;
    cin >> n >> m;
    long long cows[n][2], seats[m][2];
    bool visited[n];
    for(int i=0; i<n; i++){
        cin >> cows[i][0] >> cows[i][1];
        visited[i]=false;
    }
    for(int i=0; i<m; i++){
        cin >> seats[i][0] >> seats[i][1];
    }
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            long long distance = ((cows[i][0]-seats[j][0])*(cows[i][0]-seats[j][0]))+((cows[i][1]-seats[j][1])*(cows[i][1]-seats[j][1]));
            if(distance<minn and !visited[i]){
                thecow=i;
                minn=distance;
            }
        }
        visited[thecow]=true;
        minn=100000000000000000;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            cout << i+1 << endl;
            counter++;
        }
    }
    if(counter==0){
        cout << 0;
    }
}
