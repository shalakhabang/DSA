#include<iostream>
using namespace std;
#define size 10
class bal_exp
{
	struct stack
	{
		int top;
		char s[size];
	}st;
private:
	char exp[10];
public:
	bal_exp()
	{
		st.top=-1;


	}
	void push(char x)
	{
		st.top++;
		st.s[st.top]=x;
	}
	int pop()
	{
		char a;
		a=st.s[st.top];
		st.top--;
		return a;
	}
	int isfull()
	{
		if(st.top>=size)
		return 1;
		else
		return 0;
	}
	int isempty()
	{
		if(st.top==-1)
		return 1;
		else
		return 0;
	}
	void check()
	{
		int i,length;
		cout<<"enter the length of exp";
		cin>>length;
		cout<<"enter the expression";
		for( i=0;i<length;i++)
		{
			cin>>exp[i];
		}
		for( i=0;i<length;i++)
		{
			if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
			{
			push(exp[i]);
			continue;
			}
			else if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
			{
				if(isempty()||match(exp[i]))
				{
					cout<<"not balanced";
					return;
				}
				else
				pop();
			 }
		}


		if(isempty())
		cout<<"expression is well balanced";
		else
		cout<<"expression is not blanced";

	}

	int match(char str)
	{
		char item;
		switch(str)
		{
		 case ')':
			    item = st.s[st.top];
			    if (item=='{' || item=='[')
			    return 1;
			    else return 0;
			    break;

		case '}':
			    item = st.s[st.top];
			    if (item=='(' || item=='[')
			    return 1;
			    else return 0;
			    break;

		case ']':
			    item = st.s[st.top];
			    if (item =='(' || item == '{')
			    return 1;
			    else return 0;
		   	    break;
        }
    }

};

int main()
{
bal_exp b;
b.check();
return 0;
}







