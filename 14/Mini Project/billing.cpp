#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

class node
{
public:
	int num;
	string name;
	int price;
	int quantity;
	int tax;
	float tot3;
	node *next;
	node *prev;

	node()
	{
		num = 0;
		tax = 0;
		name = "UNDEFINED";
		price = 0;
		quantity = 0;
		next = NULL;
		prev = NULL;
		tot3 = 0;
	}
};

class bill : public node
{
	node *head;
	node *tail;

public:

	bill()
	{
		head = NULL;
		tail = NULL;
	}

	void add()
	{
		node *temp = new node;

		if(head == NULL)
		{
			head = temp;
			tail = temp;

			cout << "Enter the Item Number : " << endl;
			cin >> head->num;

			cout << "Enter the Item Name : " << endl;
			cin >> head->name;

			cout << "Enter the price of the Item : " << endl;
			cin >> head->price;
			if (head->price < 1)
			{
				cout << "Wrong price, please try again" << endl;
				cout << "Enter the price of the Item : " << endl;
				cin >> head->price;
			}

			cout << "Enter the quantity of this Item : " << endl;
			cin >> head->quantity;
			if (head->quantity < 1)
			{
				cout << "Wrong quantity, please try again" << endl;
				cout << "Enter the quantity of the Item : " << endl;
				cin >> head->quantity;
			}

			cout << "Enter the tax to be applied on this product : " << endl;
			cin >> head-> tax;
			if (head->tax < 1)
			{
				cout << "Wrong tax, please try again" << endl;
				cout << "Enter the tax of the Item : " << endl;
				cin >> head->tax;
			}
		}
		else
		{
			tail->next = new node;
			tail->next->prev = tail;
			tail = tail->next;

			cout << "Enter the Item Number : " << endl;
			cin >> tail->num;

			cout << "Enter the Item Name : " << endl;
			cin >> tail->name;

			cout << "Enter the price of the Item : " << endl;
			cin >> tail->price;
			if (head->price < 1)
			{
				cout << "Wrong price, please try again" << endl;
				cout << "Enter the price of the Item : " << endl;
				cin >> head->price;
			}

			cout << "Enter the quantity of this Item : " << endl;
			cin >> tail->quantity;
			if (head->quantity < 1)
			{
				cout << "Wrong quantity, please try again" << endl;
				cout << "Enter the quantity of the Item : " << endl;
				cin >> head->quantity;
			}

			cout << "Enter the tax to be applied on this product : " << endl;
			cin >> tail-> tax;
			if (head->tax < 1)
			{
				cout << "Wrong tax, please try again" << endl;
				cout << "Enter the tax of the Item : " << endl;
				cin >> head->tax;
			}
		}
	}

	void display(int flag, string nam)
	{
		node *temp = new node;
		temp = head;
		float tot1 = 0;
		float tot2 = 0;

		ofstream outf;
		outf.open(nam.c_str(), ios :: app);

		cout << "\n=============================================================================================================================" << endl;
		cout << "It.No.\t\t\tName\t\t\tPrice\t\t\tQuantity\t\tTax\t\tTotal" << endl;
		cout << "=============================================================================================================================" << endl;

		while(temp != NULL)
		{
			cout << temp->num << "\t\t\t";
			cout << temp->name << "\t\t\t";
			cout << temp->price << "\t\t\t";
			cout << temp->quantity << "\t\t\t";
			cout << temp -> tax << "\t\t";
			
			tot1 = (temp->price)*(temp->quantity);
			tot2 = tot1*(temp->tax)/100;
			temp -> tot3 = tot1 + tot2;
			cout << temp -> tot3 << endl;
			
			if (flag == 1)
			{
				
				outf << temp->num << "\t\t\t";
				outf << temp->name << "\t\t\t";
				outf << temp->price << "\t\t\t";
				outf << temp->quantity << "\t\t\t";
				outf << temp -> tax << "\t\t";
				outf << temp -> tot3 << endl;
			}
			temp = temp->next;
		}
	}

