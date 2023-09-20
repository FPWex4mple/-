#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
int main()
 {
    int xn, xk, dx, x, z, a, b;
    cout<<"Input a: ", cin>>a;
    cout<<"Input b: ", cin>>b;
    cout<<"Input xn: ", cin>>xn;
    cout<<"Input xk: ", cin>>xk;
    cout<<"Input dx: ", cin>>dx;
    cout<<"Function Table z=f(x)"<<endl
    <<" _________________________"<<endl
    <<" | x        | z = f(x)   |"<<endl
    <<" _________________________"<<endl;
    cout.precision(3), cout.setf(ios::showpoint);
    cout.setf(ios::left,ios::adjustfield);
    cout.setf(ios::fixed,ios::floatfield);
    for(x=xn;x<=xk;x+=dx) 
    {
        cout<<" | "<<setw(9)<<x<<'|';
        z = (x<=a) ? (exp(x) - sin(x)) : (x>a && x<b) ? tan(x) * pow(x, 2) : pow(x, 7) + fabs(x);
        cout<<" "<<setw(10);
        cout<<z;
        cout<<'|'<<endl;
    }
    cout<<" _________________________"<<endl;
return 0;
}