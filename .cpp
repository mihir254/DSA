#include<iostream>
using namespace std;

class mat
{
	int a[10][10];
public:
	void getdata(int r, int c)
	{
		cout << "Enter the elements into the matrix, row wise : " << endl;

		for (int i = 0; i < r; ++i)
		 {
		 	for (int j = 0; j < c; ++j)
		 	{
		 		cin >> a[i][j];
		 	}
		 } 
	}

	void display(int r, int c)
	{
		cout << "The matrix looks like : " << endl;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cout << a[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	bool upper(int r, int c)
	{
		int check = 0;
		cout << "\nChecking if the matrix is an upper triangular one or not : " << endl;
		for (int i = 1; i < r; ++i)
			for (int j = 0; j < i; ++j)
				if (a[i][j] != 0)
					return false;
				return true;
	}

	void add(mat n, int r, int c)
	{
		int t[10][10];
		cout << "The addition matrix looks like : " << endl;

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				t[i][j] = a[i][j] + n.a[i][j];
			}
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cout << t[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	void sub(mat n, int r, int c)
	{
		int t[10][10];

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				t[i][j] = a[i][j] - n.a[i][j];
			}
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cout << t[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	void trans(int r, int c)
	{
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cout << a[j][i] << "\n";
			}
			cout << "\n";
		}
	}

	void diagonal(int r, int c)
	{
		int sum = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (i == j)
				{
					sum = sum + a[i][j];
				}
			}
		}
		cout << "The sum of the diagonal elements is : " << sum << endl;
	}

	void saddle(int r, int c)
	{
		cout << "Cheching the saddle point : " << endl;
		int i,j,y,z,k,least,max;

		for(i=0;i<r;i++)
		{
			least=a[i][0];
			for(j=0;j<c;j++)
			{
				if(least>a[i][j])
				{
					least=a[i][j];
					y=j;
				}
			}

			max=a[0][y];

			for(k=0;k<r;++k)
			{
				if(max<a[k][y])
				{
					max=a[k][y];
					z=k;
				}
			}
		}
		if(max==a[z][y] && least==a[z][y])
		{
			cout<<"The Saddle Point is: "<<a[z][y];
		}
	}
};

int main()
{
	int r, c;
	
	cout << "Enter the number of rows and columns : " << endl;
	cin >> r >> c;
	
	mat m, n;
	m.getdata(r, c);
	m.display(r, c);

	if (m.upper(r, c))
	{
		cout << "\nThe matrix is upper triangular!" << endl;
	}
	else
	{
		cout << "\nNot Upper triangular" <<  endl;
	}

	cout << "To perform additon, we need another matrix : \n" << endl;
	int r2, c2;

	cout << "Enter the number of rows and columns : " << endl;
	cin >> r2 >> c2;

	n.getdata(r2, c2);
	n.display(r2, c2);

	cout << "The addition matrix looks like : " << endl;
	m.add(n, r, c);
	cout << "The subtraction matrix looks like : " << endl;
	m.sub(n, r, c);
	
	cout << "The transpose matrix looks like : " << endl;
	m.trans(r, c);

	m.diagonal(r, c);

	m.saddle(r, c);

	return 0;
}