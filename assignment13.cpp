#include<iostream>
using namespace std;
class sort
{
private:
	float array[50];
	int n;
	
public:
	sort()
	{
		for(int i=0;i<10;i++)
		{
			array[i]=0;
		}
	}
	
	void get()
	{
		cout<<"enter the no. of students";
		cin>>n;
		cout<<" \n enter the percentage of students";
		for(int i=0;i<n;i++)
		{
			cin>>array[i];
		}
	}

	void selection()
	{
		int i,j,min,temp;
		for(i=0;i<=n-2;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			{
				if(array[j]<array[min])
				min=j;
			}
		temp=array[min];
		array[min]=array[i];
		array[i]=temp;
		}
		
	}

	void bubble()
	{
		int i;
		int pass;
		for(pass=1;pass<n;pass++)
		{
			for(i=0;i<(n-pass);i++)
			{
				if(array[i]>array[i+1])
				{
					int temp;
					temp=array[i];
					array[i]=array[i+1];
					array[i+1]=temp;
				}
			}
		}
	}
	void display()
	{
		for(int i=0;i<n;i++)
		{
			
			cout<<"\t"<<array[i];
		}
	}

	void toppers()
	{
		int i=n-1;
		while(i>=n-5)
		{
			cout<< "\t"<<array[i];
			i--;
		}
	}
			
};

int main()
{
	sort s;
	int choice;
	cout<<"*********SELECTION SORT\n*********BUBBLE SORT\n";
do
{
	cout<<"\n1.to get an array\n2.sort using selection sort\n3.sort using bubble sort\n4.to display array\n5.to display top five scores\n6.to exit";
	cin>>choice;
	switch(choice)
	{
		case 1:
			s.get();
			break;
		case 2:
			s.selection();
			break;
		case 3:
			s.bubble();
			break;
		case 4:
			s.display();
			break;
		case 5:
			cout<<"\nTop five scores are\n";
			s.toppers();
			break;


	}
}
while(choice!=6);
	return 0;
}
