#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, cclcounter=0, ccwlcounter=0;
    cin >> n;
    int guesses[n];
    int ccl[n], ccwl[n];
    for(int i=0; i<n; i++){
        cin >> guesses[i] >> ccl[i] >> ccwl[i];
    }
    for(int i=1000; i<=9999; i++){
        //        cout << i << endl;
        ccwlcounter=0;
        cclcounter=0;
        int ones=i%10;
        int tens=(i/10)%10;
        int hundreds=(i/100)%10;
        int thousands=(i/1000)%10;
        for(int j=0; j<n; j++){
            int onesoriginal=guesses[j]%10;
            int tensoriginal=(guesses[j]/10)%10;
            int hundredsoriginal=(guesses[j]/100)%10;
            int thousandsoriginal=(guesses[j]/1000)%10;
            bool onesoriginalpicked=false, tensoriginalpicked=false, hundredsoriginalpicked=false, thousandsoriginalpicked=false;
            bool onespicked=false, tenspicked=false, hundredspicked=false, thousandspicked=false;
            //            cout << onesoriginal << tensoriginal << hundredsoriginal << thousandsoriginal;
            //            return 0;
            //check for ccl
            if(ones==onesoriginal){
                cclcounter++;
                onespicked=true;
                onesoriginalpicked=true;
//                cout << "fO" << endl;
            }
            if(tens==tensoriginal){
                cclcounter++;
                tenspicked=true;
                tensoriginalpicked=true;
//                cout << "qO" << endl;
            }
            if(hundreds==hundredsoriginal){
                cclcounter++;
                hundredspicked=true;
                hundredsoriginalpicked=true;
//                cout << "cO" << endl;
            }
            if(thousands==thousandsoriginal){
                cclcounter++;
                thousandspicked=true;
                thousandsoriginalpicked=true;
//                cout << "dO" << endl;
            }
            //end check for ccl; start check for ccwl
            if(!onespicked and ones!=onesoriginal and ((ones==tensoriginal and !tensoriginalpicked) or (ones==hundredsoriginal and !hundredsoriginalpicked) or (ones==thousandsoriginal and !thousandsoriginalpicked))){
                ccwlcounter++;
//                                cout << "hI" << endl;
            }
            if(!tenspicked and tens!=tensoriginal and ((tens==onesoriginal and !onesoriginalpicked) or (tens==hundredsoriginal and !hundredsoriginalpicked) or (tens==thousandsoriginal and !thousandsoriginalpicked))){
                ccwlcounter++;
//                                cout << "cI" << endl;
            }
            if(!hundredspicked and hundreds!=hundredsoriginal and ((hundreds==onesoriginal and !onesoriginalpicked) or( hundreds==tensoriginal and !tensoriginalpicked) or (hundreds==thousandsoriginal and !thousandsoriginalpicked))){
                ccwlcounter++;
//                                cout << "dI" << endl;
            }
            if(!thousandspicked and thousands!=thousandsoriginal and ((thousands==onesoriginal and !onesoriginalpicked) or (thousands==tensoriginal and !tensoriginalpicked) or (thousands==hundredsoriginal and !hundredsoriginalpicked))){
                ccwlcounter++;
//                                cout << "pI" << endl;
            }
//                         cout << cclcounter << " " << ccwlcounter << endl;
            if(ccwlcounter!=ccwl[j]){
                break;
            }
            if(cclcounter!=ccl[j]){
                break;
            }
            if(j==n-1){
                cout << i << endl;
                return 0;
            }
            ccwlcounter=0;
            cclcounter=0;
        }
    }
    cout << "NONE" << endl;
}
