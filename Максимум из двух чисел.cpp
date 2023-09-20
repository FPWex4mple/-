#include <iostream>
#include <math.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");
    double a,b;
    cin>>a>>b;
    if (a>b) {
        cout<<a;
    }
    else{
        cout<<b;
    }
    return 0;
}
