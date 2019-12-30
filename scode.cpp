#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int counter=0;

bool parallel(string m){
    for(int i=0; i<m.length(); i++){
        if(m[i]!=m[m.length()-i-1]) return false;
    }
    return true;
}

string split1(string s){
    string s1="";
    for(int i=0; i<s.length()/2; i++){
        s1+=s[i];
    }
    return s1;
}

string split2(string s){
    string s2="";
    for(int i=s.length()/2; i<s.length(); i++){
        s2+=s[i];
    }
    return s2;
}

void Case1(string m){
    string a="", b="";
    for(int i=1; i<=m.length()/2; i++){
        a+=m[i];
    }
    for(int i=(m.length())/2+1; i<m.length(); i++){
        b+=m[i];
    }
    if(a==b) counter++;
//    cout << a << " " << b << endl;
    return;
}
void Case2(string m){
    string a="", b="";
    for(int i=0; i<=((m.length())/2)-1; i++){
        a+=m[i];
    }
    for(int i=(m.length())/2+1; i<m.length(); i++){
        b+=m[i];
    }
    if(a==b) counter+=2;
//    cout << a << " " << b << endl;
    return;
}

void Case3(string m){
    string a="", b="";
    for(int i=0; i<=((m.length())/2)-1; i++){
        a+=m[i];
    }
    for(int i=(m.length())/2; i<m.length()-1; i++){
        b+=m[i];
    }
    if(a==b) counter++;
//    cout << a << " " << b << endl;
    return;
}

int answer(string s){
    int ans=1;
    int length=s.length();
    int middlenum=length/2;
    
    if(length%2==0 or length==1) return 1;
    
    if(s.substr(0, middlenum)==s.substr(middlenum, middlenum))
        ans+=answer(s.substr(middlenum, middlenum+1));
    
    if(s.substr(0, middlenum)==s.substr(middlenum+1, middlenum))
        ans+=answer(s.substr(0, middlenum+1));
    
    if(s.substr(0, middlenum)==s.substr(middlenum+1, middlenum))
        ans+=answer(s.substr(middlenum, middlenum+1));
    
   if(s.substr(1,middlenum) == s.substr(middlenum+1,middlenum) )
       ans+=answer(s.substr(0,middlenum+1));
    
    return ans;
}

int main(){
    cin >> s;
//    string splitfirst=s, splitsecond=s;
//    Case1(s);
//    Case2(s);
//    Case3(s);
//    cout << counter << endl;
//    while(splitfirst.length()>=2){
//        splitfirst=split1(splitfirst);
//        if(splitfirst.length()%2==0 or splitfirst.length()==2){
//            counter++;
//            break;
//        }
//        Case1(splitfirst);
//        Case2(splitfirst);
//        Case3(splitfirst);
//    }
//    cout << counter << endl;
//    while(splitsecond.length()>=2){
//        splitsecond=split2(splitsecond);
//        if(splitsecond.length()%2==0 or splitsecond.length()==2){
//            counter++;
//            break;
//        }
//        Case1(splitsecond);
//        Case2(splitsecond);
//        Case3(splitsecond);
//    }
//    cout << counter+1 << endl;
    cout << answer(s)-1 << endl;
}
