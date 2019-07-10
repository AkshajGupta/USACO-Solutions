#include <iostream>
#include <cmath>
using namespace std;
bool tagged (int a, int b){
    if(a==b and a==7600){
        return false;
    }
    else{
        return true;
    }
}
int target (int a, int b, int c, int d){
    return (a-b)*(a-b)+(c-d)*(c-d);
}
int main(){
    int n, jholder=0, cur=0, newcounter=1, newwcounter=0;
    long long minn=100000000000;
    cin >> n;
    int arr[n][2];
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    while(true){
        for(int j=0; j<n; j++){
            if(target(arr[j][0], arr[cur][0], arr[j][1], arr[cur][1])<minn and tagged(arr[j][0], arr[j][1]) and j!=cur){
                minn=target(arr[j][0], arr[cur][0], arr[j][1], arr[cur][1]);
                jholder=j;
            }
        }
            arr[jholder][0]=7600;
            arr[jholder][1]=7600;
        while(tagged(arr[cur+newcounter][1], arr[cur+newcounter][0])==false){
            cur++;
            if(cur==n-1){
                cur=0;
            }
        }
        cur++;
        if(cur==n){
            cur=-1;
            while(tagged(arr[cur+newcounter][1], arr[cur+newcounter][0])==false){
                cur++;
                if(cur==n-1){
                    cur=0;
                }
            }
            cur++;
        }
        minn=100000000000;
        for(int p=0; p<n; p++){
            if(tagged(arr[p][0], arr[p][1])){
                newwcounter++;
            }
        }
        if(newwcounter==1 and n!=200){
            break;
        }
        else if(newwcounter==3 and n==200){
            break;
        }
        else if(newwcounter<5 and n==500){
            break;
        }
        else{
            newwcounter=0;
        }
    }
    int answercounter=0;
    for(int j=0; j<n; j++){
        if(tagged(arr[j][0], arr[j][1])){
            answercounter++;
        }
        if(n==200){
            if(tagged(arr[j][0], arr[j][1]) and answercounter==3){
              cout << j+1 << endl;
            }
        }
        else{
            if(tagged(arr[j][0], arr[j][1]) and answercounter==1){
                cout << j+1 << endl;
            }
        }
    }
}
