#include <iostream>
#include <algorithm>
using namespace std;

struct cowinput{
    int num;
    int pos;
};

bool cowsnewcomp(cowinput a, cowinput b){
    return a.num<b.num;
}

int main(){
    int n, maxx=-1;
    cin >> n;
    cowinput cowsog[n], cowsnew[n];
    for(int i=0; i<n; i++){
        cin >> cowsog[i].num;
        cowsnew[i].num=cowsog[i].num;
        cowsog[i].pos=i;
        cowsnew[i].pos=i;
    }
    
    sort(cowsnew, cowsnew+n, cowsnewcomp);
    
    for(int i=0; i<n; i++){
        if(cowsnew[i].pos-cowsog[i].pos>maxx){
            maxx=cowsnew[i].pos-cowsog[i].pos+1;
        }
    }
    if(maxx>5000){
        cout << maxx << endl;
        return 0;
    }
    cout << maxx << endl;
    return 0;
}
