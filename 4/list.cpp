//============================================================================
// Name        : list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
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
		next = NULL;
	}
};

class link:public node
{
private:
	node *p;
	node *s;
	node *temp;
public:
	link()
	{
		p = NULL;
		s = NULL;
		temp = NULL;
	}
	 void add_p()
	 {
		 temp = new node;
		 cout<<"Enter the PRN:"<<endl;
		 cin>>temp->PRN;
		 cout<<"Enter the name:"<<endl;
		 cin>>temp->name;

		 temp->next = NULL;

		 if(p == NULL)
		 {
			 p = temp;
			 s = temp;
		 }
		 else
		 {
			 temp->next = p;
			 p = temp;
		 }
	 }

	 void add_s()
	 {
		 temp = new node;
		 cout<<"Enter the PRN:"<<endl;
		 cin>>temp->PRN;
		 cout<<"Enter the name: "<<endl;
		 cin>>temp->name;

		 temp->next = NULL;

		 if(p == NULL)
		 {
			 p = temp;
			 s = temp;
		 }
		 else
		 {
			 s->next = temp;
			 s = temp;
		 }
	 }

	 void add_member()
	 {
		 temp = new node;

		 cout<<"Enter the PRN:"<<endl;
		 cin>>temp->PRN;
		 cout<<"Enter the name: "<<endl;
		 cin>>temp->name;

		 temp->next = NULL;

		 if(p == NULL)
		 {
			 p = temp;
			 s = temp;
		 }
		 else
		 {
			 temp->next = p->next;
			 p->next = temp;
		 }
	 }


	 void display()
	 {
		 cout<<"The President of the PINNACLE CLUB is:"<<p->PRN<<"\t"<<p->name<<endl;
		 cout<<"The secretary of the PINNACLE CLUB is:"<<s->PRN<<"\t"<<s->name<<endl;

		 temp = p;

		 cout<<"The members are:"<<endl;
		 while(temp != NULL)
		 {
			 cout<<temp->PRN<<"\t"<<temp->name<<endl;
			 temp = temp->next;
		 }
	 }

	 void participants()
	 {
		 int count = 0;

		 temp = p;

		 cout<<"The number of members are:";

		 while(temp != NULL)
		 {
			 count++;
			 temp = temp->next;
		 }
		 cout<<count<<endl;

	 }

	 void delete_first()
	 {
		 if(p == NULL)
		 {
			 return;
		 }
		 else
		 {
			 temp = new node;
			 temp = p;
			 p = temp->next;
			 delete temp;
		 }
	 }

	 void delete_last()
	 {
		 if(p == NULL)
		 {
			 return;
		 }
		 else
		 {
			 temp = new node;
			 while(temp->next != s)
			 {
				 temp = temp->next;
			 }
			 temp = s;
			 delete s;
		 }
	 }

	 void delete_middle()
	 {
		 string str;
		 cout<<"Enter the name you want to delete:"<<endl;
		 cin>>str;
		 if(p == NULL)
		 {
			 return;
		 }
		 else
		 {
			temp = p;
			while(temp->next->name != str)
			{
				temp = temp->next;
			}
			temp->next = temp->next->next;
			delete temp->next;
		 }
	 }

	 void reverse()
	 {
	 }

	 void new_list()
	 {
		 int sw;
		 cout<<"Enter the second list:"<<endl;

		do{
			 cout<<"Enter choice:\n1)Add President\n2)Add Secretary\n3)Add Member\n4)Display\n5)Exit\n";
			 cin>>sw;

			 switch(sw)
			 {
			 case 1:
				 add_p();
				 break;
			 case 2:
				 add_s();
				 break;
			 case 3:
				 add_member();
				 break;
			 case 4:
				 display();
				 break;
			 case 5:
				 break;
			}
		 }while(sw!=5);
	 }

	 void concatenate(link l, link m)
	 	{
		 	link y;
		    l.s->next = m.p;
		    l.temp = l.p;
		    y.temp = y.p;
		    while(l.temp != NULL)
		    {
		    	y.temp = l.temp;
		    	temp = temp->next;
		    }

		    m.temp = m.p;
		    while(m.temp != NULL)
		    {
		    	y.temp = m.temp;
		    	temp = temp->next;
		    }

		    y.p = l.p;
		    y.s = m.s;

			cout<<"The President of the PINNACLE CLUB is:"<<y.p->PRN<<"\t"<<y.p->name<<endl;
			cout<<"The secretary of the PINNACLE CLUB is:"<<y.s->PRN<<"\t"<<y.s->name<<endl;

			y.temp = y.p;

			cout<<"The members are:"<<endl;
			while(y.temp != NULL)
			{
			   cout<<y.temp->PRN<<"\t"<<y.temp->name<<endl;
			   y.temp = y.temp->next;
			}
	 	}
};

int main()
{
	link l;
	link m;
	int c;

	do
	{
		cout<<"Enter choice:\n1)Add president\n2)Add secretary\n3)Add member\n4)Delete President\n5)Delete Secretary\n6)Delete member\n7)Display\n8)Number of participants\n9)New List\n10)Concatenate\n11)Exit\n"<<endl;
		cin>>c;

		switch(c)
		{
		case 1:
			l.add_p();
			break;
		case 2:
			l.add_s();
			break;
		case 3:
			l.add_member();
			break;
		case 4:
			l.delete_first();
			break;
		case 5:
			l.delete_last();
			break;
		case 6:
			l.delete_middle();
			break;
		case 7:
			l.display();
			break;
		case 8:
			l.participants();
			break;
		case 9:
			m.new_list();
			break;
		case 10:
			l.concatenate(l,m);
			break;
		case 11:
			break;
		}
	}while(c!=11);
}
