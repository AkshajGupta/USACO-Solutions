#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int n, m, counter=0;
    string s;
    cin >> n >> m;
    getline(cin, s);
    string phrases[n], cowphrases[m];
    for(int i=0; i<n; i++){
        getline(cin, phrases[i]);
    }
    // for(int i=0; i<n; i++){
    //     cout << phrases[i] << endl;
    // }
    for(int i=0; i<m; i++){
        getline(cin, cowphrases[i]);
    }
    // for(int i=0; i<m; i++){
    //     cout << cowphrases[i] << endl;
    // }
    sort(phrases, phrases+n);
    //    sort(cowphrases, cowphrases+m);
    int low=0, high=n-1, mid;
    for(int i=0; i<m; i++){
        while(low<high){
            // cout << "hi" << endl;
            mid=(low+high+1)/2;
            // cout << phrases[0] << " " << cowphrases[0] << endl;
            if(phrases[mid].substr(0, min(phrases[mid].length(), cowphrases[i].length()))<=cowphrases[i]){
                low=mid;
                // cout << "yes" << endl;
            }
            else{
                high=mid-1;
            }
        }
        // cout << low << endl;
        if(phrases[low].substr(0, min(phrases[low].length(), cowphrases[i].length()))==cowphrases[i]){
            counter++;
        }
        low=0;
        high=n-1;
    }
    cout << counter << endl;
}
