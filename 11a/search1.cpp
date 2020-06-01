#include<iostream>
using namespace std;

void getdata(int a[], int n)
{
	cout << "Enter the roll numbers of the students : ";
	for (int i = 0; i < n; ++i)
	{
		cout << "\n" << i+1 << ") ";
		cin >> a[i];
	}
}

int l_search(int a[], int n, int x)
{
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			return i;
	return -1;
}

int s_search(int a[], int n, int x)
{
	int last = a[n-1];
	a[n-1] = x;
	int i = 0;

	while(a[i] != x)
	{
		i++;
	}

	a[n-1] = last;

	if ((i < n-1) || (x == a[n-1]))
	{
		return i;
	}
	else
		return -1;
}

int main()
{
	int a[50];
	int n, x, ch, result;

	cout << "\nEnter the number of students who attended the training program : " << endl;
	cin >> n;

	getdata(a, n);

	do
	{

		cout << "\nEnter the type of search you want to use :\n1)Linear search\n2)Sentinel search\n3)Exit" << endl;
		cin >> ch;

		switch(ch)
		{
			case 1:
			cout << "\nEnter the roll number you want to search : " << endl;
			cin >> x;
			result = l_search(a, n, x);
			if (result != -1)
			{
				cout << "The roll number " << x << " attended the training program" << endl;
			}
			else
			{
				cout << "The roll number " << x << " did not attend the training program" << endl;
			}
			break;

			case 2:
			cout << "\nEnter the roll number you want to search : " << endl;
			cin >> x;
			result = s_search(a, n, x);
			if (result != -1)
			{
				cout << "The roll number " << x << " attended the training program" << endl;
			}
			else
			{
				cout << "The roll number " << x << " did not attend the training program" << endl;
			}
				break;
		}
	}while(ch != 3);

	return 0;
}
