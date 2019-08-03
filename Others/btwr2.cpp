    #include <iostream>
#include <algoirthm>
#include <cmath>
using namespace std;
int main(){
int n, total, maxx=-1;
cin >> n;
pair <int, int> haybales[n];
for(int i=0; i<n; i++){
    cin >> haybales[i].first >> haybales[i].second;
}
sort(haybales, haybales+n);
//    for(int i=0; i<n; i++){
//        cout << haybales[i].first << " " << haybales[i].second << endl;
//    }

int counter=1;
for(int i=0; i<n; i++){
    counter*=2;
}
for(int i=1; i<counter; i++){
    vector <int> otherside;
    total=0;
    for(int j=0; j<n; j++){
        if((i & (1<<j))>0){
            otherside.push_back(haybales[j].second);
        }
    }
    for(int j=0; j<otherside.size()-1; j++){
        if(otherside[j]>otherside[j+1]){
            break;
        }
        else{
            total++;
        }
    }
    if(total>maxx){
        maxx=total;
    }
    //        cout << total << endl;
}
cout << maxx+1 << endl;
}
