#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int arr[12], total=0, counter=0, team1[3], team2[3], team3[3], team4[3], team1counter=0, team2counter=0, team3counter=0, team4counter=0, minn=1000000, totalteamcounter=0;
void gen(int index){
    if(totalteamcounter==12){
        //         cout << "happened" << endl;
        int teamtotal[4];
        for(int i=0; i<4; i++){
            teamtotal[i]=0;
        }
        for(int i=0; i<3; i++){
            teamtotal[0]+=team1[i];
            teamtotal[1]+=team2[i];
            teamtotal[2]+=team3[i];
            teamtotal[3]+=team4[i];
        }
        for(int i=0; i<4; i++){
//            cout << teamtotal[i] << endl;
        }
        sort(teamtotal, teamtotal+4);
        if(teamtotal[3]-teamtotal[0]<minn){
            minn=teamtotal[3]-teamtotal[0];
        }
        return;
    }
    else{
        if(team1counter<3){
            team1[team1counter]=arr[index];
            team1counter++;
            totalteamcounter++;
            gen(index+1);
            team1counter--;
            totalteamcounter--;
        }
        if(team2counter<3){
            team2[team2counter]=arr[index];
            team2counter++;
            totalteamcounter++;
            gen(index+1);
            team2counter--;
            totalteamcounter--;
        }
        if(team3counter<3){
            team3[team3counter]=arr[index];
            team3counter++;
            totalteamcounter++;
            gen(index+1);
            team3counter--;
            totalteamcounter--;
        }
        if(team4counter<3){
            team4[team4counter]=arr[index];
            team4counter++;
            totalteamcounter++;
            gen(index+1);
            team4counter--;
            totalteamcounter--;
        }
        //            cout << totalteamcounter << endl;
        
    }
    return;
}
int main(){
    for(int i=0; i<12; i++){
        cin >> arr[i];
    }
    gen(0);
    cout << minn << endl;
}
