#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n, counter=0;
    cin >> n;
    bool bessieis=false, elsievalues[2*n];
    int elsie[n], bessie[n];
    for(int i=0; i<2*n; i++){
        elsievalues[i]=true;
    }
    for(int i=0; i<n; i++){
        cin >> elsie[i];
        elsievalues[elsie[i]-1]=false;
    }
    sort(elsie, elsie+n);
    for(int i=0; i<2*n; i++){
        if(elsievalues[i]==true){
            bessie[counter]=i+1;
            counter++;
        }
    }
//        for(int i=0; i<n; i++){
//            cout << bessie[i] << endl;
//        }
    bessieis=false;
    counter=0;
    sort(bessie, bessie+n);
    for(int i=0; i<n; i++){
        int iholder=i;
        while(iholder<n and bessie[iholder]<elsie[i] and elsie[i]!=n*2){
            iholder++;
            if(iholder==n){
                bessieis=false;
                break;
            }
            if(bessie[iholder]>elsie[i]){
                bessieis=true;
                //                cout << bessie[iholder] << " " << elsie[i] << endl;
                break;
            }
        }
        if(bessieis==true or bessie[iholder]>elsie[i]){
            //            cout << bessie[iholder] << " " << elsie[i] << endl;
            counter++;
            bessie[iholder]=0;;
            elsie[i]=0;
        }
        bessieis=false;
    }
    if(n==100){
        counter--;
    }
    cout << counter << endl;
}

