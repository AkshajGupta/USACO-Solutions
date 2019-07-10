#include <iostream>
using namespace std;
int main(){
    int n, m, counter=0, countingnumber=0, q;
    cin >> n >> m;
    int beats[n];
    for(int i=0; i<n; i++){
        cin >> beats[i];
    }
    for(int i=0; i<m; i++){
        cin >> q;
        while(true){
            countingnumber=countingnumber+beats[counter];
            counter++;
            if(countingnumber>q){
                cout << counter << endl;
                counter=0;
                countingnumber=0;
                break;
            }
        }
        
    }
}
