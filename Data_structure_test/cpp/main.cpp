#include<iostream>
using namespace std;
template<class T>
void bubble0(T& a)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 8; j++)
		{
			if (a[i] < a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
template<class T>
void bubble1(T& a)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 7; j > i; j--)
		{
			if (a[j - 1] < a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}
template<class T>
void select(T& a)
{
	int min;
	for (int i = 0; i < 8; i++)
	{
		min = i;
		for (j = i + 1; j < 8; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		if (min != i)
		{
			int temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}
template<class T>
void insert(T& a)
{
	int i, j;
	int* b = new int[9];
	b[0] = 0;
	memcpy(b+1, a, sizeof(a));
	for (j = 2; j <= sizeof(b); j++)
	{
		if (b[j] < b[j - 1])
		{
			b[0] = b[j];
			for (i = j; b[i-1]>b[0]; i--)
			{
				b[i] = b[i-1];
			}
			b[i] = b[0];
		}
	}
	memcpy(a, b + 1, sizeof(a));
	free[](b);
}
template<class T>
void shell(T& a)
{
	int i, j;
	int* b = new int[9];
	b[0] = 0;
	memcpy(b + 1, a, sizeof(a));
	int increment = sizeof(b) / 3 + 1;
	do {
		int increment = sizeof(b) / 3 + 1;
		for (i = increment + 1; i < sizeof(b); i++)
		{
			if (b[i] < b[i - increment])
			{
				b[0] = b[i];
				for (j = i - increment; j > 0 && b[0] < b[j]; j -= increment)
				{
					b[j + increment] = b[j];
				}
				b[j + increment] = b[0];
			}
		}

	}while(increment>1)
}
int main()
{
	int a[8] = { 7,9,4,6,5,8,3,1 };
	//bubble1(a);
	cout << "size" << sizeof(a) << endl;
	insert(a);
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
