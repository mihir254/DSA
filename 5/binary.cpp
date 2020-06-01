#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		node *prev;
		node()
		{
			data = 0;
			next = NULL;
			prev = NULL;
		}
};

class binary
{
	public:
	node *head;
	binary()
	{
		head = NULL;
	}	
	
	void setdata()
	{
		int bin, r;
		cout << "Enter the number : " << endl;
		cin >> bin;
		
		while(bin != 0)
		{
			r = bin%2;
			bin = bin/2;
			insert(r);
		}
	}
	
	void insert(int r)
	{
		if(head == NULL)
			{
				head = new node;
				head->data = r;
			}
			else
			{
				head->prev = new node;
				head->prev->next = head;
				head = head->prev;
				head->data = r;
			}
	}
	
	void display()
	{
		cout << "The binary number is : " << endl;
		node *temp = new node;
		temp = head;
		while(temp != NULL)
		{
			cout << temp->data;
			temp = temp->next;
		}
		cout << "\n";
	}
	
	void ones()
	{
		node *temp = new node;
		temp = head;
		while(temp != NULL)
		{
			if(temp->data == 0)
			{
				temp->data = 1;
			}
			else if(temp->data == 1)
			{
				temp->data = 0;
			}
			cout << temp->data;
			temp = temp->next;
		}
		cout << "\n";
	}
	
	void twos()
	{
		int c = 1;
		node *temp = new node;
		temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		while(temp != NULL)
		{
			if(temp->data == 0 && c == 0)
			{
				temp->data = 0;
				c = 0;
			}
			else if(temp->data == 1 && c == 1)
			{
				temp->data = 0;
				c = 1;
			}
			else
			{
				temp->data = 1;
				c = 0;
			}
			temp = temp->prev;
		}
	}
	
	void add(binary x,binary y)
	{
		int c= 0;
		node *t = x.head;
		node *p = y.head;
		node *temp = head;
	
		while(t->next!=NULL)
		{
			t = t->next;
		}
	
		while(p->next != NULL)
		{
			p = p->next;
		} 
	
		while(t != NULL && p != NULL)
		{
			if(t->data == 0 && p->data == 0 && c == 0)
			{
				insert(0);
				c=0;
			}
			else if(t->data==1 && p->data == 1 && c == 1)
			{
				insert(1);
				c=1;
			}
			else if((t->data == 0 && p->data == 0 && c == 1) ||(t->data == 0 && c == 0 && p->data == 1) || (p->data == 0 && c == 0 && t->data == 1))
			{
				insert(1);
				c=0;
			}
			else
			{
				insert(0);
				c=1;
			}
			t = t->prev;
			p = p->prev;
		}
	
		while(t != NULL)
		{
			if(c + t->data == 0)
			{
				insert(0);
				c=0;
			}
			if(c + t->data == 1)
			{
				insert(1);
				c=0;
			}
			if(c + t->data == 2)
			{
				insert(0);
				c=1;
			}
			t=t->prev;
		}
	
		while(p != NULL)
		{
			if(c+p->data==0)
			{
				insert(0);
				c=0;
			}
			if(c+p->data==1)
			{
				insert(1);
				c=0;
			}
			if(c+p->data==2)
			{
				insert(0);
				c=1;
			}
			p=p->prev;
		}
		
		if(c == 1)
		{
			insert(1);
		}
	}
};

int main()
{
	binary b, g, d, f;
	b.setdata();
	b.display();
	cout << "The one's compliment is : \n";
	b.ones();
	b.display();
	cout << "The one's compliment is : \n";
	b.ones();
	b.display();
	cout << "The two's compliment is : \n";
	b.ones();
	b.twos(); 
	b.display();
	d.setdata();
	d.display();
	g.setdata();
	g.display();
	f.add(g, d);
	f.display();
	return 0;
}
