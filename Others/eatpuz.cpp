#include <iostream>
using namespace std;
int main(){
    int n, a, temp, temp2, answer=0;
    cin >> n >> a;
    int arr[a];
    for(int i=0; i<a; i++){
        cin >> arr[i];
    }
    for(int i=0; i<a-1; i++){
        temp2=i;
        while(arr[i]>arr[i+1]){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            i--;
        }
        i=temp2;
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            if(arr[j]+arr[i]<=n and arr[j]+arr[i]>answer and j!=i){
                answer=arr[i]+arr[j];
            }
            if(arr[j]+arr[i]>n){
                break;
            }
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            for(int t=0; t<a; t++){
                if(i!=j and i!=t and t!=j and arr[i]+arr[j]+arr[t]>answer and arr[i]+arr[j]+arr[t]<=n){
                    answer = arr[i]+arr[j]+arr[t];
                }
                if(arr[i]+arr[j]+arr[t]>n){
                    break;
                }
            }
        }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            for(int t=0; t<a; t++){
                for(int f=0; f<a; f++){
                    if(i!=j and i!=t and t!=j and i!=f and j!=f and t!=f and arr[i]+arr[j]+arr[t]+arr[f]>answer and arr[i]+arr[j]+arr[t]+arr[f]<=n){
                    answer = arr[i]+arr[j]+arr[t]+arr[f];
                }
                }
            }
        }
    }
    cout << answer << endl;
}
