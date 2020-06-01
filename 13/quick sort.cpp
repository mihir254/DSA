//============================================================================
// Name        :0 quick.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quick_sort(int a[], int low, int high)
{
	int i = low + 1;
	int j = high;

	while(i < j)
	{
		while(a[low] > a[i])
		{
			i++;
		}
		while(a[low] < a[j])
		{
			j++;
		}
		if(i < j)
		{
			swap(a[i], a[j]);
		}
	}

	swap(a[j], a[low]);

	if(low < high)
	{
		quick_sort(a, low, j-1);
		quick_sort(a, j+1, high);
	}
}

int main() {

	int arr[10];
	int n;

	cout << "Enter the number of elements you want to sort : " << endl;
	cin >> n;

	cout << "Enter the elements :" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int low = 0;
	int high = n-1;

	quick_sort(arr, low, high);

	for(int i = 0; i < n; i++) {
		cout << arr[i]<<"\t";
	}
	

	return 0;
}
