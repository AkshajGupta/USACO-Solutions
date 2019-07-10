#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int s, a, answer=0, answer2=0;
    cin >> s;
    for(int j=s; j>=s; j++){
        a = sqrt(j);
        for(int i=2; i<a; i++){
            if(j%i==0){
                answer = answer+i + j/i;
            }
        }
        answer++;
        a=sqrt(answer);
        for(int i=2; i<a; i++){
            if(answer%i==0){
                answer2 = answer2+i + answer/i;
            }
        }
        answer2++;
        if(answer2==j and answer!=1 and answer2!=1 and answer!=answer2){
            cout << answer2 << " " << answer << endl;
            break;
        }
        answer=0;
        answer2=0;
    }
}
