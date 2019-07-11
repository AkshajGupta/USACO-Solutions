#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, size, arr[1001], digits[1001], counter=0;
string answer[1001];
void gen(int index){
    if(index==0){
        string news = "";
        for(int i=size-1; i>=0; i--){
            news+=to_string(arr[i]);
        }
        for(int i=size-1; i>=0; i--){
            for(int j=size-1; j>=0; j--){
                if(news[i]==news[j] and i!=j){
                    news="";
                    return;
                }
            }
        }
        answer[counter]=news;
        counter++;
        return;
    }
    else{
        for(int i=n-1; i>=0; i--){
            arr[index-1]=digits[i];
            gen(index-1);
        }
    }
    return;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> digits[i];
    }
    cin >> size;
    gen(size);
    for(int i=counter-1; i>=0; i--){
        if(answer[i]!=""){
        cout << answer[i] << endl;
        }
    }
}
