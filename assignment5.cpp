#include<iostream>
using namespace std;
struct node
{
int prn;                       //data field of link list
string name;
node *next;                    //address field
};
class pinnacle
{
public:
	node *nn;
	node *header;
public:
	pinnacle()     //default const.
	{
	header='\0';
	}
	void ins();                                                         // inserting members
	void ins_presi();                                                   //insert president data
	void ins_secret();                                                  // insert secretary data
	void disp();                                                        // display link list
	void remove();                                                      // delete some member
	void concatenate(pinnacle,pinnacle);
	void reverse(node*temp);
};


void pinnacle::ins_presi()                                                        //insert president data
{
nn=new node;
cout<<"enter the prn no. of president";
cin>>nn->prn;
cout<<"enter the name of president";
cin>>nn->name;
nn->next='\0';
if(header=='\0')
{
header=nn;
}
}



void pinnacle::ins_secret()                                                         //insert secretary data
{
nn=new node;
cout<<"enter the prn no. of secretary";
cin>>nn->prn;
cout<<"enter the name of secretary";
cin>>nn->name;
node *cn;
cn=header;
while(cn->next!='\0')
{
cn=cn->next;
}
cn->next=nn;
nn->next='\0';
}


void pinnacle::ins()                                                                   //insert member data
{
nn=new node;
cout<<"enter the prn no. of member";
cin>>nn->prn;
cout<<"enter the name of member";
cin>>nn->name;
node *cn;
cn=header;
while(cn->next!='\0')
{
cn=cn->next;
}
cn->next=nn;
nn->next='\0';
}
void pinnacle::disp()
{
node*cn;
cn=header;
while(cn!='\0')
{
cout<<cn->prn;
cout<<"\t";
cout<<cn->name;
cout<<"\n";
cn=cn->next;
}
}


void pinnacle::remove()                                                       //delete  data
{
int check;
cout<<"enter the prn number of member to be deleted";
cin>>check;
node*cn;
cn=header;
while(cn->next->prn!=check)
{
cn=cn->next;
}
cn->next=cn->next->next;
}


void pinnacle::concatenate(pinnacle a, pinnacle b)                       //concatenate
{
	node *cn;
	cn=a.header;
	while(cn->next!='\0')
	{
	cn=cn->next;
	}
	cn->next=b.header;
	a.disp();
}

void pinnacle::reverse(node* temp)                                            //reverse traverse
{
if (temp->next!='\0')
  {
	reverse(temp->next);
	cout<<temp->prn;
	cout<<temp->name;
  }
}


int main()
{
char c;
pinnacle p[2];
for (int i=0;i<2;i++)
{
p[i].ins_presi();
p[i].disp();
}
cout<<"enter y if there are more members and n if there are no  more members";
cin>>c;
while(c=='y')
{
for (int i=0;i<2;i++)
{
p[i].ins();
p[i].disp();
}
cout<<"enter y if there are more members and n if there are no  more members";
cin>>c;
}
if(c=='n')
{
for (int i=0;i<2;i++)
{
p[i].ins_secret();
p[i].disp();
}
}

do
{
cout<<"enter d to delete some member from linked list and any other letter to not to be deleted";
cin>>c;
if(c=='d')
{
for(int i=0;i<2;i++)
{
p[i].remove();
p[i].disp();
}
}
}
while(c=='d');


pinnacle p3;
cout<<"concatenated linked list is :\n";
p3.concatenate(p[0],p[1]);

cout<<"reversed string is \n";
p3.reverse(p[0].header);


return 0;
}











