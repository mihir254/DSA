#include<iostream>
#include<math.h>
using namespace std;

class poly
{
	int a[10][2];
	int n;
public:

	void input()
	{
		cout << "Enter the highest degree of your polynomial : " << endl;
		cin >> n;

		for (int i = 0; i < n+1; ++i)
		{
			cout << "Enter the coefficient whose power is " << i << " : " << endl;
			cin >> a[i][0];
			a[i][1] = i;
		}
	}

	void output()
	{
		cout << "The polynomial is : " << endl;

		for (int i = 0; i < n+1; ++i)
		{
			cout << " + " << a[i][0] << "x^" << a[i][1];
		}
		cout << "\n";
	}

	void evaluate()
	{
		int value = 0;
		int m;

		cout << "Enter the value at which you want to evaluate the polynomial : "<< endl;
		cin >> m;

		for (int i = 0; i < n+1; ++i)
		{
			value = value + a[i][0]*(pow(m,a[i][1]));
		}

		cout << "The value of the polynomila at x = " << m << " is : " << value <<endl;
	}

	void add(poly p1, poly p2)
	{
		int x=0,y=0,z=0;

		do
		{
		if(x <= p1.n && y <= p2.n)
		{
			if (p1.a[x][1] == p2.a[y][1])
			{
				a[z][0] = p1.a[x][0] + p2.a[y][0];
				a[z][1] = p1.a[x][1];
				x++;
				y++;
				z++;
			}

			else if (p1.a[x][1] <= p2.a[y][1])
			{
				a[z][0] = p1.a[x][0];
				a[z][1] = p1.a[x][1];
				x++;
				z++;
			}

			else if (p1.a[x][1] >= p2.a[y][1])
			{
				a[z][0] = p2.a[y][0];
				a[z][1] = p2.a[y][1];
				y++;
				z++;
			}
		}

		else if (x == p1.n && y <= p2.n)
		{

			a[z][0] = p2.a[y][0];
			a[z][1] = p2.a[y][1];
			z++;
			y++;
		}

		else if (y == p2.n && x <= p1.n)
		{
			a[z][0] = p1.a[x][0];
			a[z][1] = p1.a[x][1];
			z++;
			x++;
		}
		}while(x <= p1.n || y <= p2.n);

		cout << "The addition polynomial is : " << endl;

		for (int i = 0; i < z; ++i)
		{
			cout << " + " << a[i][0] << "x^" << a[i][1];
		}
		cout << "\n";
	}
};

int main()
{
	poly p1,p2,p3;
	int ch;

	do
	{
		cout << "\n||||||||||||||||||" << endl;
		cout << "Enter the choice : \n1)Enter the polynomial\n2)Display the polynomial\n3)Evaluate the polynomial\n4)Add two polynomials\n5)EXIT" << endl;
		cin >> ch;

		switch(ch)
		{
			case 1:
			p1.input();
			break;
			case 2:
			p1.output();
			break;
			case 3:
			p1.evaluate();
			break;
			case 4:
			p2.input();
			p3.add(p1,p2);
			break;
		}
	} while (ch != 5);
	return 0;
}
