#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
using namespace std;
int n, x, y, z;
struct se{
    int start;
    int end;
};
bool secomp(se a, se b){
    return a.start<b.start;
}
int main(){
    int n, x, y, z, counter=0, max=-1, placementend=0, placementstart=0;
    cin >> n >> x >> y >> z;
    se cows[n];
    for(int i=0; i<n; i++){
        cin >> cows[i].start >> cows[i].end;
    }
    sort(cows, cows+n, secomp);
    //        for(int i=0; i<n; i++){
    //            cout << cows[i].start << " " << cows[i].end << endl;
    //        }
    for(int i=0; i<n; i++){
        int searchend=cows[i].end;
        int searchstart=cows[i].start;
        //        cout << search << endl;
        for(int j=i+1; j<n; j++){
            if(cows[j].start<=searchend){
                //                cout << cows[j].start << " " << search << endl;
                counter++;
            }
        }
        if(counter>max){
            max=counter;
            placementend=searchend;
            placementstart=searchstart;
        }
        counter=0;
    }
    //    cout << max << endl;
    int sum=0;
    max=-1;
    //    cout << placementend << " " << placementstart << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cows[j].start<=cows[i].end and cows[j].end>=cows[i].end){
                sum+=y;
            }
            else if(cows[j].end<cows[i].end){
                sum+=z;
            }
            else if(cows[j].start>cows[i].end){
                sum+=x;
            }
        }
        if(sum>max){
            max=sum;
        }
        sum=0;
    }
    //    for(int i=0; i<n; i++){
    //        if(cows[i].start<=placement and cows[i].end>=placement){
    //            sum+=y;
    //        }
    //        else if(cows[i].start<placement and cows[i].end<placement){
    //            sum+=z;
    //        }
    //        else if(cows[i].start>placement and cows[i].end>placement){
    //            sum+=x;
    //        }
    //    }
    cout << max << endl;
    return 0;
}
