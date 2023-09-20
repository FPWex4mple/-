#include <stdio.h>
#include <iostream>
#include <windows.h>
const int N = 10;
int main()
{
	SetConsoleOutputCP(65001);
	int x[N];
	int i = 0;
	printf("введите %d элеметов массива ", N);
	for (; i<N; i++)
	{
		scanf("%d", &x[i]);
		int imax = 1, imin = 1, m = 1;
	}
	int imax = 1, imin = 1, m = 1;
	for (i=0; i<N; i++)
	{
		if (x[i] > x[imax]) imax = i;
		if (x[i] < x[imin]) imin = i;
	}
	for (i=0; i<N; i++)
	{
		if (x[i] > 0) m *= x[i];
	}
	printf("\n индекс максимального =%d максимальный элемент =%d ",imax, x[imax]);
	printf("\n индекс минимального =%d минимальный элемент =%d ", imin, x[imin]);
	printf("\n произведение положительных элементов массива =%d ", m);
	int ibeg, iend;
	if (imin < imax) {ibeg = imin; iend = imax;}
	else {ibeg=imax; iend=imin;}
	
	int count = 0;	
	for(i=ibeg;i<iend;i++)
	if(x[i] > 0) count++;
	printf("\n количество положительных элементов=%d ",count);
	
	int min=x[0], number=0, summa=0;
	if(x[i]<min)
	{
		min = x[i];
		number = i;
	}
	for (i = 0; i<number; i++)
	summa+=x[i];
	printf("\n сумма элементов до минимального=%d ", summa);
	float temp; 
	int j;
	for (i = 2; i < N; i++) 
	{
		temp = x[i];
		if (i%2 == 0 or i == 0) 
		{
			j = i - 2;
			while (j >= 0 and x[j] > temp) 
			{
				x[j+2] = x[j];
				x[j] = temp;
				j -= 2;
			}
		} 
		else 
		{
			j = i - 2;
			while (j >= 0 and x[j] > temp) 
			{
				x[j+2] = x[j];
				x[j] = temp;
				j -= 2;
			}
		}
	}
	for (i = 0; i < N; i++) 
	{
		printf("\n%d " ,x[i]);
	}
	return 0;
}