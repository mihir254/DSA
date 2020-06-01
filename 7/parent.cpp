#include<iostream>
using namespace std;

class par
{
	string parenthesis;
	char a[10];
	int t;

public:
	par()
	{
		parenthesis = "NOINFO";
		t = -1;
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
		t--;
	}

	void getdata()
	{
		cout << "Enter the epression here : " << endl;
		cin >> parenthesis;
	}

	void check()
	{	
		int c = 0;
		int flag = 0;
		do
		{
			if (parenthesis[c] == '{' || parenthesis[c] == '(' || parenthesis[c] == '[')
			{
				push(parenthesis[c]);
			}

			else if(parenthesis[c] == '}' || parenthesis[c] == ')' || parenthesis[c] == ']')
			{
				if (parenthesis[c] == '}' && a[t] == '{')
				{
					pop();
				}
				else if (parenthesis[c] == ')' && a[t] == '(')
				{
					pop();
				}
				else if (parenthesis[c] == ']' && a[t] == '[')
				{
					pop();
				}
				else
				{
					flag = 1;
				}
			}

			c++;
		}while(parenthesis[c] != '\0');

		if (flag == 0 && isempty())
		{
			cout << "PROPERLY PARENTHESISED"<< endl;
		}
		else if (flag  == 0 && !isempty())
		{
			cout << "Extra opening bracket!" << endl;
		}
		else
		{
			cout << "WRONGLY PARENTHESISED" << endl;
		}
	}
};

int main()
{
	par p;
	p.getdata();
	p.check();
	return 0;
}