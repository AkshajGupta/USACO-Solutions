#include <iostream>
using namespace std;
int main(){
    int b, c, counter=0, parentcounter=0, bullcounter=0, cowcounter=0, temparraycounter=0, temparray[400];
    cin >> b >> c;
    string bulls[b], cows[c];
    for(int i=0; i<400; i++){
        temparray[i]=-1;
    }
    for(int i=0; i<b; i++){
        cin >> bulls[i];
    }
    for(int i=0; i<c; i++){
        cin >> cows[i];
    }
    while(bullcounter<b){
        for(int i=0; i<b; i++){
            for(int j=0; j<25; j++){
                if((cows[cowcounter][j]==bulls[i][j] or bulls[bullcounter][j]==bulls[i][j]) and i!=bullcounter){
                    counter++;
                }
                if(counter==25){
                    parentcounter++;
                }
            }
            counter=0;
        }
        counter=0;
        for(int i=0; i<c; i++){
            for(int j=0; j<25; j++){
                if((cows[cowcounter][j]==cows[i][j] or bulls[bullcounter][j]==cows[i][j]) and i!=cowcounter){
                    counter++;
                }
                if(counter==25){
                    parentcounter++;
                }
            }
            counter=0;
        }
        counter=0;
        if(cowcounter<c-1){
            cowcounter++;
        }
        else{
            cowcounter=0;
            bullcounter++;
        }
        temparray[temparraycounter]=parentcounter;
        temparraycounter++;
        parentcounter=0;
    }
    for(int i=0; i<400; i++){
        if(i%c==0 and i!=0){
            cout << endl;
        }
        if(temparray[i]==-1){
            break;
        }
        else{
            cout << temparray[i] << " ";
        }
    }
}
