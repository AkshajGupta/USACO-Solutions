#include <iostream>
using namespace std;
int main(){
    string s;
    
    int leftcounter=0, rightcounter=0, ans=0;
    
    cin >> s;
    
    for(int i=0; i<s.length()-1; i++){
        
        if(s.substr(i,2)=="(("){
            
            leftcounter++;
            
            ans-=rightcounter;
            
        }
            
        if(s.substr(i,2)=="))"){
            
            rightcounter++;
            
        }
        
    }
    
    cout << ans+rightcounter*leftcounter << endl;
    
    return 0;
    
}
