#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
	float x,a,b,res;
	cout<<"x=", cin>>x;
	cout<<"a=", cin>>a;
	cout<<"b=", cin>>b;
	if(x<=a)
	{
		res = expl(x)-sin(x);
		cout<<"z=expl(x)-sin(x)="<<res;
	}
	else if(x>=b)
	{
		res = pow(x, 7)+fabs(x);      
		cout<<"z=pow(x, 7)+fabs(x)"<<res;
	}
	else
	{
		res = tan(x)*pow(x, 2);
		cout<<"z=tan(x)*pow(x, 2)"<<res;
	}
	return 0;
} 