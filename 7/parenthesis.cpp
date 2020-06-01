#include<iostream>
using namespace std;

class node
{
public:
	char data;
	node *next;
	node *prev;
	string parenthesis;

	node()
	{
		data = 'A';
		parenthesis = "NO INFORMATION";
		next = NULL;
		prev = NULL;
	}
};

class stack : public node
{
	node *top;
	int flag;
public:
	stack()
	{
		top = NULL;
		flag = 0;
	}

	void push(char m)
	{
		node *temp;
		int counter = 0;

		if (top == NULL)
		{
			top = new node;
			top->data = m;
			temp = top;
		}
		else
		{
			temp = top;
			temp->next = new node;
			temp->next->prev = temp;
			temp->next->data = m;
			temp = temp->next;
			top = temp;
		}
	}

	void pop()
	{
		node *temp;
		temp = top;

		if (top == NULL)
		{
			cout << "There is an extra 'End Bracket' parenthesis !" << endl;
		}
		else
		{
			top = temp->prev;
			delete temp;
		}
	}

	void getdata()
	{
		cout << "Enter the string of parenthesis you want to check : " << endl;
		cin >> parenthesis;
	}

	void display()
	{
		node *temp;
		temp = top;

		cout << "The stack looks like : " << endl;

		while(temp != NULL)
		{
			cout << temp->data << "\n";
			temp = temp->prev;
		}
	}

	void evaluate()
	{
		int c = 0;
		do
		{
			if (parenthesis[c] == '{' || parenthesis[c] == '[' || parenthesis[c] == '(')
			{
				push(parenthesis[c]);
				c++;
			}
			else if (parenthesis[c] == '}' || parenthesis[c] == ']' || parenthesis[c] == ')')
			{
				if (top != NULL)
				{
					if (parenthesis[c] == '}' && top->data == '{')
					{
						pop();
					}
					else if (parenthesis[c] == ']' && top->data == '[')
					{
						pop();
					}
					else if (parenthesis[c] == ')' && top->data == '(')
					{
						pop();
					}
					else
					{
						cout << "Improper parenthesis !" << endl;
						flag = 1;
					}
				}
				else
				{
					pop();
					flag = 1;
				}
				c++;
			}
		}while(parenthesis[c] != '\0');
	}

	void check()
	{
		node *temp;
		temp = top;
		if (flag == 0)
		{
			if(top == NULL)
			{
				cout << "The parenthesis are complete !" << endl;
			}
			else
			{
				cout << "The parenthesis are incomplete !" << endl;
			}
		}
	}
};

int main()
{
	stack s;
	s.getdata();
	s.evaluate();
	s.check();
	return 0;
}