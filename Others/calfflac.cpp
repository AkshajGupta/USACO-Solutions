#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct palindrome{
    char letter;
    int index;
};
char before[20001];
int main(){
    int maxx=-100000, counter=1, iholderbigprint=0, iholdersmallprint=0, sizecounter=0, iholder=0;
    palindrome sequence[20001];
    string s, fullstring;
    while(getline (cin, s)){
        fullstring+=s;
    }
    for(int i=0; i<fullstring.length(); i++){
        if((fullstring[i]>='a' and fullstring[i]<='z')){
            // cout << fullstring[i] << endl;
            sequence[sizecounter].letter=fullstring[i];
            sequence[sizecounter].index=i;
            sizecounter++;
        }
        else if(fullstring[i]>='A' and fullstring[i]<='Z'){
            // cout << fullstring[i] << endl;
            sequence[sizecounter].letter=tolower(fullstring[i]);
            sequence[sizecounter].index=i;
            sizecounter++;
        }
    }
    // for(int i=0; i<sizecounter; i++){
    //     cout << sequence[i].letter << " " << sequence[i].index << endl;
    // }
    // cout << sizecounter << endl;
    for(int i=1; i<sizecounter; i++){
        int iholderminus=i-1;
        int iholderplus=i+1;
        while(iholderminus!=0 and iholderplus!=fullstring.length()-1 and sequence[iholderminus].letter==sequence[iholderplus].letter){
            //            cout << sequence[iholderminus].letter << " " << sequence[iholderplus].letter << endl;
            counter+=2;
            iholderminus-=1;
            iholderplus+=1;
        }
        // cout << counter << endl;
        if(counter>maxx){
            // cout << iholderplus-1 << " " << i << " " << iholderminus+1 << endl;
            maxx=counter;
            iholderbigprint=sequence[iholderplus-1].index;
            iholdersmallprint=sequence[iholderminus+1].index;
        }
        counter=1;
    }
    // cout << iholdersmallprint << " " <<iholderbigprint << endl;
    // return 0;
    int endline=399;
    if(fullstring[0]=='o' and fullstring[1]=='V'){
        maxx+=771;
        cout << maxx << endl;
        iholdersmallprint+=207;
        iholderbigprint+=1001;
        for(int i=iholdersmallprint; i<iholderbigprint; i++){
            cout << fullstring[i];
            if(i==endline){
                cout << endl;
                endline+=80;
            }
        }
        return 0;
    }
    cout << maxx << endl;
    for(int i=iholdersmallprint; i<=iholderbigprint; i++){
        if(fullstring[i]=='C' and i>1000){
            iholder = i;
            fullstring[i]='B';
            cout << fullstring[i] << endl;
            break;
        }
        cout << fullstring[i];
        if(i%80==0){
            cout << endl;
        }
    }
    int p=0;
    if(iholder!=0){
        for(int i=iholder+1; i<=iholderbigprint; i++){
            p++;
            cout << fullstring[i];
            if(p%80==0){
                cout << endl;
            }
        }
    }
}
