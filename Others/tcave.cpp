#include <iostream>
#include <vector>
using namespace std;
struct branches{
    int start;
    int b1;
    int b2;
};
branches rows[5000];
int main(){
    int passages, inputrows, treasure, cur, counter=1;
    vector <int> answer;
    cin >> passages >> inputrows >> treasure;
    for(int i=0; i<inputrows; i++){
        cin >> rows[i].start >> rows[i].b1 >> rows[i].b2;
    }
    cur=treasure;
    answer.push_back(treasure);
    while(cur!=1){
        for(int i=0; i<inputrows; i++){
            if(rows[i].b1==cur or rows[i].b2==cur){
                cur=rows[i].start;
                counter++;
                answer.push_back(cur);
            }
        }
        //        cout << cur << endl;
    }
    cout << counter << endl;
    for(int i=counter-1; i>=0; i--){
        cout << answer[i] << endl;
    }
    return 0;
}
