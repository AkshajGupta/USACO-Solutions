#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

struct input{
    string names;
};

int main(){
    
    cin >> n;
    input cows[n];
    vector <string> solve, temp;
    
    //INPUT and sort INPUT
    for(int i=0; i<n; i++){
        bool found=false;
        string arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        string s = arr[0]+'-'+arr[1]+'-'+arr[2];
                temp.push_back(s);
        //        cout << s << endl;
                for(int j=0; j<solve.size(); j++){
                    if(solve[j]==s){
                        found=true;
                        break;
                    }
                }
                if(!found){
                    solve.push_back(s);
                }
    }
    
    //CHECK
    int counter=0, maxx=-1;
    for(int i=0; i<solve.size(); i++){
        counter=0;
        for(int j=0; j<temp.size(); j++){
            if(solve[i]==temp[j]) counter++;
        }
        if(counter>maxx){
            maxx=counter;
        }
    }
    
    //PRINT ANSWER
    cout << maxx << endl;
    
    return 0;
}
