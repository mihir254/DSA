#include <iostream>
using namespace std;

class String
{
private:
	char a[100];
	char b[100];

public:

	void getData()
	{
		cout<<"Enter a string: ";
		cin>>a;
	}

	void display()
	{
		cout<<"The entered string is: "<<a<<"\n";
	}

	void copy()
	{
		cout<<"Enter a string: ";
		cin>>b;
		for(int i=0;i<100;i++)
		{
			b[i]=a[i];
		}
		cout<<"The copied string is: "<<b;
	}

	void conc()
	{
		char c[100];
		cout<<"Enter a string: ";
		cin>>b;
		int counter1=0,counter2=0;
		for(int i=0;i<100;i++)
		{
			if(a[i]!='\0')
			{
				counter1++;
			}
			else
				break;
		}
		cout<<"The length of the string is:"<<counter1;

		for(int i=0;i<100;i++)
		{
			if(b[i]!='\0')
			{
				counter2++;
			}
			else
				break;
		}
		cout<<"The length of the string is:"<<counter2;

		for(int i=0;i<counter1;i++)
		{
			c[i]=a[i];
		}
		for(int i=0;i<counter2;i++)
		{
			c[counter1+i]=b[i];
		}
		cout<<"The concatenated string is: "<<c;
	}

	void equal()
	{
		int t=0;
		cout<<"Enter a string: ";
		cin>>b;
		for(int i=0;i<100;i++)
		{
			if(a[i]==b[i])
			{
				t++;
			}
			else
			break;
		}
		if(t==0)
		{
			cout<<"The strings are unequal!";
		}
		else
		{
			cout<<"The strings are equal!";
		}
	}

	void length()
	{
		int counter,i;
		for(i=0;a[i]!='\0';i++);
		counter=i;
		cout<<"The length of the string is:"<<counter;
	}

	void rev()
	{
		int counter,i;
		for(i=0;a[i]!='\0';i++);
		counter=i-1;
		cout<<"The length of the string is:"<<counter+1<<".";

		cout<<"The reversed string is:";
		for(i=counter;i>=0;i--)
		{
			cout<<a[i];
		}
	}

	void sub()
	{
		int count=0,temp=0;
		int len1,i,j,len2;
		cout<<"Enter the substring:";
		cin>>b;
		for(i=0;a[i]!='\0';i++);
			len1=i;

		for(j=0;b[j]!='\0';j++);
		len2=j;

		for(int i=0;i<len1;i++)
		{
			if(a[i]==b[count++])
			{
				if(count==len2)
				{
					temp=1;
				}
			}
			else
			{
				count=0;
			}
		}
		if(temp==1)
		{
			cout<<"It is a substring!";
		}
		else
		{
			cout<<"It is not a substring";
		}
	}

	void frequency()
	{
		int count=0;
		char x;
		cout<<"Enter the character whose frequency is to be determined:"<<endl;
		cin>>x;

		for(int i=0;i<100;i++)
		{
			if(a[i]==x)
			{
				count++;
			}
		}
		cout<<"The frequency of the given character is:"<<count<<endl;
	}

	void palindrome()
	{
		int counter,i,count=0,temp=0;
		for(i=0;a[i]!='\0';i++);
			counter=i-1;

			cout<<"The length of the string is:"<<counter+1<<".";
			cout<<"The reversed string is:";

			for(i=counter;i>=0;i--)
			{
				cout<<a[i];
				if(a[i]==a[counter-i])
				{
					count++;
					if(count==counter)
					{
						temp=1;
					}
				}
			}
			if(temp==1)
			{
				cout<<"The string is a palindrome!";
			}
			else
			{
				cout<<"The string is not a palindrome!";
			}
	}

	void charDelete()
	{
		char x;
		int length,i;
		for(i=0;a[i]!='\0';i++);
		length=i;

		cout<<"Enter a character to be removed:";
		cin>>x;

		for(int i=0;i<length;i++)
		{
			if(a[i]!=x)
			{
				cout<<a[i];
			}
		}
	}

	void del()
		{
			int len,start,m;
			cout<<"Enter the start and length:";
			cin>>start>>len;
			m=start+len;
			int length,i;
			for(i=0;a[i]!='\0';i++);
				length=i;

			for(int i=0;i<start-1;i++)
			{
				 cout<<a[i];
			}

			for(i=m-1;i<length;i++)
			{
				cout<<a[i];
			}
		}

	void replace()
	{
		char c[100];
		int count=0,temp=0,len1,i,len2,len3;

		cout<<"Enter the substring:";
		cin>>b;

		cout<<"Enter the string to be added:";
		cin>>c;

		for(i=0;a[i]!='\0';i++);
			len1=i;
			cout<<"The length of the string is:"<<len1<<endl;

		for(i=0;b[i]!='\0';i++);
			len2=i;
			cout<<"The length of the substring is:"<<len2<<endl;


		for(i=0;c[i]!='\0';i++);
			len3=i;
			cout<<"The length of the 'To be added string' is:"<<len3<<endl;

		for(int i=0;i<len1;i++)
		{
			if(a[i]==b[count++])
			{
				if(count==len2)
				{
					temp=1;
				}
				a[i]=c[i];
			}
			else
			{
				count=0;
			}
		}
		cout<<"The new string is:"<<endl;
		for(i=0;i<100;i++)
		{
			cout<<a[i];
		}


		if(temp==1)
		{
			cout<<"It is a substring!"<<endl;
		}
		else
		{
			cout<<"It is not a substring"<<endl;
		}

	}

};

int main()
{
	int c;
	String s;
	s.getData();
	s.display();

	do
	{
	cout<<"Enter choice:\n1)COPY.\n2)CHECK IF EQUAL.\n3)CONCATENATE.\n4)LENGTH.\n5)REVERSE.\n6)CHECK SUBSTRING.\n7)FREQUENCY.\n8)PALINDROME.\n9)DELETE A CHARACTER.\n10)DELETE A STRING.\n11)REPLACE.\n12)EXIT\n";
	cin>>c;
		switch(c)
		{
	    	case 1:
		    	s.copy();
			    break;
	    	case 2:
	    		s.equal();
	    		break;
	    	case 3:
	    		s.conc();
	    		break;
	    	case 4:
	    		s.length();
	    		break;
	    	case 5:
	    		s.rev();
	    		break;
	    	case 6:
	    		s.sub();
	    		break;
	    	case 7:
	    		s.frequency();
	    		break;
	    	case 8:
	    		s.palindrome();
	    		break;
	    	case 9:
	    		s.charDelete();
	    		break;
	    	case 10:
	    		s.del();
	    		break;
	    	case 11:
	    		s.replace();
	    		break;
		}
	}while(c<12);
}
