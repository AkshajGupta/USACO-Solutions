#include <iostream>
#include <algorithm>
using namespace std;
struct massforce{
    float mass;
    float force;
    int index;
};

bool massforcecomp(massforce a, massforce b){
    return (a.force/a.mass)<(b.force/b.mass);
}

int keep[10001];

int main(){
    int f, m, n, currentforce, currentmass, counter=0;
    cin >> f >> m >> n;
    massforce arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].force >> arr[i].mass;
        arr[i].index=i;
    }
    // for(int i=0; i<n; i++){
    //     originalarray[i]=arr[i].index;
    // }
    sort(arr, arr+n, massforcecomp);
    currentforce=f;
    currentmass=m;
    for(int i=n-1; i>=0; i--){
        if(arr[i].force/arr[i].mass > currentforce/currentmass){
            currentforce = currentforce+arr[i].force;
            currentmass = currentmass+arr[i].mass;
            keep[counter]=arr[i].index;
            keep[counter]++;
            counter++;
            // counter++;
            // for(int j=0; j<n; j++){
            //     if(arr[j].force==originalarray[j][0] and arr[j].mass==originalarray[j][1]){
            //         cout << i << endl;
            //         break;
            //     }
            // }
        }
        else{
            break;
        }
    }
    sort(keep, keep+10001);
    for(int i=0; i<10001; i++){
        if(keep[i]!=0){
            cout << keep[i] << endl;
        }
    }
    if(counter==0){
        cout << "NONE" << endl;
    }
}