	void remove()
	{
		int x;

		cout << "Enter the item number which you want to delete : " << endl;
		cin >> x;

		node* temp = new node;
		node* hold = new node;
		temp = head;

		if (head == NULL)
		{
			cout << "Sorry, there are no items in your cart!" << endl;
		}
		else if (head == tail && head -> num == x)
		{
			temp = head;
			head = NULL;
			tail = NULL;
			delete temp;
		}
		else if (head -> num == x)
		{
			temp = head;
			head = head -> next;
			head -> prev = NULL;
			delete temp;
		}
		else if (tail -> num == x)
		{
			temp = tail;
			tail = tail -> prev;
			tail -> next = NULL;
			delete temp;
		}
		else
		{
			while(temp != NULL)
			{
				if (temp -> num == x)
				{
					hold = temp;
					temp = temp -> prev;
					temp -> next = hold -> next;
					hold -> next -> prev = hold -> prev;
					delete hold;
				}
				temp = temp -> next;
			}
		}
	}

	void edit()
	{
		int c;
		int x;
		node *temp = new node;
		temp = head;

		cout << "Enter the item number of the item you want to edit : " << endl;
		cin >> x;

		while(temp != NULL)
		{
			if (temp -> num == x)
			{
				do
				{
					cout << "The Item details are : " << endl;
					cout << temp -> num << "\t" << temp -> name << "\t" << temp -> price << "\t" << temp -> quantity << "\t" << temp -> tax << endl;

					cout << "\nEdit :\n1)Item Number\n2)Item Name\n3)Item Price\n4)Item Quantity\n5)Tax\n6)Exit\n\nCHOICE : " << endl;
					cin >> c;

					switch(c)
					{
						case 1:
						cout << "Enter the Item Number : " << endl;
						cin >> temp -> num;
						break;
						case 2:
						cout << "Enter the Item Name : " << endl;
						cin >> temp -> name;
						break;
						case 3:
						cout << "Enter the Item Price : " << endl;
						cin >> temp -> price;
						break;
						case 4:
						cout << "Enter the Item Quantity : " << endl;
						cin >> temp -> quantity;
						break;
						case 5:
						cout << "Enter the Tax : " << endl;
						cin >> temp -> tax;
						break;
					}
				} while (c != 6);
			}
			temp = temp -> next;
		}
	}

	void check()
	{
		int x;
		int flag = 0;

		cout << "Enter the item number of the item you want to check : " << endl;
		cin >> x;

		node *temp = new node;
		temp = head;

		while(temp != NULL)
		{
			if (temp -> num == x)
			{
				cout << "Item found !" << endl;
				cout << temp -> num << "\t" << temp -> name << "\t" << temp -> price << "\t" << temp -> quantity << "\t" << temp -> tax << endl;
				flag = 1;
			}
			temp = temp -> next;
		}

		if (flag == 0)
		{
			cout << "Item not found !" << endl;
		}
	}

	void Total(int flag, string nam)
	{
		float total = 0;
		node* temp = new node;
		temp = head;

		ofstream outf;
		outf.open(nam.c_str(), ios::app);

		while(temp != NULL)
		{
			total = total + (temp -> tot3);
			temp = temp -> next;
		}

		cout << "\nGRAND TOTAL = " << total << endl;
		
		if (flag == 1)
		{
			outf << "\nGRAND TOTAL = " << total << "\n" << endl;
		}
	}

	void exchange()
	{
		int x;
		float tot1,tot2,yolo,di;
		int flag = 0;

		cout << "Enter the item number of the item you want to exchange : " << endl;
		cin >> x;

		node *temp = new node;
		temp = head;

		while(temp != NULL)
		{
			if (temp -> num == x)
			{
				cout << "Item found !" << endl;
				
				cout << temp -> num << "\t" << temp -> name << "\t" << temp -> price << "\t" << temp -> quantity << "\t" << temp -> tax << endl;
				flag = 1;
				
				yolo = temp -> tot3;

				cout << "Enter the Product details of the new Item" << endl;

				cout << "\nEnter the Item Number : " << endl;
				cin >> temp->num;

				cout << "Enter the Item Name : " << endl;
				cin >> temp->name;

				cout << "Enter the price of the Item : " << endl;
				cin >> temp->price;

				cout << "Enter the quantity of this Item : " << endl;
				cin >> temp->quantity;

				cout << "Enter the tax to be applied on this product : " << endl;
				cin >> temp-> tax;

				tot1 = (temp->price)*(temp->quantity);
				tot2 = tot1*(temp->tax)/100;
				temp -> tot3 = tot1 + tot2;

				if (yolo > temp -> tot3)
				{
					di = yolo - temp->tot3;
					cout << "\nCash to be returned : " << di << endl; 
				}
				else
				{
					di = temp -> tot3 - yolo;
					cout << "\nYou need to pay : " << di << endl;
				}
			}
			temp = temp -> next;
		}

		if (flag == 0)
		{
			cout << "Item not found !" << endl;
		}
	}

