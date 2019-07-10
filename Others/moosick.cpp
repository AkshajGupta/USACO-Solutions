#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int total1[1000000];
int main(){
    int notes, killnotes, counter=0, total=0;
    cin >> notes;
    int song[notes];
    for(int i=0; i<notes; i++){
        cin >> song[i];
    }
    cin >> killnotes;
    int kill[killnotes];
    for(int i=0; i<killnotes; i++){
        cin >> kill[i];
    }
    sort(kill, kill+killnotes);
    for(int i=0; i<notes-killnotes+1; i++){
        int temparray[killnotes];
        for(int q=0; q<killnotes; q++){
            temparray[q]=song[i+q];
        }
        sort(temparray, temparray+killnotes);
//        for(int a=0; a<killnotes; a++){
//            cout << temparray[a] << " ";
//        }
        int something=temparray[0]-kill[0];
        for(int j=1; j<killnotes; j++){
            if(temparray[j]-kill[j]==something){
                counter++;
//                cout << counter << endl;
            }
        }
        if(counter==killnotes-1){
            total1[total]=i+1;
            total++;
        }
        counter=0;
    }
    cout << total << endl;
    for(int i=0; i<total; i++){
        cout << total1[i] << endl;
    }
}
