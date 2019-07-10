#include <iostream>
using namespace std;
int main(){
    int n, m, counting=0, minutes=0;
    cin >> n >> m;
    int arr[m][3];
    for(int i=0; i<m; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for(int i=0; i<m; i++){
        int ppm = arr[i][0];
        int maximumread = arr[i][1];
        int Break = arr[i][2];
        while(true){
            counting=counting+ppm;
            maximumread--;
            minutes++;
            if(counting>=n){
                cout << minutes << endl;
                break;
            }
            if(maximumread==0){
                minutes=minutes+Break;
                maximumread=arr[i][1];
            }
        }
        counting=0;
        minutes=0;
    }
}
