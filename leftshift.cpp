#include<iostream>
using namespace std;
void leftshift(int a[], int n);
void output(int a[], int n);
int main()
{
	int a[] = {11,22,33,44};
	output(a,4);	
	leftshift(a,4);
	output(a,4);	
}
void leftshift(int a[], int n)
{
	int temp;
	temp = a[0];
	for(int i=0;i<n-1;i++)
		a[i]=a[i+1];
	a[n-1] = temp;
}
void output(int a[], int n)
{
	cout<<"\n array elements = \n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	
}
