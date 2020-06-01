//============================================================================
// Name        : simpe.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class deque
{
	int a[10];
	int front;
	int rear;

public:
	deque() {
	front = -1;
	rear = -1;
	}

	void pushFront();
	void pushBack();
	bool isEmpty();
	bool isFull();
	void delFront();
	void delBack();
	void display();
};

bool deque :: isFull() {
	return(front == 0 && rear == 9);
}

bool deque :: isEmpty() {
	return(front == rear);
}

void deque :: pushFront() {
	int x;

	cout << "Enter the element you want to push in front : ";
	cin >> x;

	if(isFull() || front == 0) {
		cout << "Overflow" << endl;
		return;
	}
	if(front == -1) {
		front ++;
		rear ++;
	}
	else {
		front = front -1;
	}
	a[front] = x;
}

void deque :: pushBack() {
	int x;

	cout << "Enter the element you want to push in front : ";
	cin >> x;

	if(isFull() || rear == 9) {
		cout << "Overflow" << endl;
		return;
	}
	if(front == -1) {
		front ++;
		rear ++;
	}
	else {
		rear = rear +1;
	}
	a[rear] = x;
}

void deque :: delFront() {
	if(isEmpty())
	{
		cout << "Underflow" << endl;
		return;
	}
	if(front == rear) {
		front = -1;
		rear = -1;
	}
	else {
		front++;
	}
}

void deque :: delBack() {
	if(isEmpty())
	{
		cout << "Underflow" << endl;
		return;
	}
	if(front == rear) {
		front = -1;
		rear = -1;
	}
	else {
		rear--;
	}
}

void deque :: display() {
	for(int i = front; i <= rear; i++) {
		cout << a[i] << "\t";
	}
	cout << "\n";
}

int main() {
	deque d;
		int ch;

		do
		{
			cout << "Enter the choice :\n1)Push Front\n2)Push Back\n3)Delete Front\n4)Delete Back\n5)Display\n6)Exit\n\nChoice : ";
			cin >> ch;
			switch(ch)
			{
			case 1:
				d.pushFront();
				break;
			case 2:
				d.pushBack();
				break;
			case 3:
				d.delFront();
				break;
			case 4:
				d.delBack();
				break;
			case 5:
				d.display();
				break;
			}
		}while(ch != 6);


		return 0;
}
