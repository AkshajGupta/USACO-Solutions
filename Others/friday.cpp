#include <iostream>
using namespace std;
int main(){
    int n, sunday=1, monday=2, tueday=3, wednsday=4, thursday=5, friday=6, saturday=7, current=2;
    int arr[7];
    cin >> n;
    for(int i=0; i<7; i++){
        arr[i]=0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<13; j++){
            if(j==1 or j==3 or j==5 or j==7 or j==8 or j==10 or j==12){
                current=current+12;
                current=current%7;
                arr[current]++;
                current=current+19;
                current=current%7;
            }
            if(j==2 and (i+1900)%4==0){
                if((i+1900)%100==0){
                    if((i+1900)%400!=0){
                    current=current+12;
                    current=current%7;
                    arr[current]++;
                    current=current+16;
                    current=current%7;
                    }
                }
                else{
                current=current+12;
                current=current%7;
                arr[current]++;
                current=current+17;
                current=current%7;
                }
            }
            else if(j==2){
                current=current+12;
                current=current%7;
                arr[current]++;
                current=current+16;
                current=current%7;
            }
            if(j==4 or j==6 or j==9 or j==11){
                current=current+12;
                current=current%7;
                arr[current]++;
                current=current+18;
                current=current%7;
            }
        }
    }
    for(int i=0; i<7; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
