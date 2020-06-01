#include<iostream>
using namespace std;

void linear(int a[], int x)
{
	int flag = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (a[i] == x)
		{
			flag = 1;
			cout << "FOUND AT : " << i+1 << endl;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "NOT FOUND!" << endl;
	}
}

void sentinel(int a[], int x)
{
	int flag = 0;
	int check = a[9];
	a[9] = x;
	int i = 0;
	while(a[i] != x)
	{
		i++;
	}

	a[9] = check;

	if (i < 9 || x == a[9])
	{
		cout << "FOUND AT : " << i+1 << endl;
	}
	else
	{
		cout << "NOT FOUND!" << endl;
	}
}

int main()
{
	int x;
	int a[10] = {9, 8, 6, 7, 4, 5, 3, 1, 2, 0};
	cout << "Enter the number you want to search : " << endl;
	cin >> x;
	linear(a, x);
	sentinel(a, x);
	return 0;
}