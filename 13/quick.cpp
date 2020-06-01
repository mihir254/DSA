#include<iostream>
using namespace std;

int partition(int a[], int start, int end)
{
	int pivot = a[end];
	int flag = start;
	for(int i = start; i < end; i++)
	{
		if(a[i] <= pivot)
		{
			int temp;
			temp = a[i];
			a[i] = a[flag];
			a[flag] = temp;
			flag++;
		}
	}
	int t;
	t = a[end];
	a[end] = a[flag];
	a[flag] = t;
	
	return flag;
}

void quicksort(int a[], int start, int end)
{
	if(start < end)
	{
		int check;
		check = partition(a, start, end);
		quicksort(a, start, check-1);
		quicksort(a, check+1, end);
	}
}

int main()
{
	int a[8] = {7, 6, 5, 4, 3, 2, 1, 0};
	for(int i = 0; i < 8; i++)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
	quicksort(a, 0, 7);
	for(int i = 0; i < 8; i++)
	{
		cout << a[i] << "\t";
	}
	return 0;
}
