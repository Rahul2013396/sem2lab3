#include <iostream>
using namespace std;
class Node
{
	public:
    	int data;
    	// Pointer for next Node
    	Node *next;
    	// Constructor which points pointer to null
    	Node(int value)
    	{
        	next = NULL;
        	data = value;
    	}
};

class cll
{
  	public:
    	Node *head;
    	cll()
    	{
        	head = NULL;
    	}
    	// insert at the end of ll.
    	void insert(int value)
    	{
	// a new node is created
        Node *temp = new Node(value);
        // loop to check if the list is empty
        if (head == NULL)
        {
            head = temp;
        }
        else
        { // if the list is not empty.
            Node *current = head;
            while (current->next != head)
            current = current->next;
            current->next = temp;
        }
        temp->next = head;
	}
    // function for display of ll
    void display()
    	{
        	Node *current = head;
        	if (current == NULL)
       		 {
        	cout << "No elements " << endl;
         	return;
       		 }
        	while (current->next != head)
       		 { 
		// break at head
          	cout << current->data << "->";
            	current = current->next;
       		 }
        // Printing the last element
        cout << current->data;
        cout << endl;
    	}
    void InsertAt(int value, int pos)
    	{
        	// Creating a new node
        	Node *temp = new Node(value);
        	// check if the list is empty
        	if (head == NULL)
        	{
        	    head = temp;
            	    temp->next = head;
        	}
        	else
        	{ 
			// if the list in not empty
            		Node *current = head;
            		int i = 1;
            		while (i < pos-1)
            	{
                	current = current->next;
                	i++;
           	 }
           	 temp->next = current->next;
           	 current->next = temp;
        }
    }
    void DeleteAt(int pos)
    {
    	if (pos < CountItems())
        {
            Node *current = head;
            int i = 1;
            while (i < pos-1)
            {
                current = current->next;
                i++;
            }
            current->next = current->next->next;
        }
        else
        {
            cout << "element limit is exceeded";
        }
    }
    void Delet()
    {
        Node *current = head;
        while (current->next->next != head)
        {
            current = current->next;
        }
        current->next = head;
    }
    int CountItems()
    {
        int i = 1;
        Node *current = head->next;
        while (current != head)
        {
            current = current->next;
            i++;
        }
        return i;
    }
};

int main()
{
    cll cll1;
    for (int i = 1; i < 11; i++)
    {
        cll1.insert(i);
    }
    cll1.insert(11);
    cll1.InsertAt(3,8);
    cll1.display();
    cll1.display();
    cll1.DeleteAt(4);	
    cll1.Delet();
    cll1.display();
    cll1.display();

}
