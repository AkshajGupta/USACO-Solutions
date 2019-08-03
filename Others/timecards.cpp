#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct cow{
    int cowid;
    string ss;
    int hours;
    int minutes;
};
bool cowcomp (cow a, cow b){
    return a.cowid<b.cowid;
}
int main(){
    int n, m, counter=0, mcounter=0;
    cin >> n >> m;
    int arr[m];
    for(int i=0; i<m; i++){
        arr[i]=0;
    }
    cow cows[m];
    for(int i=0; i<m; i++){
        cin >> cows[i].cowid >> cows[i].ss >> cows[i].hours >> cows[i].minutes;
//        temp[i].cowid=cows[i].cowid;
//        temp[i].ss=cows[i].ss;
//        temp[i].hours=cows[i].hours;
//        temp[i].hours=cows[i].minutes;
    }
//    sort(cows, cows+m, cowcomp);
//    for(int i=0; i<m; i++){
//        cout << cows[i].cowid << " " << cows[i].ss << " " << cows[i].hours << " " << cows[i].minutes << endl;
//    }
    for(int i=0; i<m; i++){
        for(int j=i; j<m; j++){
            if(cows[i].cowid==cows[j].cowid and j!=i and cows[i].ss!="STOP" and cows[j].ss!="START"){
//                cout << i << " " << j << endl;
                arr[cows[i].cowid-1]+=abs((cows[i].hours-cows[j].hours)*60 + (cows[i].minutes-cows[j].minutes));
//                cout << arr[cows[i].cowid-1] << endl;
//                cows[j].cowid=0;
                break;
            }
        }
    }
    
    
    for(int i=0; i<n; i++){
        cout << arr[i]/60 << " " << arr[i]%60 << endl;
    }
//    for(int i=0; i<m; i++){
//
//    }
}
