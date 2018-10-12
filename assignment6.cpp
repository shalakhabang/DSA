#include<iostream>
using namespace std;
struct node
{
char status;
node *next;
node *prev;
};
class sample
{
public: node *header;
	node *nn;
	sample()
	{
	header=NULL;
	}
	void insert();
	void display();
	void book();
	void cancel();
	

	
};
void sample:: insert()
    {	
	
	for(int j=0;j<7;j++) 
        {
	nn=new node;
	//cout<<"enter the status";
	//cin>>status;
	nn->status='A';
	nn->next=nn->prev=NULL;
	if(header==NULL)
	{
	header=nn;
	nn->next=header;
	nn->prev=header;
	}
	
	else
	{
	node *cn;
	cn=header;
	while(cn->next!=header)
	{
	cn=cn->next;
	}
	cn->next=nn;
	nn->prev=cn;
	nn->next=header;
	}
       }
   }

 void sample::display()
    {
	node*cn;
	cn=header;
	cout<<cn->status;
	cn=cn->next;
	while(cn!=header)
	{
	cout<<"\t";
	cout<<cn->status;
	cn=cn->next;
	}
   }

void sample::book()
    {
	int colm;
	cout<<"enter the column no. of seat to be booked";
	cin>>colm;

	node *cn;
	cn= header;
	for (int i=0;i<colm-1;i++)
	{
	cn=cn->next;
	}
	if(cn->status=='A')
	{
	cn->status='B';
	}
	 else if(cn->status=='B')
	{
	cout<<"the seat is already booked";
	}
   }

void sample::cancel()
  {
	int colm;
	cout<<"enter the colm no. of ur seat to  be cancelled";
	cin>>colm;
	node *cn;
	cn=header;
	for (int i=0;i<colm-1;i++)
	{
	cn=cn->next;
	}
	if(cn->status=='B')
	{
	cn->status='A';
	cout<<"your seat was cancelled";
	
	}
	 else if(cn->status=='A')
	{
	cout<<"the seat was not booked only";
	}
   }
	
 





    
int main()
{
int row,choice;
char ch;
sample s[10];
cout<<"enter y to continue and n to stop";
cin>>ch;
do
{
	
	cout<<" \n 1. to show available seats \n 2. to display \n 3. to book \n 4. to cancel";
	cout<<" \n enter your choice";
	cin>>choice;
	switch(choice)
	 {
		case 1: {
			for (int i=0;i<=9;i++)
			{
			s[i].insert();
			}
			break;
			}
		case 3:{
			cout<<" \n enter the row no. where u want to book a seat";
                        cin>>row;
			s[row-1].book();
			break;
			}
		case 4:{
			cout<<" \nenter the row no. of ur booked seat to be cancelled";
			cin>>row;
			s[row-1].cancel();
			break;
			}
		case 2:{
			for (int i=0;i<=9;i++)
			{
			cout<<"\n";
			s[i].display();
			}
			break;
			}
		
	}
	}
		while (ch=='y');
	
return 0;
}


