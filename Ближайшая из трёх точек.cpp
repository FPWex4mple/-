#include <iostream>
#include <math.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");
    double a,b,c,z,x;
    cin>>a>>b>>c;
    z=fabs(a-c);
    x=fabs(a-b);
    if (z>x) {
        cout<<'B'<<' '<<x;
    }
    else {
        cout<<'C'<<' '<<z;
    }
    return 0;
}
