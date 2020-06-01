#include <iostream>
using namespace std;
class Sparse{
	int row, col, val, sparse[50][3];
public:
	void accept();
	void display();
	void addition(Sparse &s2, Sparse &s3);
	void transpose(Sparse &s2);
	void fast_transpose(Sparse &s2);


};
void Sparse::accept()
{
	cout<<"Enter number of rows: ";
	cin>>sparse[0][0];
	cout<<"Enter number of columns: ";
	cin>>sparse[0][1];
	cout<<"Enter total number of non zero elements: ";
	cin>>sparse[0][2];
	cout<<"NOTE:- Users should enter rows in sorted form and columns within rows in sorted form. "<<endl;
	for(int i=1; i<=sparse[0][2]; i++)
	{
		cout<<"Row: ";
		cin>>sparse[i][0];
		cout<<"Column: ";
		cin>>sparse[i][1];
		cout<<"Value: ";
		cin>>sparse[i][2];
	}
}
void Sparse::display()
{
	cout<<"row\tcolumn\tvalue\n";
	for(int i=0; i<=sparse[0][2]; i++)
	{

		for(int j=0; j<3; j++)
			cout<<sparse[i][j]<<"\t";
		cout<<endl;
	}
}
void Sparse::addition(Sparse &s2, Sparse &s3)
{
	if(sparse[0][0]== s2.sparse[0][0] && sparse[0][1]== s2.sparse[0][1])
	{
		int k1,  k2, k3;
		k1=k2=k3=1;
		while(k1<=sparse[0][2] && k2<=s2.sparse[0][2])
		{
			if(sparse[k1][0] < s2.sparse[k2][0])
			{
				s3.sparse[k3][0]=sparse[k1][0];
				s3.sparse[k3][1]=sparse[k1][1];
				s3.sparse[k3][2]=sparse[k1][2];
				k1++;
				k3++;
			}
			else if(sparse[k1][0] > s2.sparse[k2][0])
			{
				s3.sparse[k3][0]=s2.sparse[k2][0];
				s3.sparse[k3][1]=s2.sparse[k2][1];
				s3.sparse[k3][2]=s2.sparse[k2][2];
				k2++;
				k3++;
			}
			else
			{
				if(sparse[k1][1] < s2.sparse[k2][1])
				{
					s3.sparse[k3][0]=sparse[k1][0];
					s3.sparse[k3][1]=sparse[k1][1];
					s3.sparse[k3][2]=sparse[k1][2];
					k1++;
					k3++;
				}
				else if(sparse[k1][1] > s2.sparse[k2][1])
				{
					s3.sparse[k3][0]=s2.sparse[k2][0];
					s3.sparse[k3][1]=s2.sparse[k2][1];
					s3.sparse[k3][2]=s2.sparse[k2][2];
					k2++;
					k3++;
				}
				else
				{
					s3.sparse[k3][0]=sparse[k1][0];
					s3.sparse[k3][1]=sparse[k1][1];
					s3.sparse[k3][2]=sparse[k1][2]+s2.sparse[k2][2];
					k1++;
					k2++;
					k3++;
				}
			}
		}
		while(k1<=sparse[0][2])
		{
			s3.sparse[k3][0]=sparse[k1][0];
			s3.sparse[k3][1]=sparse[k1][1];
			s3.sparse[k3][2]=sparse[k1][2];
			k1++;
			k3++;
		}
		while(k2<=s2.sparse[0][2])
		{
			s3.sparse[k3][0]=s2.sparse[k2][0];
			s3.sparse[k3][1]=s2.sparse[k2][1];
			s3.sparse[k3][2]=s2.sparse[k2][2];
			k2++;
			k3++;
		}
		s3.sparse[0][0]=sparse[0][0];
		s3.sparse[0][1]=sparse[0][1];
		s3.sparse[0][2]=(k3-1);
	}
}
void Sparse::transpose(Sparse &s2)
{
	int k1=1;
	for(int i=0; i<sparse[0][1]; i++)
	{
		for(int j=1; j<=sparse[0][2]; j++)
		{
			if(i==sparse[j][1])
			{
				s2.sparse[k1][0]=sparse[j][1];
				s2.sparse[k1][1]=sparse[j][0];
				s2.sparse[k1][2]=sparse[j][2];
				k1++;
			}
		}
	}
	s2.sparse[0][0]=sparse[0][0];
	s2.sparse[0][1]=sparse[0][1];
	s2.sparse[0][2]=sparse[0][2];
}

void Sparse::fast_transpose(Sparse &s2)
{
	int n=sparse[0][1];
	int count[n], pos[n];
	for(int i=0; i<n; i++)
	{
		count[i]=0;
		pos[i]=0;
	}
	for(int i=1; i<=sparse[0][2]; i++)
		count[sparse[i][1]]++;
	pos[0]=1;
	for(int i=1; i<sparse[0][1]; i++)
		pos[i]=(pos[i-1]+count[i-1]);
	for(int i=1; i<=sparse[0][2]; i++)
	{
		n=pos[sparse[i][1]];
		pos[sparse[i][1]]++;
		s2.sparse[n][0]= sparse[i][1];
		s2.sparse[n][1]= sparse[i][0];
		s2.sparse[n][2]= sparse[i][2];
	}
	s2.sparse[0][0]=sparse[0][0];
	s2.sparse[0][1]=sparse[0][1];
	s2.sparse[0][2]=sparse[0][2];
}
int main()
{

	Sparse s1, s2, s3;
	int ch;
	char con;
	do{
		cout<<"1. Addition of two sparse matrix\n";
		cout<<"2. Normal transpose of matrix\n";
		cout<<"3. Fast transpose of matrix\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter first matrix: \n";
			s1.accept();
			s1.display();
			cout<<endl;
			cout<<"Enter second matrix: \n";
			s2.accept();
			s2.display();
			cout<<endl;
			cout<<"Result of addition is: \n";
			s1.addition(s2,s3);
			s3.display();
			break;
		case 2:
			cout<<"Enter a matrix: \n";
			s1.accept();
			s1.display();
			cout<<endl;
			cout<<"Transpose of matrix is: \n";
			s1.transpose(s2);
			s2.display();
			break;
		case 3:
			cout<<"Enter a matrix: \n";
			s1.accept();
			s1.display();
			cout<<endl;
			cout<<"Transpose of matrix is: \n";
			s1.fast_transpose(s2);
			s2.display();
			break;
		default:
			cout<<"Invalid choice!! Please try again.";
		}
		cout<<"\nDo you want to continue?(Y/N): ";
		cin>>con;
	}
	while(con=='y' || con=='Y');
}
