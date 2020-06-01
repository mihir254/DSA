#include<iostream>
using namespace std;

void f_search(int a[], int n, int x)
{
	int m1 = 1;
	int m2 = 0;
	int m = m1 + m2;

	while(m < n)
	{
		m2 = m1;
		m1 = m;
		m = m1 + m2;
	}

	int offset = 0;



}

void getdata(int a[], int n)
{
	cout << "Enter the roll number of " << n <<" students" << endl;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
}

int b_search(int a[], int n, int x)
{
	int low = 0;
	int high = n-1;
	while(low <= high)
	{
		int mid = (low + high)/2;

		if (a[mid] < x)
		{
			low = mid + 1;
		}
		else if (a[mid] > x)
		{
			high = mid -1;
		}
		else
			return mid;
		}
		return -1;
}

int main()
{
	int n;
	int a[50];

	cout << "Enter the number of students who attended the training program : " << endl;
	cin >> n;

	getdata(a, n);

	int x;

	cout << "Enter the roll number you want to search : " <<endl;
	cin >> x;


	int result = b_search(a, n, x);

	if (result == -1)
	{
		cout << "The roll number you want to search was not present at the training program !" << endl;
	}
	else
	{
		cout << "The student you searched for was present at the training program !" << endl;
	}

	return 0;
}
