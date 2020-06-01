#include <iostream>
using namespace std;

class matrix
{
private:
	int r,c;
	int a[3][3];
	int b[3][3];
	int s[3][3];

public:
	void null(int r,int c)
	{
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				a[i][j]=0;
			}
		}
	}

	void getData(int r,int c)
	{
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cout<<"Enter element: \n";
				cin>>a[i][j];
			}
		}

	}

	void display(int r,int c)
	{
		for(int i=0;i<r;i++)
				{
					for(int j=0;j<c;j++)
					{
						cout<<a[i][j]<<"\t";
					}
					cout<<"\n";
				}

	}

	void sum()
	{
		int i,j;
		for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					cout<<"Enter element: \n";
					cin>>b[i][j];
				}
			}
		for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					cout<<b[i][j]<<"\t";
				}
					cout<<"\n";
			}


		for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					s[i][j]=a[i][j]+b[i][j];
				}
			}
		cout<<"The sum of two matrices is: \n";
		for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					cout<<s[i][j]<<"\t";
				}
					cout<<"\n";
				}
	}

	void dif()
		{
			cout<<"Enter element: \n";
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<"Enter element: \n";
					cin>>b[i][j];
				}
			}
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<c;j++)
					{
						cout<<b[i][j]<<"\t";
					}
						cout<<"\n";
				}
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<c;j++)
					{
						s[i][j]=a[i][j]-b[i][j];
					}
				}
			cout<<"The diff of two matrices is: \n";
			for(int i=0;i<r;i++)
				{
				for(int j=0;j<c;j++)
					{
						cout<<s[i][j]<<"\t";
					}
						cout<<"\n";
					}
		}
	void mul()
		{
			int p,q;
			cout<<"Enter the number of rows and columns of the second matrix: \n";
			cin>>p>>q;

			for(int i=0;i<p;i++)
			{
				for(int j=0;j<q;j++)
				{
					cout<<"Enter element: \n";
					cin>>b[i][j];
				}
			}
			if(c==p)
			{
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<q;j++)
					{
						s[i][j]=0;
						for(int k=0;k<c;++k)
						{
							s[i][j]=s[i][j]+(a[i][j]*b[i][j]);
							cout<<s[i][j]<<":";
						}
						cout<<"\n";
					}
				}
			}
			else
			{
				cout<<"No Multiplication!";
			}
		}


	void ut()
	{
		int i,j;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(j<i)
				{
					cout<<"Upper Triangular!\n";
				}
				else
				{
					cout<<"Not Upper Triangular!";
				}
			}
		}
	}

	void dia()
	{
		int i,j,d=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i==j)
				{
					d=d+a[i][j];
				}
			}
		}
	}

	void trans()
	{
		int i,j;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				a[i][j]=a[j][i];
			}
		}
	}

	void sad()
	{
		int i,j,y,z,k,least,max;

		for(i=0;i<r;i++)
		{
			least=a[i][0];
			for(j=0;j<c;j++)
			{
				if(least>a[i][j])
				{
					least=a[i][j];
					y=j;
				}
			}

			max=a[0][y];

			for(k=0;k<r;++k)
			{
				if(max<a[k][y])
				{
					max=a[k][y];
					z=k;
				}
			}
		}
		if(max==a[z][y] && least==a[z][y])
		{
			cout<<"The Saddle Point is: "<<a[z][y];
		}
	}
};

int main()
{
	int r,q,c;
	cout<<"Enter number of rows: ";
	cin>>r;
	cout<<"Enter number of columns: ";
	cin>>c;

	matrix m;
	m.null(r,c);
	m.getData(r,c);
	m.display(r,c);


do{
	cout<<"Enter choice:\n1)ADD.\n2)DIFFERENT.\n3)MULTIPLICATION.\n4)CHECK IF UPPER TRIANGULAR.\n5)TRANSPOSE.\n6)SADDLE POINT.\n7)EXIT";
	cin>>q;

	switch(q)
	{
	case 1:
	{
		m.sum();
		break;
	}
	case 2:
	{
		m.dif();
		break;
	}
	case 3:
	{
		m.mul();
		break;
	}
	case 4:
	{
		m.ut();
		break;
	}
	case 5:
	{
		m.trans();
		break;
	}
	case 6:
	{
		m.sad();
		break;
	}
	default:
	{
		break;
	}
	}
}while(c != 7);

	return 0;
}
