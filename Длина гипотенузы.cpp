#include <iostream>
#include <math.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");
    double a,b,c;
    cin>>a>>b;
    if (a>0 && b>0) {
        c = sqrt(pow(a,2)+pow(b,2));
        cout<<c;
    }

    return 0;
}
