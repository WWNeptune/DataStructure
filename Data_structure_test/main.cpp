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
int main()
{
	int a[8] = { 7,9,4,6,5,8,3,1 };
	bubble1(a);
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
