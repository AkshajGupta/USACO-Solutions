#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int main(){
    int n, counter=0, total=0, length=0, maxx=-10000;
    cin >> n;
    int original[n], fj[n];
    for(int i=0; i<n; i++){
        cin >> original[i];
    }
    for(int i=0; i<n; i++){
        cin >> fj[i];
    }
    for(int i=0; i<n; i++){
        if(original[i]!=fj[i]){
            counter=i;
            int temp=original[counter];
            original[counter]=0;
            while(true){
                int temp1=temp;
                for(int j=0; j<n; j++){
                    if(fj[j]==temp){
                        counter=j;
                        break;
                    }
                }
                temp=original[counter];
                original[counter]=temp1;
//                for(int i=0; i<n; i++){
//                    cout << original[i] << " ";
//                }
//                cout << endl;
//                cout << length << endl;
                length++;
                if(length>maxx){
                    maxx=length;
                }
                if(temp==0){
                    original[counter]=fj[counter];
                    break;
                }
            }
            length=0;
            total++;
        }
    }
    if(maxx==-10000){
        maxx=-1;
    }
    cout << total << " " << maxx << endl;
}
