#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <stdarg.h>

using namespace std;

unsigned i, j;

enum type_number { positive, negative, all };

int happy(char* arr)
{
	int f, s;
	f = (int)arr[0] + (int)arr[1];
	s = (int)arr[2] + (int)arr[3];
	if (f == s)
		return 1;
	else return 0;
}

void sort_u(int*arr, int j)
{
	int prom;
	if (arr[j] > arr[j + 1])
	{
		prom = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = prom;
	}
}

void sort_d(int*arr, int j)
{
	int prom;
	if (arr[j] < arr[j + 1])
	{
		prom = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = prom;
	}
}

void sort(int*arr, int r, int n)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < r - 1; j++)
		{
			if (n == 1)
				sort_u(arr, j);
			else
				sort_d(arr, j);
		}
	}
}

int numb(type_number tn, int start, int end)
{
	switch (tn)
	{
	case positive:
		return start + rand() % end;
		break;
	case negative:
		return start*(-1) + rand() % end;
		break;
	case all:
		return rand();
		break;
	}
}

void creat(int*arr, int r, int start, int end, type_number tn)
{
	for (i = 0; i < r; i++)
	{
		arr[i] = numb(tn, start, end);
	}
}

void print_arr(int*arr, int r)
{
	for (i = 0; i < r; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void arr_d(int*arr, int arr1[][4], int r)
{
	int m = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			//*(*(arr1+i)+j) = *(arr+m);
			arr1[i][j] = arr[m];
			m++;
		}
	}
}

int sum(int num, ...)
{
	int arr = 0;
	va_list r;
	va_start(r, num);
	for (; num; num--)
	{
		arr += va_arg(r, int);
	}
	va_end(r);
	return arr;
}

//1.	Описать процедуру Smooth(A, N), заменяющую каждый элемент вещественного массива A размера N на его среднее арифметическое 
//со своими соседями("сглаживание массива").Массив A — входной и выходной параметр, N — входной параметр.С помощью этой процедуры 
//выполнить пятикратное сглаживание данного массива A размера N, выводя на экран результаты каждого сглаживания.
//
//Ввести с клавиатуры массив, состоящий из n строк и m столбцов.Создать библиотеку, в которой будет содержаться функция, которая 
//производит вычисления согласно заданию, приведенному в таблице.

void smooth(int*a, int r, const int* k)
{	
	for (int y = 0; y < *k; y++)
	{
		a++;
		for (j = 1; j < r - 1; j++)
		{
			/*a[j] = (a[j - 1] + a[j] + a[j + 1]) / 3;*/
			*a = (*(a - 1) + *a + *(a + 1)) / 3;
			a++;
		}
		a=a - 9;
		print_arr(a, r);
	}
}

