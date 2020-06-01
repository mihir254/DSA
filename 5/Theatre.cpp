#include<iostream>
using namespace std;

class node
{
public:
	int data;
	char status;
	node *next;
	node *prev;

	node()
	{
		data = 0;
		status = 'U';
		next = NULL;
		prev = NULL;
	}
};
class theatre : public node
{
	node *head;

public:
	theatre()
	{
		head = NULL;
		}

	void setdata()
	{
		int x=1;
		node *temp = new node;
		if(head == NULL)
		{
			head = new node;
			head->data = x;
			head->status = 'A';
			head->next = head;
			head->prev = head;
		}
		temp = head;

		for (int i = 0; i < 70; ++i)
		{
			temp->next = new node;
			temp->next->next = head;
			temp->next->prev = temp;
			temp->next->data = x+1;
			temp->next->status = 'A';
			x++;
			temp = temp->next;
		}
	}

	void display()
	{
		node *temp = new node;
		temp = head;
		do
		{
			if(temp->data < 10)
			{
				cout<<0;
				cout<<temp->data<<temp->status<<"  ";
			}
			else
			{
				cout<<temp->data<<temp->status<<"  ";
			}
			if(temp->data%7 == 0)
			{
				cout<<"\n";
			}
			temp = temp->next;
		}while(temp->next != head);
	}

	void book()
	{
		int sum = 0;
		int n,count;
		cout<<"Enter the number of seats you want to book : "<<endl;
		cin>>count;
		cout<<"Enter the seat you want to book : "<<endl;
		for (int i = 0; i < count; ++i)
		{
			cout << "SEAT " << i+1 << ": ";
			cin>>n;

			node *temp = new node;
			temp = head;

			while(temp->next != head)
			{
				if(temp->data == n && temp->status == 'A')
				{
					temp->status = 'B';
					cout<<"Your seat has been successfully booked!"<<endl;
				}
				else if (temp->data == n && temp->status == 'B')
				{
					cout<<"Sorry! The seat has already been booked."<<endl;
					book();
				}
				temp = temp->next;
			}
		}
	}

	void cancel()
	{
		int n,count;
		cout<<"Enter the number of seats you want to cancel : "<<endl;
		cin>>count;
		for (int i = 0; i < count; ++i)
		{
			cout<<"Enter the seat you want to cancel : "<<endl;
			cin>>n;

			node *temp = new node;
			temp = head;

			while(temp->next != head)
			{
				if(temp->data == n && temp->status == 'B')
				{
					temp->status = 'A';
					cout<<"The cancelation has been confirmed, Thank you!\n"<<endl;
				}
				else if(temp->data == n && temp->status == 'A')
				{
					cout<<"The seat number "<<n<<" is NOT BOOKED\n"<<endl;
				}
				temp = temp->next;
			}
		}
	}
};

int main()
{
	int c;
	theatre t;

	cout<<"\n\n||||||||     PICT THEATRE     ||||||||"<<endl;
	cout<<"             SEAT BOOKING   \n"<<endl;

	t.setdata();
	t.display();

	do
	{
		cout<<"\n\nEnter the choice:\n1)Book Seat\n2)Cancel Booking\n3)Display Status\n4)Exit\nCHOICE : ";
		cin>>c;

		switch(c)
		{
			case 1:
				t.book();
				t.display();
				break;
			case 2:
				t.cancel();
				break;
			case 3:
				t.display();
				break;
			case 4:
				break;
		}
	}while(c!=4);
	return 0;
}
