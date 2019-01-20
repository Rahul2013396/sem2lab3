#include<iostream>
using namespace std;

class Node 
{
	public:
	Node *next;
	Node *prev;
	int data;
	Node()
	{
		next=NULL;
		prev=NULL;
	}
};

class doublell
{
	Node *head;
	Node *tail;
	public:
	doublell()
	{
		head=NULL;
		tail=NULL;
	}
	int count();
	void insert(int value);
	void delat(int pos);
	void del();
	void display();
	void insertat(int pos,int value);
};

void doublell::insert(int value)
{
	Node *temp=new Node;
	temp->data=value;
	if (head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->prev=tail;
		tail->next=temp;
	}
	tail=temp;
}

void doublell::insertat(int pos,int value)
{
	if( pos>this->count() )
	cout<<"Linklist doesnot have this many elements"<<endl;
	else
	{
	Node *temp=new Node;
	temp->data=value;
	if (pos==1)
	{
		head->prev=temp;
		temp->next=head;
		temp->prev=NULL;
		head=temp;
	}
	else
	{	
		int i=1;
		Node *wow=head;
		while(i<pos-1)
		{
			wow=wow->next;i++;
		}
		temp->prev=wow;
		temp->next=wow->next;
		wow->next=temp;
		if(temp->next!=NULL)
		temp->next->prev=temp;
	}
	}
}
void doublell::del()
{
	Node *current=head;
	while(current->next!=tail)
	{
		current=current->next;
	}
	tail=current;
	current=current->next;
	tail->next=NULL;
	current->prev=NULL;
	delete current;
}

void doublell::delat(int pos)
{
	if( pos>this->count() )
	cout<<"Linklist Does not have that many elements"<<endl;
	else
	{
		Node *foo=head;int i=1;
		while(i<pos)
		{
			foo=foo->next;i++;
		}
		
		if (foo!=head)
		{
			foo->prev->next=foo->next;
		}
		
		if (foo!=tail)
		{
			foo->next->prev=foo->prev;
		}
		
		foo->next=NULL;
		foo->prev=NULL;
		delete foo;
		
	}
	
	
}

int doublell::count()
{
	Node *foo=head;int i=0;
	while(foo!=NULL)
	{
		i+=1;
		foo=foo->next;
	}
	return i;
}

void doublell::display()
{
	Node *foo=head;
	while(foo!=NULL)
	{
		cout<<foo->data<<"->";
		foo=foo->next;
	}
	cout<<"NULL"<<endl;
}

int main()
{
	doublell dl;
	dl.insert(1);
	dl.insert(2);
	dl.insert(3);
	dl.insert(4);
	dl.insert(5);
	dl.display();
	dl.display();
	dl.insertat(3,7);
	dl.display();
	dl.del();
	dl.delat(3);
	dl.display();	
	dl.insertat(9,9);	
	return 0;
}

