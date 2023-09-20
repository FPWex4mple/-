#include <iomanip>
#include <iostream>
using namespace std;
int sum_str(int **a, int m, int n, int s, int c, int sum);
int sum_count(int **a, int m, int n, int s, int c, int sum);
int sum_elem(int **a, int m, int n, int s, int c, int sum);
void vyvod(int **a, int m, int n, int s, int c, int sum);
//главная функция
int main()
{
	int i, j, m, n, sum, s, c;
	cout<<"vvedite kol-vo strok i stolbcov:"<<endl;
	cin>>n>>m;
	int **a=new int *[n]; // выделение памяти
	for(i=0;i<n;i++) // под матрицу
	a[i]=new int[m];
	cout<<"vvedite elementi: "<<endl; 
	for(i=0;i<n;i++) // ввод матрицы
	for(j=0;j<m;j++) 
	cin>>a[i][j];
	sum_str(a,n,m,s,c,sum); // суммирование элементов
	sum_count(a,n,m,s,c,sum); // суммирование количества элементов
	sum_elem(a,n,m,s,c,sum); // вычисление соседей
	vyvod(a,n,m,s,c,sum); // вывод результатов
	for(i=0;i<n;i++) // под матрицу
	delete []a[i]; // освобождение памяти
	delete []a;
	return 0;
}
//------подсчет суммы
int sum_str(int **a, int m, int n, int s, int c, int sum)
{
	int i,j;
	s=0;
	for (i=0; i<n; i++)
	{
		for (j=0;j<m;j++)
		{
			if (a[i][j]<0 && a[i][j] % 2 !=0)
			s+=a[i][j];	
		}
	}
	return s;
}
//------------подсчет количества
int sum_count(int **a, int m, int n, int s, int c, int sum)
{
	int i, j;
	c=0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			if(a[i][j]<0 && a[i][j] % 2 !=0)
			c+=1;
		}
	}
	return c;
}
//----- подсчет соседей, которые больше
int sum_elem(int **a, int m, int n, int s, int c, int sum)
{
	int i, j;
	sum=0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (i>=1 && i<=n-2 && j>=1 && j<=m-2)//центральный квадрат
			{
				if (a[i][j]>a[i-1][j] && a[i][j]>a[i+1][j] && a[i][j]>a[i][j-1] && a[i][j]>a[i][j+1])
				{
					sum += 1;
				}
			}
			if (i==0 && j==0)//левый верхний угол
			{
				if (a[i][j]>a[i+1][j] && a[i][j]>a[i][j+1])
				{
					sum += 1;
				}
			}
			if (i==0 && j==m-1)//правый верхний угол
			{              
				if (a[i][j]>a[i][j-1] && a[i][j]>a[i+1][j])
				{
					sum += 1;
				}
			}
			if (i==n-1 && j==0)//левый нижний угол
			{
				if (a[i][j]>a[i-1][j] && a[i][j]>a[i][j+1])
				{
					sum += 1;
				}
			}
			if (i==n-1 && j==m-1)//правый нижний угол
			{
				if (a[i][j]>a[i][j-1] && a[i][j]>a[i-1][j])
				{
					sum += 1;
				}
			}
			if (i==0 && j>=1 && j<=m-2)//верхняя строка
			{
				if (a[i][j]>a[i][j-1] && a[i][j]>a[i][j+1] && a[i][j]>a[i+1][j])
				{
					sum += 1;
				}
			}
			if (i==n-1 && j>=1 && j<=m-2)//нижняя строка
			{
				if (a[i][j]>a[i][j-1] && a[i][j]>a[i][j+1] && a[i][j]>a[i-1][j])
				{
					sum += 1;
				}
			}
			if (j==0 && i>=1 && i<=n-2)//левая строка
			{
				if (a[i][j]>a[i-1][j] && a[i][j]>a[i+1][j] && a[i][j]>a[i][j+1])
				{
					sum += 1;
				}
			}
			if (j==m-1 && i>=1 && i<=n-2)//правая строка
			{
				if (a[i][j]>a[i-1][j] && a[i][j]>a[i+1][j] && a[i][j]>a[i][j-1])
				{
					sum += 1;
				}
			}
		}
	}
	return sum;
}       
//---------вывод результатов
void vyvod(int **a, int m, int n, int s, int c, int sum)
{
	int i,j; 
	cout<<endl<<endl;
	cout<<"matrica"<<endl;
	for(i=0;i<n;i++)
 	{ 
		for(j=0;j<m;j++) 
 		cout<<setw(4)<<a[i][j]<<" ";//вывод матрицы
		cout<<endl;
 	}
 	cout<<endl<<endl;
	cout<<"\n results"<<endl; 
	int res=sum_str(a,m,n,s,c,sum);
	int count=sum_count(a,m,n,s,c,sum);
	int srt=sum_elem(a,m,n,s,c,sum);
	cout<<" Summa elementov :"<<res<<endl;//вывод суммы элементов
	cout<<" Kolichestvo elementov : "<<count<<endl;//количество элементов
	cout<<" max : "<<srt<<endl;//количество соседей, которые меньше
	cout<<endl;
}
