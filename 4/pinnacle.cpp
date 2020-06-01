#include<iostream>
using namespace std;

class node
{
public:
	int PRN;
	string name;
	node *next;
	node()
	{
		PRN = 0;
		name = "NONAME";
		next = NULL;
	}
};

class club : public node
{
public:
	node *head;
	node *tail;
	club()
	{
		head = NULL;
		tail = NULL;
	}

	void add()
	{
		node *temp = new node;
		
		cout << "Enter the PRN of the member : " << endl;
		cin >> temp->PRN;
		cout << "Enter the name of the member : " << endl;
		cin >> temp->name;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}

	int display()
	{
		node *temp = new node;
		
		if (head == NULL)
		{
			cout << "The club has no members yet !" << endl;
			return -1;
		}

		cout << "PRESIDENT PRN : " << head->PRN << " \nPRESIDENT NAME : " << head->name << "\n" << endl;
		cout << "SECRETARY PRN : " << tail->PRN << " \nSECRATARY NAME : " << tail->name << "\n" << endl;

		temp = head;

		cout << "\nMEMBERS : \n\n";
		while(temp != NULL)
		{
			cout << temp->name << "   " << temp->PRN << endl;
			temp = temp->next;
		}
		return 1;
	}

	void remove()
	{
		int exor;
		int flag = 0;
		cout << "Enter the PRN of the member you want to remove : " << endl;
		cin >> exor;
		node *temp = new node;
		temp = head;
		while(temp != NULL)
		{
			if (temp->PRN == exor)
			{
				if (temp == head)
				{
					head = head->next;
					delete temp;
				}
				else if(temp == tail)
				{
					node *t = new node;
					t = head;
					while(t->next->PRN != exor)
					{
						t = t->next;
					}
					tail = t;
					t = t->next;
					delete t;
				}
				else
				{
					node *t = new node;
					t = head;
					while(t->next->PRN != exor)
					{
						t = t->next;
					}
					t->next = temp->next;
					delete temp;
				}
				flag = 1;
			}
			temp = temp->next;
		}

		if (flag == 1)
		{
			cout << "FOUND AND REMOVED" << endl;
		}
		else
		{
			cout << "NOT FOUND!" << endl;
		}
	}

	void number()
	{
		int count = 0;
		node *temp = new node;
		temp = head;
		while(temp != NULL)
		{
			count ++;
			temp = temp->next;
		}
		cout << "The number of members is : " << count  << endl;
	}

	void two()
	{
		cout << "THIS IS THE SECOND CLUB !" << endl;
		 int sw;

		do{
			cout<<"Enter choice:\n1)Add Member\n2)Remove Member\n3)Display\n4)Exit\n";
			cin>>sw;

			switch(sw)
			{
			case 1:
				add();
				break;
			case 2:
			remove();
				break;
			case 3:
				display();
				break;
			}
	 	}while(sw!=4);
	}

	void conc(club l, club m)
	{
		l.tail->next = m.head;
		node* temp = new node;
		temp = l.head;
		while(temp != NULL)
		{
			cout << temp->name << "   " << temp->PRN << endl;
			temp = temp->next;
		}
	}

	void reverse(node* head1)
	{
		if (head1 != NULL)
		{
			reverse(head1->next);
			cout << head1->name << "   " << head1->PRN << "\n";
		}
	}
};

int main()
{
	club l;
	club m;
	club n;
	int c;

	do
	{
		cout<<"\nEnter choice:\n1)Add Mmeber\n2)Delete member\n3)Display\n4)Number of participants\n5)New List\n6)Concatenate\n7)Reverse\n8)Exit\n"<<endl;
		cin>>c;

		switch(c)
		{
		case 1:
		l.add();
		break;
		case 2:
		l.remove();
		break;
		case 3:
		l.display();
		break;
		case 4:
		l.number();
		break;
		case 5:
		m.two();
		break;
		case 6:
		n.conc(l,m);
		break;
		case 7:
		cout << "The reversed list is : \n" << endl;
		l.reverse(l.head);
		break;
		}
	}while(c!=8);
	return 0;
}