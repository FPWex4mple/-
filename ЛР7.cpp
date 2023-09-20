#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;
const int len_fio=15;//размер поля
struct student//создание структуры
{
	char first_name[len_fio];//фамилия
	char name[len_fio];//имя
	int year;//год рождения
	int stud_year;//год начала обучения
	float marks;//средний балл аттестата
	int group_ind;//номер группы
	int numb_zach;//номер зачетной книжки
};
//введение функций
const int size_p=sizeof(student);//размер структуры
//____________________прототипы функции____________
student* create_mas(int size);//выделение памяти
void fill_data(student *x, int size);//заполнение массива
void sort(student *x,int size);//сортировка
void print_mas(student *x, int size);//вывод массива
int search_students(student *x, int size);//поиск и вычисления
void del_mas(student *x);//удаления массива

int main() 
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	int size;
	puts("Введите количество элементов");
	scanf("%d",&size);
	student *x = create_mas(size); // выделение памяти
	//------вывод меню и запуск соответствующих функций--
	int c;
	while (1) 
	{
		system("cls");
		puts("1- Заполнение массива");
		puts("2- Сортировка ");
		puts("3- Вывод ");
		puts("4- Поиск и вычисления");
		puts("5- Выход");
		puts("______________________________");
		puts("Введите номер пункта меню\n");
		scanf("%d",&c);
		switch (c) 
		{
			case 1:
			fill_data(x,size); // заполнение массива
			break;
			case 2:
			sort(x,size); // сортировка
			break;
			case 3:
			print_mas(x,size); // вывод массива
			break;
			case 4:
			search_students(x,size); // поиск и вычисление
			break;
			case 5:
			del_mas(x); // освобождение памяти
			default:
			printf("ERROR");
			break;
			return 0;
		}
	}
}
//____________________выделение________________________
student* create_mas(int size)
{
	student *x=(student *)malloc(size*sizeof(student));
	if (x!=NULL)puts("Память выделена");
	else 
	{
		puts("Ошибка выделения памяти");
		exit(1);
	}
	puts("Нажмите любую клавишу");
	getch();
	return x;
}
//______________заполнение___________________
void fill_data(student *x, int size)
{
	student elem;
	puts("Ввод данных о студентах");
	for(int i=0; i<size; i++)
	{
		puts("Введите фамилию");
		scanf("%s",&x[i].first_name);//ввод фамилии
		puts("Введите имя");
		scanf("%s",&x[i].name);//ввод имени
		puts("Введите год рождения");
		scanf("%i", &x[i].year);//ввод года рождения
		puts("Введите год начала обучения");
		scanf("%i",&x[i].stud_year);//ввод года начала обучения
		puts("Введите группу");
		scanf("%i",&x[i].group_ind);// ввод номера группы
		puts("Введите номер зачетной книжки");
		scanf("%i",&x[i].numb_zach);// ввод номера зачетной книжки
		puts("Введите средний балл аттестата");
		scanf("%f",&x[i].marks);// ввод среднего балла аттестата
	}
}
//________________________________вывод массива_________________________________
void print_mas(student *x, int size)
{
	puts("Фамилия  Имя  Год  Начало обучения  Группа  Номер зачетки  Ср.балл\n");
	for(int i=0; i<size; i++)
	{
	printf("%-15s%-15s%-6i%-6i%-15i%-6i%-8.2f\n", x[i].first_name,
	x[i].name, x[i].year, x[i].stud_year,x[i].group_ind,
	x[i].numb_zach, x[i].marks);
	}
	puts("___________________________________________________________");
	getch();
	return;
}
//_____________сортировка по фамилии методом "пузырька"_____________
void sort(student *x, int size)
{
	long i,j;
	student temp;
	for(i=size-1; i>=1; i--)
	for(j=0; j<=i-1; j++)
	{
		if(strcmp(x[i].first_name,x[j].first_name)<0)
		{
			temp=x[i];
			x[i]=x[j];
			x[j]=temp;
		}
	}
	puts("Массив отсортирован");
	getch();
	return;
}
//____________поиск индекс старшего студента_____________
int search_students(student *x, int size)
{
	char s[len_fio];//строка для ввода фамилии
	float year_year = 100000;//поиск старшего студента
	int n_year = 1;//счетчик индека
	student elem;
	cin.ignore();
	//поиск индекса старшего студента
	for(int i=0; i<size; i++)
		if(x[i].year<year_year)
		{
			year_year=x[i].year;
			n_year=i;
		}
	while (1)
	{	
		puts("Введите фамилию или * (exit)");
		gets(s);//заполняем фамилию в строке s
		if (!strcmp(s,"*")) // выход если ввели *
		break;
		for(int i=0; i<size; i++)
			if(strstr(x[i].first_name, s))//ищем строку s
			{
				puts("_____________________________");
				puts("Фамилия  Имя  Год  Начало обучения  Группа  Номер зачетки  Ср.балл");
				printf("%-15s%-15s%-6i%-6i%-15i%-6i%-8.2f\n", x[i].first_name,
				x[i].name, x[i].year, x[i].stud_year,x[i].group_ind,
				x[i].numb_zach, x[i].marks);
				puts("_____________________________");
			}
	}
	printf("Старший студент ");
	printf("%i\n",n_year);
	puts("Нажмите любую клавишу");
	getch();
	return 0;
}
//_________освобождение памяти_____________
void del_mas(student *x)
{
	free(x);
	puts("Память освобождена");
	getch();
}