	void record(string nam)
	{
		ifstream infile;
		int offset;
		string line;
		string search;
		int fish = 0;
		infile.open(nam.c_str());
		int pass;

		cout << "Enter the password : ";
		cin >> pass;

		if (pass == 21309)
		{
			cout << "\nEnter the date : ";
			cin >> search;

			cout << "\nSearching the bill on the given date.... ";

			if (infile.is_open())
			{
				while(!infile.eof())
				{
					getline(infile, line);
					if ((offset = line.find(search,0)) != string :: npos)
					{
						cout << "\nThe bill on the given date has been found." << endl;
						fish = 1;
					}
				}
				if (fish != 1)
				{
					cout << "\nSorry! There was no purchase on the given date." << endl;
				}
			infile.close();
			}
			else
			{
				cout << "\nError, No purchases by this name !" << endl;
			}
		}
		else
		{
			cout << "Sorry Wrong password !" << endl;
		}
  	}

  	void bag()
  	{
  		int counter = 0;
  		node *temp = new node;
  		temp = head;
  		while(temp != NULL)
  		{
  			counter++;
  			temp = temp -> next;
  		}
  		cout << "The total number of items is : " << counter << endl; 
  	}
};

int main()
{
	bill b;
	int ch;
	int flag = 0;

	string date, nam, city;
	
	system("clear");

	cout << "Enter Date : ";
	cin >> date;
	cin.ignore();
	cout << "\nEnter Name : ";
	getline(cin, nam);
	cout << "\nEnter Locality : ";
	getline(cin, city);

	system("clear");

	cout << "\nDate     : " << date << endl;
	cout << "Name     : " << nam << endl;
	cout << "Locality : " << city << endl;

	do
	{
		cout << "\n-----------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\nEnter the choice :\n\n1) Add Item\n2) Remove Item\n3) Display Purchased Items\n4) Edit Item\n5) Check Item\n6) Total\n7) Exchange Item from the bill\n8) Number of Items\n9) Bill Records\n10) Print Bill & Check Out\n11) Exit\n\nCHOICE : " << endl;
		cin >> ch;

		switch(ch)
		{
			case 1:
			b.add();
			break;
			case 2:
			b.remove();
			break;
			case 3:
			system("clear");
			b.display(flag, nam);
			break;
			case 4:
			b.edit();
			break;
			case 5:
			b.check();
			break;
			case 6:
			b.display(flag, nam);
			b.Total(flag, nam);
			break;
			case 7:
			b.exchange();
			break;
			case 8:
			b.bag();
			break;
			case 9:
			b.record(nam);
			break;
			case 10:
			flag = 1;

			system("clear");

			ofstream outf;
			outf.open(nam.c_str(), ios :: app);
			
			cout << "\n****************************************                   WELCOME                  ****************************************" << endl;
			cout << "\n________________________________________                  YOUR  BILL                 ________________________________________" << endl;

			outf << "\n\n\n****************************************                   WELCOME                   ****************************************" << endl;
			outf << "\n________________________________________                  YOUR  BILL                 ________________________________________" << endl;

			cout << "\n\nDate     : " << date << endl;
			cout << "Name     : " << nam << endl;
			cout << "Locality : " << city << endl;


			outf << "\n\nDate     : " << date << endl;
			outf << "Name     : " << nam << endl;
			outf << "Locality : " << city << endl;
			
			outf << "\n\n=============================================================================================================================" << endl;
			outf << "It.No.\t\t\tName\t\t\tPrice\t\t\tQuantity\t\tTax\t\tTotal" << endl;
			outf << "=============================================================================================================================" << endl;
			
			b.display(flag, nam);
			cout << "\n-----------------------------------------------------------------------------------------------------------------------------" << endl;
			outf << "\n-----------------------------------------------------------------------------------------------------------------------------" << endl;
			b.Total(flag, nam);
			cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
			outf << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "\n                                                  THANK YOU, VISIT AGAIN!\n" << endl;
			break;
		}
	}while(ch < 10);

	return 0;
}