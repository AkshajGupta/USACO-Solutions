    #include <iostream>
#include <algoirthm>
#include <cmath>
using namespace std;
int main(){
    int bowls[20], bowls2[20],total=0, ans=1000000, zerocounter=0;
    
    memset(bowls, 0,sizeof(bowls));
    memset(bowls2, 0,sizeof(bowls2));
    for(int i=0; i<20; i++){
        cin >> bowls[i];
        bowls2[i]=bowls[i];
        if(bowls[i]==0){
            zerocounter++;
        }
        //        cout << bowls[i] << " " << bowls2[i] << endl;
    }
//    for(int i=0; i<20; i++){
//        cout << bowls2[i] << " ";
//    }
    bowls[0] ^= 1;
    bowls[1] ^= 1;
    total++;
    for(int i=0; i<20; i++){
        if(bowls[i]==1 and bowls[i-1]==1){
            bowls[i-1]=0;
            bowls[i]=0;
            total++;
            if(bowls[i+1]==0){
                bowls[i+1]=1;
            }
            else{
                bowls[i+1]=0;
            }
        }
        else if(bowls[i]==0 and bowls[i-1]==1){
            bowls[i-1]=0;
            bowls[i]=1;
            total++;
            if(bowls[i+1]==0){
                bowls[i+1]=1;
            }
            else{
                bowls[i+1]=0;
            }
        }
    }
//    cout << total << endl;
    if(ans>total){
        ans=total;
    }
    total=0;
    //    for(int i=0; i<20; i++){
    //        cout << bowls2[i] << " ";
    //    }
    bowls2[0]=0;
    for(int i=0; i<20; i++){
        if(bowls2[i]==1 and bowls2[i-1]==1){
            bowls2[i-1]=0;
            bowls2[i]=0;
            total++;
            if(bowls2[i+1]==0){
                bowls2[i+1]=1;
            }
            else{
                bowls2[i+1]=0;
            }
        }
        else if(bowls2[i]==0 and bowls2[i-1]==1){
            bowls2[i-1]=0;
            bowls2[i]=1;
            total++;
            if(bowls2[i+1]==0){
                bowls2[i+1]=1;
            }
            else{
                bowls2[i+1]=0;
            }
        }
    }
//    cout << total << endl;
    if(ans>total and total!=0){
        ans=total;
    }
    if(zerocounter==20){
        cout << 0 << endl;
    }
    else{
        cout << ans << endl;
    }
    }
