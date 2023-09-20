#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;
    string result="";
    char c=s[0];
    int count = 1;
    for (int i = 1;i<s.size();++i){
        if (s[i]==c){
            count++;
        }
        else {
            result+=c;
            if (count>1) {
                result+=to_string(count);
            }
            c=s[i];
            count=1;
        }
    }
    result+=c;
            if (count>1) {
                result+=to_string(count);
            }
    cout<<result<<endl;
    return 0;
}
