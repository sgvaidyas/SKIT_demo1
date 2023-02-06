#include<iostream>
using namespace std;
void output(int a[], int n)
{
	cout<<"\n array elements = \n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	
}
int main()
{
	int a[30];	
	int pos,n = 0,flag=1,ele;
	do
	{
		cout<<"\n Enter the ele = ";
		cin>>ele;
		cout<<"\n Enter the pos = ";
		cin>>pos;
		
		if(pos>n || pos<0)
		{
			cout<<"\n Invalid pos \n";
			continue;
		}	
	    else if(pos==n)
			a[pos] = ele;
		else
		{
			//shifting the elements to right
			for(int i=n;i>pos;i--)
				a[i] = a[i-1];
			//insert ele at given pos
			a[pos]= ele;
		}
		//increment n val		
		n++;
		output(a,n);
		cout<<"\n If you want to continue press 1 = ";
		cin>>flag;
	}while(flag);
		
}
