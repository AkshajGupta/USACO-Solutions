#include <iostream>
#include <vector>
using namespace std;
int main(){
    bool printed=false;
    int cows, ropes;
    cin >> cows >> ropes;
    vector <int> ans;
    int connections[ropes][2];
    for(int i=0; i<ropes; i++){
        cin >> connections[i][0] >> connections[i][1];
        if(connections[i][0]==1){
            ans.push_back(connections[i][1]);
//            cout << connections[i][0] << " " << connections[i][1] << endl;
        }
        else if(connections[i][1]==1){
            ans.push_back(connections[i][0]);
//            cout << connections[i][0] << " " << connections[i][1] << endl;
        }
    }
    
    for(int i=0; i<ropes; i++){
        
        bool found1=false;
        bool found2=false;
        
            for(int k=0; k<ans.size(); k++){
                if(ans[k]==connections[i][0] or connections[i][0]==1){
                    found1=true;
                }
                if(ans[k]==connections[i][1] or connections[i][1]==1){
                    found2=true;
                }
            }
        if(found1 and found2){
            
        }
            else if(found1) ans.push_back(connections[i][1]);
            else if(found2) ans.push_back(connections[i][0]);
        
    }
    
    for(int i=0; i<ropes; i++){
        
        bool found1=false;
        bool found2=false;
        
            for(int k=0; k<ans.size(); k++){
                if(ans[k]==connections[i][0] or connections[i][0]==1){
                    found1=true;
                }
                if(ans[k]==connections[i][1] or connections[i][1]==1){
                    found2=true;
                }
            }
        if(found1 and found2){
            
        }
            else if(found1) ans.push_back(connections[i][1]);
            else if(found2) ans.push_back(connections[i][0]);
        
    }
//    cout << ans.size() << endl;
    for(int j=2; j<=cows; j++){
        bool print=true;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]==j){
                print=false;
                break;
            }
        }
        if(print){
            printed=true;
            cout << j << endl;
        }
    }
    if(!printed) cout << 0 << endl;
    return 0;
}
