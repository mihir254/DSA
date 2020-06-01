#include<iostream>
using namespace std;

void getdata(float a[][2], int n)
{
	cout << "Enter the roll numbers of the students and their marks respectively : " << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i][0];
		cin >> a[i][1];
	}
}

void display(float a[][2], int n)
{
	cout << "Roll Number   Marks" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "    " << a[i][0] << "          " << a[i][1] << endl;
	}
}

void bubble(float a[][2], int n)
{
	float temp;
	bool swap;

	for(int i = 0; i < n-1; i++)
	{
		swap = false;
		for(int j = 0; j < n-i-1; j++)
		if(a[j][1] > a[j+1][1])
		{
			for(int k = 0; k < 2; k++)
			{
				temp = a[j][k];
				a[j][k] = a[j+1][k];
				a[j+1][k] = temp;
				swap = true;
			}
		}
		if(swap == false)
		{
			break;
		}
	}
}

void selection(float a[][2], int n)
{
	 float temp;

	 for(int i = 0; i < n-1; i++)
	 {
		 for(int j = i+1; j < n; j++)
		 {
			 if(a[j][1] < a[i][1])
			 {
				 for(int k = 0; k <2; k++)
				 {
					 temp = a[j][k];
					 a[j][k] = a[i][k];
					 a[i][k] = temp;
				 }
			 }
		 }
	 }
}

int main()
{
	float a[50][2];
	int n;
	int ch;

	do
	{

		cout << "Enter the number of students : " << endl;
		cin >> n;

		cout << "Enter the choice of sorting technique : \n1)Bubble sort\n2)Selection sort\n3)Exit" << endl;
		cin >> ch;

		getdata(a, n);
		display(a, n);

		cout << "The sorted array according to floating point numbers is : " << endl;

		switch(ch)
		{
		case 1:
			bubble(a, n);
			display(a, n);
			break;
		case 2:
			selection(a, n);
			display(a, n);
			break;
		}
	}while(ch != 3);

	return 0;
}
