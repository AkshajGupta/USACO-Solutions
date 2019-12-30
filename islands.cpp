#include <iostream>
#include <algorithm>
using namespace std;

struct input{
    int height;
    int pos;
    char type;
};

bool inputcomp(input a, input b){
    return a.height<b.height;
}

    input islands[100000];

int main(){
    int n, previnput=-1, tempvar, sizecounter=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tempvar;
        if(i==0 or (i>=1 and previnput!=tempvar)){
            islands[sizecounter].height=tempvar;
            islands[sizecounter].pos=i;
            previnput=islands[sizecounter].height;
            sizecounter++;
//            cout << previnput << " " << tempvar  << endl;
        }
        
    }
    
    for(int i=0; i<sizecounter; i++){
        if(islands[i].pos==0){
            if(islands[i].height>islands[i+1].height){
                islands[i].type='P';
            }
            else{
                islands[i].type='Z';
            }
        }
        else if(islands[i].pos==sizecounter-1 and islands[i-1].height<islands[i].height){
            islands[i].type='P';
        }
        else if(islands[i].height<islands[i-1].height and islands[i].height < islands[i+1].height){
            islands[i].type='D';
        }
        else if(islands[i].height>islands[i-1].height and islands[i].height>islands[i+1].height){
            islands[i].type='P';
        }
        else{
            islands[i].type='Z';
        }
    }
    
    sort(islands, islands+sizecounter, inputcomp);
    
//    for(int i=0; i<sizecounter; i++){
//        cout << islands[i].height << " "  << islands[i].pos << " " << islands[i].type << endl;
//    }
    
//    return 0;
    
    int counter=1, cur, prev=1, maxx=1;
    
    for(int i=0; i<sizecounter; i++){
        
        cur = islands[i].height;
        
        if(cur!=prev){
//            cout << cur << endl;
            if(counter>maxx){
                maxx=counter;
            }
        }
            if(islands[i].type=='P'){
                counter--;
            }
            else if(islands[i].type=='D'){
                counter++;
            }
        
        // cout << counter << endl;
        
        prev = islands[i].height;
        
    }
    
    cout << maxx << endl;
    return 0;
    
}
