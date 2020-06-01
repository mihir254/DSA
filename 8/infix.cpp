#include<iostream>
using namespace std;

class expression
{
	char a[10];
	int t;
	string exp;
public:
	expression()
	{
		exp = "NOINFO";
		t = 0;
	}

	bool isempty()
	{
		return (t == -1);
	}

	bool isfull()
	{
		return (t == 9);
	}

	void push(char x)
	{
		a[++t] = x;
	}

	void pop()
	{
		cout << a[t];
		t--;
	}

	void getdata()
	{
		cout << "Enter the exp which you want to convert into postfix : " << endl;
		cin >> exp;
	}

	void check()
	{
		int c = 0;
		do
		{
			if (exp[c] == '*' || exp[c] == '-' || exp[c] == '+' || exp[c] == '/' || exp[c] == '(')
			{
				if (exp[c] == '+' || exp[c] == '-')
				{
					if (a[t] == '*' || a[t] == '/' || a[t] == '-' || a[t] == '+')
					{
						pop();
					}
					else
					{
						push(exp[c]);
						c++;
					}
				}
				else if (exp[c] == '*' || exp[c] == '/')
				{
					if (a[t] == '/' || a[t] == '*')
					{
						pop();
					}
					else
					{
						push(exp[c]);
						c++;
					}
				}
				else
				{
					push(exp[c]);
					c++;
				}
			}
			else if (exp[c] == ')')
			{
				while(a[t] != '(')
				{
					pop();
				}
				t--;
				c++;
			}
			else
			{
				cout << exp[c];
				c++;
			}

		} while (exp[c] != '\0');

		do
		{
			pop();
		} while (t != -1);
	}
};

int main()
{
	expression e;
	e.getdata();
	cout << "\n";
	cout << "\nThe new expression is : " << endl;
	e.check();
	return 0;
}