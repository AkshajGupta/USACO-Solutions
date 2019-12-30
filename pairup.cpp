#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct input{
    int amount;
    int size;
};

bool cowscomp(input a, input b){
    return a.size<b.size;
}

int main(){
    int n;
    cin >> n;
    input cows[n];
    for(int i=0; i<n; i++){
        cin >> cows[i].amount >> cows[i].size;
    }
    
    sort(cows, cows+n, cowscomp);
    
    int countermin=0, countermax=n-1, maxx=-1;
    
    while(countermin<countermax){
        int subtract=min(cows[countermin].amount, cows[countermax].amount);
        cows[countermin].amount-=subtract;
        cows[countermax].amount-=subtract;
        if(cows[countermin].size+cows[countermax].size>maxx){
//            cout << cows[countermin].size+cows[countermax].size << endl;
            maxx=cows[countermin].size+cows[countermax].size;
        }
        if(cows[countermin].amount==0) countermin++;
        
        if(cows[countermax].amount==0) countermax--;
//        cout << countermin << " " << countermax << endl;
    }
    cout << maxx << endl;
    return 0;
}
