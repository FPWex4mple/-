#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double a,b;
    cin>>a>>b;
    if (b == 0){
        return 0;
    }
    double res = a/b;
    cout << res;
    return 0;
}
