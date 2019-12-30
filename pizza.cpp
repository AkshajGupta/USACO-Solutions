#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int toppings, constraints, temparr[20], size=1, counter=0;
vector <int> top[52];

bool check(string s){
    int total=0;
        for(int i=0; i<constraints; i++){
            for(int j=0; j<top[i].size(); j++){
                for(int k=0; k<s.length(); k++){
                    if(s[k]-'0'==top[i][j]){
                    //                    cout << "hi" << endl;
                                        total++;
                    }
                }
//                cout << top[i][j] << " " << s[k] << endl;;
            }
//            cout << s[i]
//            cout << endl;
//            cout << total << " " << top[i].size() << endl;
            if(total==top[i].size()){
                return true;
            }
            total=0;
        }
//        cout << counter << " " << s[k] << endl;
    return false;
}

void recurse(int index, int lastindex){
    bool works=true;
    if(index==size){
        string s = "";
        for(int i=0; i<size; i++){
            s+=temparr[i]+'0';
        }
        if(!check(s)){
//            cout << s << " ";
            counter++;
        }
//        cout << s << " " << check(s) << endl;
//        exit(0);
        return;
    }
    else{
        for(int i=lastindex; i<toppings; i++){
            temparr[index]=i+1;
            recurse(index+1, i+1);
        }
    }
    return;
}

int main(){
    cin >> toppings >> constraints;
    for(int i=0; i<constraints; i++){
        int num;
        cin >> num;
        for(int j=0; j<num; j++){
            int a;
            cin >> a;
            top[i].push_back(a);
        }
        sort(top[i].begin(), top[i].end());
    }
    
    for(int i=0; i<toppings; i++){
        recurse(0, 0);
        size++;
    }
    cout << counter+1 << endl;
    return 0;
}
