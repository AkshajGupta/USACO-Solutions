#include <iostream>
#include <vector>
using namespace std;
int passages, cur, counter=1, curcounter=0, maxx=-1, prevcur=0;
struct branches{
    int start;
    int b1;
    int b2;
};
branches rows[5000];
void find(int cur){
    while(prevcur!=cur){
        prevcur=cur;
        for(int i=0; i<passages; i++){
            if(rows[i].b1==cur or rows[i].b2==cur){
                cur=rows[i].start;
                counter++;
            }
        }
        curcounter++;
        //        cout << cur << endl;
    }
    if(counter>maxx){
        maxx=counter;
    }
    counter=0;
    return;
}
int main(){
    cin >> passages;
    for(int i=0; i<passages-1; i++){
        cin >> rows[i].start >> rows[i].b1 >> rows[i].b2;
    }
    for(int i=0; i<passages-1; i++){
        find(rows[i].start);
    }
    cout << maxx+1 << endl;
    return 0;
}
