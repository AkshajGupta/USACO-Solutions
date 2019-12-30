#include <iostream>
using namespace std;
int main(){
    int desta, destb, planes, ans=100000;
    cin >> desta >> destb >> planes;
    for(int i=0; i<planes; i++){
        int cost, stops, route;
        cin >> cost >> stops;
        bool founda=false;
        for(int j=0; j<stops; j++){
            cin >> route;
            if(route==desta){
                founda=true;
            }
            if(founda and route==destb){
                if(cost<ans){
                    ans=cost;
                }
            }
        }
        founda=false;
    }
    if(ans==100000) ans=-1;
    cout << ans << endl;
    return 0;
}
