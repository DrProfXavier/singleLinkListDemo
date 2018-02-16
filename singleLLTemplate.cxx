#include <iostream>
using namespace std;

/*create data Strucure called node, node is now a type of structure
 * in this projet*/
struct node
{
	int data; //data in each node
	node *next; //pointer attatched toeach node
};

class list
{
	private:
	node *head, *tail;
	
	public:
	void createnode(int value);
	void display();
	void insert_start(int value);
	void insert_position(int pos, int value);
	void delete_first();
	void delete_last();
	void delete_position(int pos);
	
	list()//constructor
	{
		head=NULL;//make head and tail point to null, an empty list 
		tail=NULL;
	}
};
/*The creation of a new node at the end of linked list has 2 steps:
*
*    1. Linking the newly created node with tail node. Means passing the address of a new node to the next pointer of a tail node.
*    2. The tail pointer should always point to the last node. So we will make our tail pointer equal to a new node.
*/

void list::createnode(int value)
{
	node *temp = new node; //hold onto your hats
	temp->data=value;//address that temp points to(the new node) will have its "data" attribute from "struct node" set to param value 
	temp->next=NULL;
	/*same goes for the pointer, assign temp's destination address to 
	 * next, the node's pointer, becasue it is the tail, points to null,
	 */ 
	if(head==NULL) //list is empty 
	{
		head = temp;//head node is the new node, call by reference
		tail = temp;//tail node is the new node, call by reference
		temp = NULL;//reset temp for later use
	}
	else //list is not empty
	{
		tail->next=temp;//have existing tail's next attribute point to new node
		tail=temp;//new tail is new node
	}
}

void list::display()
{
	node *temp = new node;
	temp=head;//put a new node in front of head by taking its place
	while(temp!=NULL)//as long as there's a valid pointer to next node
	{
		cout << temp->data <<"\t";
		temp=temp->next;//set temps address to that of next node to be printed 
	}
}
/*
 * Insertion at the Start

	Insertion of a new node is quite simple. It is just a 2-step algorithm which is performed to insert a node at the start of a singly linked list.

    1. New node should be connected to the first node, which means the head. This can be achieved by putting the address of the head in the next field of the new node.
    2. New node should be considered as a head. It can be achieved by declaring head equals to a new node.
*/

void list::insert_start(int value)
{
	node *temp=new node;
	temp->data=value;
	temp->next=head;
	head = temp;
}

void list::insert_position(int pos, int value)//insert between "previous" and "current"
{
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;i++)//until you reach target node to insert behind
    {
      pre=cur;//set previous to where we are(leaving soon)
      cur=cur->next;//set our new curret node to the next node by pointer 
    }
    temp->data=value;//temporary data from parameter
    pre->next=temp;	//our temp node is now pointed to by the previous node 
    temp->next=cur; //our new temp node now points to current, now it is in the middle
}

void list::delete_first()
{
    node *temp=new node;//as always
    temp=head;//pass address of head to temp, for later deletion
    head=head->next;//set new head to the node that was after head
    delete temp;//delete temp, a.k.a old head
}
  
void list::delete_last()
{
  node *current=new node;
    node *previous=new node;
    current=head; //start at head
    while(current->next!=NULL) //until current node points to null, indicating tail...
    {
      previous=current;//move both to next node
      current=current->next;//this one too	
    }
    //once tail is found
    tail=previous;//set tail pointer to previous node
    previous->next=NULL;//set previous/tails next to NULL
    delete current;//delete old tail
}

void list::delete_position(int pos) //delete at a point
{
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;//skip old current, thereby removing it
}


int main()
{
	list obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,60);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	system("pause");
	return 0;
}

