#include <iostream>
#include <algorithm>
using namespace std;

struct input{
    long long cost;
    long long amount;
};

bool inputcomp(input a, input b){
    return a.cost<b.cost;
}

int main(){
    long long cows, money, counter=0;
    cin >> cows >> money;
    input chocolate[cows];
    for(int i=0; i<cows; i++){
        cin >> chocolate[i].cost >> chocolate[i].amount;
    }
    
    sort(chocolate, chocolate+cows, inputcomp);
    
//    for(int i=0; i<cows; i++){
//        cout << chocolate[i].cost << " " << chocolate[i].amount << endl;
//    }
    
    for(int i=0; i<cows; i++){
        long long maxamount = money/chocolate[i].cost;
        if(maxamount>chocolate[i].amount) maxamount=chocolate[i].amount;
        counter+=maxamount;
        long long subtract=maxamount*chocolate[i].cost;
        money-=subtract;
        if(money<=0 or chocolate[i].cost>money){
            cout << counter << endl;
            return 0;
        }
    }
    
    cout << counter << endl;
    return 0;
    
}
