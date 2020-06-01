#include<iostream>
using namespace std;

int binary(int a[], int x)
{
	int check = 0;
	int low = 0, high = 9;

	while(low <= high)
	{
		int mid = (low+high)/2;
		if (x < a[mid])
		{
			high = mid-1;
		}
		else if (x > a[mid])
		{
			low = mid+1;
		}
		else if (x == a[mid])
		{
			return mid;
		}
	}
	return -1;
}

int min(int x, int y)
{
	return (x<y)?x:y;
}

int fibonacci(int a[], int x, int n)
{
	int m1 = 0, m2 = 1, m = m1+m2;
	while(m < n)
	{
		m1 = m2;
		m2 = m;
		m = m1+m2;
	}
	int offset = -1;
	while(m > 1)
	{
	int i = min(m1+offset, n-1);
		if (a[i] < x)
		{
			m = m2;
			m2 = m1;
			m1 = m-m2;
			offset = i;
		}
		else if (a[i] > x)
		{
			m = m1;
			m2 = m2-m1;
			m1 = m-m2;
		}
		else
			return i;
	}
	return -1;
}

int main()
{
	int x;
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "Enter the number you want to search : " << endl;
	cin >> x;
	int f = binary(a, x);
	if (f == -1)
	{
		cout << "NOT FOUND" << endl;
	}
	else
	{
		cout << "FOUND AT " << f+1 << endl;
	}
	int h = fibonacci(a, x, 10);
	if (h != -1)
	{
		cout << "FOUND!" << endl;
	}
	else
		cout << "NOT FOUND" << endl;
	return 0;
}