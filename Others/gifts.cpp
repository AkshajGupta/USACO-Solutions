#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct gift{
    int cost;
    int shipping;
};

bool giftcomp(gift a, gift b){
    return a.cost+a.shipping<b.cost+b.shipping;
}

int main(){
    int cow, budget, purchases=0, amountingcost=0, discount=0, maxx=-1;
    cin >> cow >> budget;
    gift gifts[cow];
    for(int i=0; i<cow; i++){
        cin >> gifts[i].cost >> gifts[i].shipping;
    }
    sort(gifts,gifts+cow, giftcomp);
    // for(int i=0; i<cow; i++){
    //     cout << gifts[i].cost << " " << gifts[i].shipping << endl;
    // }
    for(int i=0; i<cow; i++){
        for(int j=0; j<cow; j++){
            if(amountingcost>budget){
                break;
            }
            amountingcost=amountingcost+gifts[j].shipping+gifts[j].cost;
            if(j==discount){
                amountingcost=amountingcost-gifts[j].cost/2;
            }
            purchases++;
        }
        if(purchases>maxx){
            maxx=purchases;
        }
        purchases=0;
        discount++;
        amountingcost=0;
    }
    cout << maxx-1 << endl;
}
