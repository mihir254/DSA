#include<iostream>
using namespace std;

class node
{
public:
	int roll;
	string ice1;
	string ice2;
	node *next;
	node *prev;
	node()
	{
		roll = 0;
		ice1 = "NO";
		ice2 = "NO";
		next = NULL;
		prev = NULL;
	}
};

class ice : public node
{
	node *head;
public:
	ice()
	{
		head = NULL;
	}

	void getdata()
	{
		node *temp = new node;

		int x, count = 0;
		
		cout << "Enter the number of the students : " <<  endl;
		cin >> x;
		
		if (head == NULL)
		{
			head = new node;
			head->roll = ++count;
		}
		
		temp = head;
		
		for (int i = 0; i < x-1; ++i)
		{
			temp->next = new node;;
			temp->next->roll = ++count;
			temp->next->prev = temp;
			temp = temp->next;
		}
	}

	void display()
	{
		cout << "\nThe roll numbers are : " << endl;
		node *temp = new node;
		temp = head;
		while(temp != NULL)
		{
			cout << temp->roll << "\t";
			temp = temp->next;
		}
		cout << "\n";
	}

	void vanilla()
	{
		node *temp = new node;
		int x;
		cout << "\nEnter the number of students who like vanilla icecream : "<< endl;
		cin >> x;
		for (int i = 0; i < x; ++i)
		{
			int m;
			cout << "\nEnter the roll number : " << endl;
			cin >> m;

			temp = head;
			
			while(temp->roll != m)
			{
				temp = temp->next;
			}
			temp->ice1 = "YES";
		}

		temp = head;
		cout << "\nThe students who like vanilla icecream are : "<< endl;
		while(temp != NULL)
		{
			if (temp->ice1 == "YES")
			{
				cout << temp->roll << "\t";
 			}
 			temp = temp->next;
		}
		cout << "\n";
	}

	void butterscotch()
	{
		node *temp = new node;
		int x;
		cout << "\nEnter the number of students who like butterscotch icecream : "<< endl;
		cin >> x;
		for (int i = 0; i < x; ++i)
		{
			int m;
			cout << "\nEnter the roll number : " << endl;
			cin >> m;

			temp = head;
			
			while(temp->roll != m)
			{
				temp = temp->next;
			}
			temp->ice2 = "YES";
		}

		temp = head;
		cout << "\nThe students who like butterscotch icecream are : "<< endl;
		while(temp != NULL)
		{
			if (temp->ice2 == "YES")
			{
				cout << temp->roll << "\t";
 			}
 			temp = temp->next;
		}
		cout << "\n";
	}

	void both()
	{
		node *temp = new node;
		temp = head;
		cout << "\nThe students who like both the icecreams are : "<< endl;
		while(temp != NULL)
		{
			if (temp->ice2 == "YES" && temp->ice1 == "YES")
			{
				cout << temp->roll << "\t";
 			}
 			temp = temp->next;
		}
		cout << "\n";
	}

	void none()
	{
		node *temp = new node;
		temp = head;
		cout << "\nThe students who like none of the icecreams are : "<< endl;
		while(temp != NULL)
		{
			if (temp->ice2 == "NO" && temp->ice1 == "NO")
			{
				cout << temp->roll << "\t";
 			}
 			temp = temp->next;
		}
	}
};

int main()
{
	ice i;
	i.getdata();
	i.display();
	i.vanilla();
	i.butterscotch();
	i.both();
	i.none();
	return 0;
}