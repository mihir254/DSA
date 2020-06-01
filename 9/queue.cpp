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
		data = "NODATA";
		next = NULL;
		prev = NULL;
	}
};

class job : public node
{
	node *front;
	node *rear;
public:
	job()
	{
		front = NULL;
		rear = NULL;
	}

	void add()
	{
		string s;

		cout << "\nEnter the job you want to add to the queue : " << endl;
		cin >> s;

		if (front == NULL)
		{
			front = new node;
			front->data = s;
			rear = front;
		}
		else
		{
			rear->next = new node;
			rear->next->prev = rear;
			rear = rear->next;
			rear->data = s;
		}
	}

	void del()
	{
		node *temp = new node;
		temp = front;
		front = front->next;
		delete temp;
		if (front == NULL)
		{
			cout << "The job queue is empty, there's nothing to delete!" << endl;
		}
	}

	void display()
	{
		cout << "\nThe job list looks like : \n" << endl;
		node *temp = new node;
		temp = front;
		while(temp != NULL)
		{
			cout << temp->data << "\n";
			temp = temp->next;
		}
		if (front == NULL)
		{
			cout << "The job queue is empty!" << endl;
		}
	}
};

int main()
{
	job q;
	int ch;

	do
	{
		cout << "\n\nEnter the choice : \n1)Add a job to the queue\n2)Delete a job from the queue\n3)Display the queue of jobs\n4)Exit" << endl;
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