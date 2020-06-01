#include<iostream>
using namespace std;

void selection(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		int min = i;
		for (int j = i+1; j < n; ++j)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp; 	
	}

	cout << "\nAFTER SORTING USING SELECTION SORT : " << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
}

void bubble(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp; 
			}
		}
	}
	cout << "\nAFTER SORTING BUBBLE SORT : " << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
}

int main()
{
	int a[10];
	int n;
	cout << "Enter the number of numbers you want to sort : " << endl;
	cin >> n;
	cout << "Enter the numbers you want to sort : " << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "The numbers entered are : " << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << "\t";
	}
	selection(a, n);
	bubble(a, n);

	return 0;
}