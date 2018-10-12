#include<iostream>
using namespace std;
#define size 5
class pizza
{
	struct que
	{
		int q1[size];
		int front,rear;
	}q;

	private: int n;
	public:pizza()
		{
		
			q.front=-1;
			q.rear=-1;
		}
		int qfull();
		int qempty();
		int accept(int);
		int ready();
		void dis();
};
int  pizza::qfull()
{
	if(q.front==(q.rear+1)%size)
		return 1;
	else
		return 0;
}
int  pizza::qempty()
{
	if(q.front==-1)
		return 1;
	else
		return 0;
}
int pizza::accept(int item)
{
	if(q.rear==-1)
	{
		q.front=q.rear=0;
		
	}
	else
	{
		q.rear=(q.rear+1)%size;
		
	}
	q.q1[q.rear]=item;
	return q.rear;
}
int pizza::ready()
{
	cout<<"\n order is ready: "<<q.q1[q.front];
	if(q.front==q.rear)
	{
		q.front=-1;
	}
	else
	{
		q.front=(q.front+1)%size;				
	}
}
void pizza::dis()
{
	int i;
	i=q.front;
	cout<<"\n orders are: ";
	while(i!=q.rear)
	{
			
		cout<<" "<<q.q1[i];
		i=(i+1)%size;
				
	}
	cout<<" "<<q.q1[i];
}

int main()
{
	
	pizza p;
	int c,item;
	char ch;
	cout<<"\t..........WELCOME TO DOMINOS...........\t";
	do
	{
		cout<<"\n1.add order\n2.ready order\n3.display orders\n enter choice:";
		cin>>c;
		switch(c)
		{
			case 1:if(p.qfull())
				cout<<"\n cannot accept order: ";
			else
			{
				cout<<"\n enter the order number: ";
				cin>>item;
				p.accept(item);
			}
			break;	
			case 2:if(p.qempty())
					cout<<"\nno order is ready: ";
				else
					p.ready();
				break;
			case 3:if(p.qempty())
					cout<<"\norder queue is empty: ";
				else
					p.dis();	
		}
		cout<<"\n want to continue (y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	
	return 0;
}
