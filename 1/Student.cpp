//============================================================================
// Name        : matrix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class student
{
public:
	int marks;
	char x;
	char name[20];
	int roll_no;
};
double avg(student *s,int n)
{
	double total=0;
	double avg=0;

	for(int i=0;i<n;i++)
	{
		total=total+s[i].marks;
	}
	avg=total/n;
	return avg;
}
int high(student *s,int n)
{
	int h=0;
	for(int i=0;i<n;i++)
	{
		if(h<s[i].marks)
		{
			h=s[i].marks;
		}
	}
	return h;
}

int low(student *s,int n)
{
	int l=50;
	for(int i=0;i<n;i++)
	{
		if(l>s[i].marks)
		{
			l=s[i].marks;
		}
	}
	return l;
}

int absent(student *s,int n)
{
	int counter=0;
	for(int i=0;i<n;i++)
	{
		if(s[i].x=='A')
		{
			++counter;
			cout << "The absent roll number : " << s[i].roll_no << endl;
		}
	}
	return counter;
}

int main()
{
	int n,c; int i;
	std::cout<<"Enter the number of students\n";
	std::cin>>n;

	student s[30];
	std::cout<<"Enter roll number and marks resp : \n";
	for(i=0;i<n;i++)
	{
		std::cout<<"Enter roll number"<< i+1 << " : ";
		std::cin>>s[i].roll_no;
		std::cout<<"Enter attendance (P for present, A for absent)"<< i+1 << " : ";
		std::cin>>s[i].x;

		if(s[i].x=='A')
		{
			s[i].marks=0;
		}
		else if(s[i].x == 'P')
		{
			std::cout<<"Enter marks" << i+1 << " : ";
			std::cin>>s[i].marks;
		}
		else
		{
			cout << "Invalid Input!" << endl;
		}
	}
	do
	{
		std::cout<<"Enter 1 for average marks scored.\nEnter 2 for Highest marks scored.\nEnter 3 for Lowest marks scored.\nEnter 4 for list of absent students.\nEnter 5 for EXIT\n";
		std::cin>>c;

		switch(c)
		{
			case 1:
			{
				std::cout<<"The average marks of the students is:" << avg(s,n) << "\n";
				break;
			}
			case 2:
			{
				int max=high(s,n);
				for(i=0;i<n;i++)
				{
					if(s[i].marks==max)
					{
						std::cout << s[i].roll_no << ":";
					}
				}
				std::cout<<"Above roll numbers scored the highest marks: " << max <<"\n";

				break;
			}
			case 3:
			{
					int min=low(s,n);
					for(i=0;i<n;i++)
					{
						if(s[i].marks==min)
						{
							std::cout << s[i].roll_no << ":";
						}
					}
					std::cout<<"Above roll numbers scored the lowest marks: " << min <<"\n";

					break;
			}
			case 4:
			{
				std::cout<<"The total number of absent students is: " << absent(s,n) <<"\n";
				break;
			}
		}
	}while(c != 5);
	return 0;
}
