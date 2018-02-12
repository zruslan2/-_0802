#include <stdio.h>
#include<stdlib.h>
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
double numb(type_number tn, double start, int end)
{
	switch (tn)
	{
	case positive:
		return (start + rand() % end)/(start + rand() % end);
		break;
	case negative:
		return (start*(-1) + rand() % end)/ (start*(-1) + rand() % end);
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
#define colCount 5
void creatMatrix(int(*a)[colCount], int r, int start, int end, type_number tn)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			a[i][j] = numb(tn, start, end);
		}
	}
}

void creatMatrix(double(*a)[colCount], int r, double start, int end, type_number tn)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			a[i][j] = round(numb(tn, start, end)*100)/100;
			/*round(a[i][j] = numb(tn, start, end));*/
		}
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

void printMatrix(double(*a)[colCount], int r)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
void printMatrix(int (*a)[colCount], int r)
{
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
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
//2.	������� ��������� Smooth(A,N), ���������� ������ ������� ������������� 
//������� A ������� N �� ��� ������� �������������� �� ������ ��������
//("����������� �������"). ������ A � ������� � �������� ��������,
//N � ������� ��������. � ������� ���� ��������� ��������� ����������� 
//����������� ������� ������� A ������� N, ������ �� ����� ���������� ������� �����������.

void Smooth(int *a, int r, const int *k)
{
	for (int l = 0; l < *k; l++)
	{
		a++; //����������� ���-�� ���
		for (j = 1; j < r - 1; j++)
		{
			/*a[j] = (a[j - 1] + a[j] + a[j + 1]) / 3;*/

			*a = (*(a - 1) + *a + *(a + 1)) / 3;
			a++;
		}
		a = a - 9;
		print_arr(a, r);
	}
}


int sum_ind(int(*a)[4], int r, int &col, int &row, int &max) //������� ���������� ����� 1 ��������
{
	int s;
	max = *(*a);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				col = j;
				row = i;
				s = i + j;
			}
		}
	}
	return s;
}

double sr_arif(double(*a)[colCount], int r)
{
	float s = 0,sr;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			s += a[i][j];
			//s += *(*a);
			//a++;
		}
	}
	return round((s / (colCount * r))*100)/100;
}
