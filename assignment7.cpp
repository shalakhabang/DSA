#include<iostream>
using namespace std;
struct node
{
int bit;
node *next;
node *prev;
};
class binary
{
public:
	node *header;
	node *nn;
	binary()
	{
	header=NULL;
	}
	void get_binary();
	void calc_onescomp();
	void display();
	void calc_twocomp();
 	void add(binary,binary);
	
};
void binary::get_binary()
	{       
		
		nn=new node;
		cout<<"enter the bit";
		cin>>nn->bit;
		nn->next=nn->prev=NULL;
		if(header==NULL)
		{
		header=nn;
		}
		else
		{
		node *cn;
		cn=header;
		while(cn->next!=NULL)
		{
		cn=cn->next;
		}
		cn->next=nn;
		nn->prev=cn;
		}
	}


void binary:: calc_onescomp()               //function to calculate ones comp
   {    
	
	node*cn;
	cn=header;
	while(cn!=NULL)
	{
	if(cn->bit==0)
	{
	cn->bit=1;
	}
	else
	{
	cn->bit=0;
	}
	cn=cn->next;
       }
   }
       
void binary::display()                       //display a binary number
      {
	node *cn;
	cn=header;
	while(cn!=NULL)
	{
	cout<<cn->bit;
	cn=cn->next;
	}
      }  

void binary::calc_twocomp()                         //function to calculate twos complement
    {
	int carry=1;
	node *cn;
	cn=header;
	while(cn->next!=NULL)
	{
		
		cn=cn->next;
	}
	while(cn!=NULL)
	{
		if(cn->bit==1)
		{
		cn->bit=0;
		carry=1;
		}
		else
		{
		cn->bit=1;
		carry=0;
		break;
		}
	
	cn=cn->prev;
        } 
   }

void binary::add(binary x,binary y)
{
node *cn1;
node *cn2;
int sum=0,carry=0;
cn1= x.header;
cn2= y.header;
while(cn1->next!=header)
{
cn1=cn1->next;
}
while(cn2->next!=header)
{
cn2=cn2->next;
}
while(cn1!=NULL&&cn2!=NULL)
{
	sum=(cn1->bit+cn2->bit+carry)%2;
	carry=(cn1->bit+cn2->bit+carry)/2;
	node *nn;
	nn=new node;
	nn->next=nn->prev=NULL;
	nn->bit=sum;
	if(header==NULL)
	{
	   header=nn;
	}
	else
	{
	     node *cn;
	     cn=header;
	     while(cn->next!=NULL)
		{
		cn=cn->next;
		}
		cn->next=nn;
		nn->prev=cn;
        }
	cn1=cn1->prev;
	cn2=cn2->prev;
}
}
			




 int main()
{
 binary d;
 binary b;
 int choice;
 char ch;
do 
{
	 cout<<" \n enter \n 1 to input a binary number \n 2 to display \n 3 to calculate ones complement "; 
	 cout<<" \n 4 to calculate twos complement  \n 5 to add two binary numbers \n 6  to exit";
	 cin>>choice;
switch(choice)
{
case 1:
	{
		
		
		do
		{
		b.get_binary();
		cout<<"  \n enter y if u want to continue to add";
		cin>>ch;
		}
		while (ch=='y');
                break;
	}
case 2:
	{       cout<<"binary number is \t ";
		b.display();
	        break;
	}

case 3: 
	{
		b.calc_onescomp();
		cout<<"\n ones complement is \t";
		b.display();
		break;
	}

case 4:
	{
		b.calc_twocomp();
		cout<<"\n twos complement is \t";
		b.display();
		break;
	}

case 5:
	{
		binary a;
		do
		{
		d.get_binary();
		cout<<"  \n enter y if u want to continue to add";
		cin>>ch;
		}
		while (ch=='y');
		
		cout<<"the second binary no. is=";
		d.display();
		a.add(b,d);
		cout<<"sum of two binary nos =";
		a.display();
	}
		
}
}
while(choice!=6);
return 0;
}



 


	









		 
