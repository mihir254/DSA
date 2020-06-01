#include<iostream>
using namespace std;

class node
{
public:
	string data;
	node *next;
	node *prev;
	node()
	{
		data = "NO JOB";
		next = NULL;
		prev = NULL;
	}
};

class queue : public node
{
	node *front;
	node *back;
public:
	queue()
	{
		front = NULL;
		back = NULL;
	}

	void add()
	{
		string info;

		cout << "Enter the job you want to add : " << endl;
		cin >> info;

		if (front == NULL)
		{
			front = new node;
			front->data = info;
			back = front;
		}
		else
		{
			back->next = new node;
			back->next->prev = back;
			back->next->data = info;
			back = back->next;
		}
	}

	void del()
	{
		node *temp;

		if (front == NULL)
		{
			cout << "The queue is empty !" << endl;
		}
		else
		{
			temp = front;
			front = temp->next;
			delete temp;
		}
	}

	void display()
	{
		node *temp;
		temp = front;

		cout <<"The queue of jobs looks like : " << endl;
		while(temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << "\n" << endl;
	}
};

int main()
{
	queue q;
	int ch;

	do
	{
		cout << "Enter the choice : \n1)Add a job to the queue\n2)Delete a job from the queue\n3)Display the queue of jobs\n4)Exit" << endl;
		cin >> ch;

		switch(ch)
		{
			case 1:
			q.add();
			break;
			case 2:
			q.del();
			break;
			case 3:
			q.display();
			break;
		}
	} while (ch != 4);
	return 0;
}
