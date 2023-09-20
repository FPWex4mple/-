#include <iostream>
using namespace std;
 
int main(){
    int num = 1, n;
    int right = 3;
    int dx = 1, floater = 1;
    cin>>n;
    while(num<=n){
            for (int i=0; i<floater && num<=n; ++i)
                cout << num++ << ' ';
            cout << endl;
            floater += dx;
            if (floater < 1){
                dx = 1;
                floater = 2;
                ++right;
            }else if (floater>=right){
                dx = -1;
                floater-=2;
            }
    }
}
