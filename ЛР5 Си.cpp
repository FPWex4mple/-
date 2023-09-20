#include <stdio.h> 
#include <stdlib.h>
// ------------------ прототипы функций
int summa(int *a, int n);// функция, суммирующая элементы массива
void out_mas(int *a, int n);// функция, выполняющая вывод
int* in_mas(int *a, int n);// функция, выполняющая ввод
// ----------------- основная функция
int main()
{
	int n, i;
	printf("Vvedite kolichestco elementov massiva:n->"); 
	scanf("%d",&n);
	int *a=in_mas(a,n);
	out_mas(a,n);
	int res=summa(a,n);
	printf("\n summa ravna %d",res); 
	free (a);// освобождение памяти
	return 0;
}
 //----------------------- подсчет суммы
int summa(int *a, int n)
{
	int s=0;
	for(int i=0;i<n;i++)
	s+=a[i];
	return s; 
}
 //-------------------- выделение и заполнение массива
int* in_mas(int *x, int n)
{
	x=(int *) malloc(sizeof(int)*n); // выделение памяти
	printf("Vvedite elementi massiva:");
	for(int i=0;i<n;i++) // ввод 
	scanf("%d",&x[i]);
	return x;
} 
//----------------------- печать элементов массива
void out_mas(int *a, int n)
{ 
	for (int i=0; i<n; i++)
	{
		if(a[i]==0)
		printf("%d ", a[i]);
	}
	for (int j=n;j>1;j--)
	{
		for(int i=0;i<j-1;i++)
		{
			if(a[i]>a[i+1])
			{
				int temp=a[i]; 
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
 	{
		if(a[i]!=0)
		printf("%d ",a[i]);
	}
	return;
}