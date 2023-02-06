#include<iostream>
using namespace std;
void insertBegin(int);
void insertEnd(int);
void insertPos(int,int);
void deleteBegin();
void deleteEnd();
void deletePos(int);
void display();
struct Node
{
	int data ;
	struct Node *next,*prev;
};

Node *head;
int cnt;

int main()
{
	head = NULL;
	cnt = 0;
	int flag = 1,ch,pos,ele;
	while(flag)
	{
		cout<<"\n 1 Insert Begin";
		cout<<"\n 2 Insert End";
		cout<<"\n 3 Insert Pos";
		cout<<"\n 4 Delete Begin";
		cout<<"\n 5 Delete End";
		cout<<"\n 6 Delete Pos";
		cout<<"\n 7 Display";		
		cout<<"\n 8 Exit";		
		cout<<"\n Enter the choice = ";
		cin>>ch;
		if(ch >=1 && ch<=3)
		{
			cout<<"\n Enter the ele = ";
			cin>>ele;
		}
		switch(ch)
		{
			case 1:insertBegin(ele);break;
			case 2:insertEnd(ele);break;
			case 3:cout<<"\n Enter the pos = ";
				   cin>>pos;
				   if(pos>=1 && pos<=cnt+1)
				   		insertPos(pos,ele);
				   else
				   		cout<<"\n Invalid pos\n";
				   	break;
			case 4:deleteBegin();break;
			case 5:deleteEnd();break;
			case 6:cout<<"\n Enter the pos = ";
				   cin>>pos;
				   if(pos>=1 && pos<=cnt)
				   		deletePos(pos);
				   else
				   		cout<<"\n Invalid pos\n";
			case 7:display();break;
			case 8:cout<<"\n Exiting prog";
			       flag=0;
			       break;
			default:cout<<"\n Bro get ur eyes checked!\n";
		}			
	}
}



void insertBegin(int ele)
{
	Node *temp = new Node();
	temp->data = ele;
	temp->next = NULL;
	temp->prev = NULL;
	if(head== NULL)
		head = temp;
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;		
	}
	cnt++;
}
void insertEnd(int ele)
{
	Node *temp = new Node();
	temp->data = ele;
	temp->prev = NULL;
	temp->next = NULL;
	
	if(head == NULL)
		head = temp;
	else
	{
		Node *ptr;
		for(ptr = head; ptr->next!=NULL;ptr=ptr->next);
		ptr->next = temp;
		temp->prev = ptr;
	}
	cnt++;
}
void insertPos(int pos,int ele)
{
	if(pos == 1)
		insertBegin(ele);
	else if(pos == cnt+1)
		insertEnd(ele);
	else
	{
		Node *temp = new Node();
		temp->data = ele;
		temp->prev = NULL;
		temp->next = NULL;
		Node *pp,*cp;
		pp = head;
		cp = head;
		for(int i=1;i<pos;i++)
		{
			pp= cp;
			cp= cp->next;
		}
		pp->next = temp;
		temp->prev = pp;
		temp->next = cp;
		cp->prev = temp;
		cnt++;
	}
}
void deleteBegin()
{
	if(head==NULL)
		cout<<"\n List empty\n";
	else
	{
		Node *ptr;
		ptr = head;
		head = head->next;
		if(head!=NULL)
			head->prev=NULL;
		cout<<"\n Del..... = "<<ptr->data<<endl;
		delete ptr;
		cnt--;
	}
}
void deleteEnd()
{
	if(head==NULL)
		cout<<"\n LIST EMPTY \n";
	else
	{
		Node *ptr,*pp;
		for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
		if(ptr == head)
		{
			head = NULL;
		}
		else
		{
			pp = ptr->prev;
			pp->next = NULL;
		}		
		cout<<"Deleting node = "<<ptr->data<<endl;
		delete ptr;
		cnt--;
	}	
}

void deletePos(int pos)
{
	if(pos==1)
		deleteBegin();
	else if(pos==cnt)
		deleteEnd();
	else
	{
		Node *cp,*pp;
		cp = head;
		for(int i=1;i<pos;cp=cp->next,i++);
		pp = cp->prev;
		pp->next = cp->next;
		cp->next->prev = pp;
		cout<<"\n DEL.... = "<<cp->data<<endl;
		delete cp;
		cnt--;
	}
}
void display()
{
	if(head == NULL)
		cout<<"\n List empty\n";
	else
	{
		cout<<"\n List ele\n";
		Node *ptr ;
		ptr = head;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<endl;
			ptr = ptr->next;
		}		
	}
}
