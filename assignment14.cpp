#include<iostream>
using namespace std;
class quicksort
{
private:
	float a[50];
	int n,low,high;
	
public:
	quicksort()
	{
		for(int i=0;i<50;i++)
		{
			a[i]=0;
		}
	}
	
	void get()
	{
		cout<<"\nenter the no. of students";
		cin>>n;
		cout<<" \n enter the percentage of students";
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		low=0;
		high=n-1;
		quick(low,high);
	}
	void quick(int low,int high)
	{
		int m;
		if(low<high)
		{
			m=partition(low,high);
			quick(low,m-1);
			quick(m+1,high);
		}
	}
	
	int partition(int low,int high)
	{
		int pivot,i,j;
		pivot=a[low];
		i=low+1;
		j=high;
		while(i<=j)
		{
			while(a[i]<pivot)
			{
				i++;
			}
			while(a[j]>pivot)
			{
				j--;
			}
			if(i<=j)
			swap(i,j);
			else
			swap_p(j,low);
			
		}
		return j;
		
	}
	void swap(int i,int j)
	{
		int temp;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	
	void swap_p(int j,int low)
	{
		int temp;
		temp=a[j];
		a[j]=a[low];
		a[low]=temp;
	}

	void display()
	{
		for(int i=0;i<n;i++)
		{
			
			cout<<"\t"<<a[i];
		}
	}

	void toppers()
	{
		int i=n-1;
		while(i>=n-5)
		{
			cout<< "\t"<<a[i];
			i--;
		}
	}
};

int main()
{
	cout<<"\n...........QUICK SORT ALGORITHM..........";
	cout<<"\nGET AN ARRAY TO BE SORTED";
	quicksort s;
	s.get();
	cout<<"SORTED ARRAY IS:";
	s.display();
	cout<<"\nTOP 5 RANKERS ARE";
	s.toppers();
	return 0;
}
	


