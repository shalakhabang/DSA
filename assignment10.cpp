#include<iostream>
using namespace std;
struct node
{
	node *prev;
	node *next;
	int data;
};
class dequeue
{
public:
	node *nn;
	node *front;
	node *rear;
public:
	dequeue()
	{
		front='\0';
		rear='\0';
	}

	void get()
	{
		nn=new node;
		nn->next='\0';
		nn->prev='\0';
		cout<<"\nenter the data";
		cin>>nn->data;
	}
	void insert_rear()
	{
		get();		
		if(rear=='\0'&&front=='\0')
		rear=front=nn;
		else
		{
			rear->next=nn;
			nn->prev=rear;
			rear=nn;
		}
	}

	void insert_front()
	{
		get();
		if(front=='\0'&&rear=='\0')
		front=rear=nn;
		else
		{
		nn->next=front;
		front->prev=nn;
		front=nn;
		}
	}

	void remove_rear()
	{
		rear->prev->next='\0';
		rear=rear->prev;
	}
	
	void remove_front()
	{
		front=front->next;
	}

	void display()
	{

		if(front=='\0'&&rear=='\0')
		cout<<"queue is empty";
		else
		{
			node*cn;
			cn=front;
			while(cn!='\0')
			{
				cout<<cn->data<<"\t";
				cn=cn->next;
			}
		}
	}
};

int main()
{
dequeue d;
int choice;
cout<<".........IMPLEMENTING DEQUE USING LINKED LIST.................";
cout<<"\n1.insert at rear\n2.insert at front\n3.delete from rear\n4.delete from front\n5.to display\n6.to exit";
do
{
	
	cout<<"\nenter your choice";	
	cin>>choice;
	switch(choice)
	{
		case 1:
			d.insert_rear();
			break;
		case 2:
			d.insert_front();
			break;
		case 3:
			d.remove_rear();
			break;
		case 4:
			d.remove_front();
			break;
		case 5:
			d.display();
			break;
	}
}
while(choice!=6);
return 0;
}
