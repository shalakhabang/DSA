#include<iostream>
#include<string>
using namespace std;
class str
{
	private :char a[50],b[50],cpy[50],con[50],rev[50];
	public: void get()
			{

				cout<<"\n enter string one:";
				cin>>a;
				cout<<"\n enter string two:";
				cin>>b;
			}
			void length()
			{
				int count=0;
				for(int i=0;a[i]!='\0';i++)
				{
					count++;
				}
				cout<<"\n length of 1 string is:"<<count;

			}
			void copy()
			{
				int i;
				for(i=0;a[i]!='\0';i++)
				{
					cpy[i]=a[i];
				}
				cpy[i]='\0';
				cout<<"\n copied string:"<<cpy;
			}
			void concat()
			{

				int i,j,k;
				for(i=0;a[i]!='\0';i++)
				{
					con[i]=a[i];
				}
				k=i;
				for (j=0;b[j]!='\0';j++)
				{
					con[k]=b[j];
					k++;
				}
				con[k]='\0';
				cout<<"concatenated string: "<<con;
			}
			void reverse()
			{

				int j,co=0,i;
				for(int i=0;a[i]!='\0';i++)
				{
					co++;
				}
				for(i=0;a[i]!='\0';i++)
				{
					rev[i]=a[i];
				}
				rev[i]='\0';
				i=0;
				j=co-1;
					while(i<=j)
					{
						char temp;
						temp=rev[i];
						rev[i]=rev[j];
						rev[j]=temp;
						i++;j--;
					}
					rev[co]='\0';
					cout<<"\n reverse string is:"<<rev;
			}
			void compa()
			{
				int flag=0,i,j;
				for(i=0,j=0;a[i]!='\0',b[j]!='\0';i++,j++)
				{
					if(a[i]==b[i])
						flag=1;
				}
				if (flag==1)
					cout<<"\n string is same";
				else
					cout<<"\n string id not same";
			}
};
int main()
{
	str s;
	s.get();
	s.length();
	s.copy();
	s.concat();
	s.reverse();
	s.compa();
	return 0;
}

