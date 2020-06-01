#include<iostream>
#include<math.h>
using namespace std;

class node
{
public:
	int coeff;
	int power;
	node *next;
	node *prev;

	node()
	{
		coeff = 0;
		power = 0;
		next = NULL;
		prev = NULL;
	}
};

class poly : public node
{
	node *head;
public:
	poly()
	{
		head = NULL;
	}

	void setdata()
	{
		node *temp;
		int n;

		cout << "Enter the highest degree of your polynomial : " << endl;
		cin >> n;
		
		for (int i = 0; i <= n; ++i)
		{
			if (head == NULL)
			{
				head = new node;
				head->prev = head;
				head->next = head;
				temp = head;
			}
			else
			{
				temp->next = new node;
				temp->next->prev = temp;
				temp->next->next = head;
				temp = temp->next;
			}
		}
	}

	void getdata()
	{
		node *temp;
		temp = head;
		int i = 0;
		do
		{
			cout << "Enter the coefficient of the term with power " << i << " : " << endl;
			cin >> temp->coeff;
			temp->power = i;
			i++;
			temp = temp -> next;
		} while (temp != head);
	}

	void display()
	{
		node *temp;
		temp = head;
		int i = 0;

		cout << "The polynomial is : " << endl;
		do
		{
			cout << " + " << temp->coeff << "x^" << i;
			i++;
			temp = temp->next;
		} while (temp != head);
		cout << "\n";
	}

	void evaluate()
	{
		int value = 0;
		int a;
		node *temp;
		temp = head;

		cout << "Enter the value at which you want to evaluate the polynomial : "<< endl;
		cin >> a;

		do
		{	
			value = value + temp->coeff*(pow(a,temp->power));
			temp = temp->next;
		} while (temp != head);

		cout << "The value of the polynomial at x = " << a << " is : " << value <<endl;
	}

	void add(poly p1, poly p2)
	{
		node *temp1;
		node *temp2;
		node *temp;

		temp1 = p1.head;
		temp2 = p2.head;

		do
		{
			if(temp1->power == temp2->power)
			{
				if (head == NULL)
				{
					head = new node;
					head->prev = head;
					head->next = head;
					temp = head;
				}
				else
				{
					temp->next = new node;
					temp->next->prev = temp;
					temp->next->next = head;
					temp = temp->next;
				}

				temp->coeff = temp1->coeff + temp2->coeff;
				temp->power = temp1->power;
				
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			
			else if (temp1->power < temp2->power)
			{
				if (head == NULL)
				{
					head = new node;
					head->prev = head;
					head->next = head;
					temp = head;
				}
				else
				{
					temp->next = new node;
					temp->next->prev = temp;
					temp->next->next = head;
					temp = temp->next;
				}

				temp->coeff = temp1->coeff;
				temp->power = temp1->power;

				temp1 = temp1->next;
				temp = temp->next;
			}
			
			else if (temp1->power > temp2->power)
			{
				if (head == NULL)
				{
					head = new node;
					head->prev = head;
					head->next = head;
					temp = head;
				}
				else
				{
					temp->next = new node;
					temp->next->prev = temp;
					temp->next->next = head;
					temp = temp->next;
				}

				temp->coeff = temp2->coeff;
				temp->power = temp2->power;

				temp2 = temp2->next;
				temp = temp->next;
			}

		}while(temp1 != p1.head || temp2 != p2.head);

		cout << "The addition polynomial is : " << endl;

		temp = head;
		do
		{
			cout << " + " << temp->coeff << "x^" << temp->power;
			temp = temp->next;
		}while(temp != head);

		cout << "\n";
	}
};

int main()
{
	int ch;
	poly p1,p2,p3;
	
	p1.setdata();
	p1.getdata();

	do
	{
		cout << "\nEnter the choice : \n1)Display\n2)Evaluate the polynomial at a certain value\n3)Add two polynomials\n4)Exit" << endl;
		cin >> ch;

		switch(ch)
		{
			case 1:
			p1.display();
			break;
			case 2:
			p1.evaluate();
			break;
			case 3:
			p2.setdata();
			p2.getdata();
			p2.display();
			p3.add(p1,p2);
			break;
		}
	} while (ch != 4);
}