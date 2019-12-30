#include <iostream>
#include <algorithm>
using namespace std;

struct cows{
    
    int start;
    int end;
    
};

bool cowscomp(cows a, cows b){
    
    return a.start<b.start;
    
}

int main(){
    
    int n;
    
    cin >> n;
    
    cows crossings[n];
    
    int maxxpos[n], minnpos[n];
    
    for(int i=0; i<n; i++){
        cin >> crossings[i].start >> crossings[i].end;
    }
    
    sort(crossings, crossings+n, cowscomp);
    
//    for(int i=0; i<n; i++){
//
//        cout << crossings[i].start << " " << crossings[i].end << endl;
//
//    }
    
    int cowcounter=0, minn=1000000, maxx=-1000000;
    
    for(int i=n-1; i>=0; i--){
        
        if(crossings[i].end<minn) minn=crossings[i].end;
        
        maxxpos[i]=minn;
        
    }
    
    for(int i=0; i<n; i++){
        
        if(crossings[i].end>maxx) maxx=crossings[i].end;
        
        minnpos[i]=maxx;
        
    }
    
    for(int i=0; i<n; i++){
        
//        cout << maxxpos[i] << " " << minnpos[i] << endl;
        
        if(maxxpos[i]>=crossings[i].end and crossings[i].end>=minnpos[i]) cowcounter++;
//            cout << i << endl;
        
    }
    
    cout << cowcounter << endl;
    
    return 0;
}
