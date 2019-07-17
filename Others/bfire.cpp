#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int n, nochair;
    vector <int> visited;
    cin >> n;
    int arr[n];
    for(int i=1; i<=n; i++){
        arr[i-1]=i;
    }
    nochair=1;
    arr[0]=0;
    for(int i=0; i<n; i++){
        int newpos=nochair*2-1;
        while(newpos>n-1){
            newpos-=n;
        }
        if(arr[newpos]==0){
            cout << nochair << endl;
            return 0;
        }
        for(int j=0; j<visited.size(); j++){
            if(newpos==visited[j]){
                int a = visited[j+1]+1;
                if(a==1){
                    cout << 2*(newpos+1) << endl;
                    return 0;
                }
                else{
                    cout << a << endl;
                    return 0;
                }
            }
        }
        visited.push_back(nochair-1);
        nochair=arr[newpos];
        arr[newpos]=arr[i];
//        cout << nochair << endl;
    }
}
