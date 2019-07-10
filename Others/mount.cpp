#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
    using namespace std;
    int main(){
        int n, heightcounter=0, start, end, maxx=-10000, temp=0, uhohcounter=0;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(temp==arr[i]){
                uhohcounter++;
            }
            temp=arr[i];
        }
        if(uhohcounter==n-1){
            cout << n << endl;
            return 0;
        }
        for(int i=0; i<n; i++){
            int iholder=i-1;
            if(i==n-1){
                if(arr[i-1]<arr[i]){
                    iholder=i;
                    while(iholder>0){
                        heightcounter=arr[iholder];
                        iholder--;
                        if(arr[iholder]>heightcounter){
                            iholder++;
                            break;
                        }
                    }
                }
                start=iholder;
                end=n-1;
                if(end-start+1>maxx){
                    maxx=end-start+1;
                }
            }
            if(arr[i]<heightcounter){
                while(iholder>0){
                    heightcounter=arr[iholder];
                    iholder--;
                    if(arr[iholder]>heightcounter){
                        iholder++;
                        break;
                    }
                }
                start=iholder;
                iholder=i-1;
                while(iholder<n){
                    heightcounter=arr[iholder];
                    iholder++;
                    if(arr[iholder]>heightcounter){
                        iholder--;
                        break;
                    }
                }
                end=iholder;
                if(end-start+1>maxx){
                    maxx=end-start+1;
                }
            }
            heightcounter=arr[i];
        }
        if(maxx>n){
            cout << n << endl;
            return 0;
        }
        else{
        cout << maxx << endl;
        }
    }
