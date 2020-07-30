//LinkedList.cpp
//LinkedList Implementation

//Prototype Library
#include "LinkedList.h"
//Standard Libraries
#include <iostream>
//#include <string>
using namespace std;

// default constructor
LinkedList::LinkedList()
{
	//Create an empty list
	head = nullptr;
	m_numberItems = 0;
}

// copy constructor
LinkedList::LinkedList(const LinkedList& rhs)
{
	//Create an empty list
	head = nullptr;
	m_numberItems = 0;
	//Copy the rhs list to the new list
	ItemType item;
	//Copy from last item to the first because add the items from the front
	for (int i = (rhs.m_numberItems-1); i >=0; i--)
	{
		//Get the item from old list
		rhs.get(i, item);
		//Insert item into new list
		insertToFront(item);
	}
}
// Destroys all the dynamically allocated memory
// in the list.
LinkedList::~LinkedList()
{
	Node* Ptr = head;
	Node* nextPtr = nullptr;
	//While items exist in list
	while (m_numberItems > 0)
	{
		//Find the next nude
		nextPtr = Ptr->next;
		//Delete this node
		delete Ptr;
		//lower item count
		m_numberItems--;
		//go to the next node
		Ptr = nextPtr;
	}
	//Set to empty list status
	head = nullptr;
	m_numberItems = 0;
}
// assignment operator
const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
	//Check if assigning something to itself
	if (this == &rhs)
	{
		//Return self for self assignment
		return *this;
	}
	//destory the list to be copied over
	this->~LinkedList();
	ItemType item;
	//Add items from old list into new list in reverse
	for (int i = (rhs.m_numberItems-1); i >= 0; i--)
	{
		//get item from old list
		rhs.get(i, item);
		//add item to the new list
		insertToFront(item);
	}
	//Return new list
	return *this;
}
// Inserts val at the front of the list
void LinkedList::insertToFront(const ItemType& val)
{
	//Create new node
	Node* newNode = new Node;
	//Set item the node
	newNode->value = val;
	//Set the old header to second in list
	newNode->next = head;
	//Set head to new node at front
	head = newNode;
	//increase item count
	m_numberItems++;
	return;
}
// Prints the LinkedList
void LinkedList::printList() const
{
	Node* Entry = head;
	//Iterate from first item to last
	for (int i = 0; i < m_numberItems; i++)
	{
		//Write out the item and a space
		cout << Entry->value << " ";
		//Got to the next item
		Entry = Entry->next;
	}
	//Finish the line jump to new one
	cout << endl;
	return;
}
// Sets item to the value at position i in this
// LinkedList and return true, returns false if
// there is no element i
bool LinkedList::get(int i, ItemType& item) const
{
	//Check if number asking for in the list
	if (i<0 || i>(m_numberItems-1))
	{
		//If not valid number return false
		return false;
	}
	Node* Ptr = head;
	//Iterate though the list until find the num node
	for (int k = 0; k<i; k++)
	{
		//Iterate through node pointers
		Ptr = Ptr->next;
	}
	//Get thats node's value
	item = Ptr->value;
	//return true found the node in looking
	return true;
}
// Reverses the LinkedList
void LinkedList::reverseList()
{
	//Create new empty list of reverse
	LinkedList reverse;
	ItemType item;
	bool test;
	//Iterate through list input to collect all nodes
	for (int i=0; i<m_numberItems; i++)
	{
		//If item was in the old list get it
		test = get(i,item);
		if (test == true)
		{
			//Place in the front of the return list
			reverse.insertToFront(item);
		}
	}
	//Copy over the reversed list into the input list
	*this = reverse;
	//Delete the reverse list
	reverse.~LinkedList();
	return;
}
// Prints the LinkedList in reverse order
void LinkedList::printReverse() const
{
	//Create hold list identical to list input
	LinkedList holder;
	holder = *this;
	//Reverse the holder list and print it
	holder.reverseList();
	holder.printList();
	//Destroy the holder list
	holder.~LinkedList();
	return;
}
// Appends the values of other onto the end of this
// LinkedList.
void LinkedList::append(const LinkedList& other)
{
	Node* preNode = head;
	ItemType item;
	//For each node in the list to append to the other list
	for (int i=0; i<other.m_numberItems; i++)
	{
		//Check if list is empty first
		if (preNode == nullptr)
		{
			//Create new node at the end
			Node* newNode = new Node;
			//get and input the correct values into the new node
			other.get(i, item);
			newNode->value = item;
			//Link the new node at the end
			head = newNode;
			newNode->next = nullptr;
			preNode = head;
			//Increse the item count
			m_numberItems++;
			continue;
		}
		//Find end of list want to append to
		while(preNode->next!=nullptr)
		{
			preNode = preNode->next;
		}
		//Create new node at the end
		Node* newNode = new Node;
		//get and input the correct values into the new node
		other.get(i, item);
		newNode->value = item;
		//Link the new node at the end
		preNode->next = newNode;
		newNode->next = nullptr;
		//Increse the item count
		m_numberItems++;
	}
	return;
}
// Exchange the contents of this LinkedList with the other
// one.
void LinkedList::swap(LinkedList& other)
{
	//create new empty list
	LinkedList temp;
	//assign other to temp
	temp = other;
	//overwrite other with the list
	other = *this;
	//overwrite the list with the temp
	*this = temp;
	//destory the temp list
	temp.~LinkedList();
	return;
}
// Returns the number of items in the Linked List.
int LinkedList::size() const
{
	//return the number of items in the list
	return m_numberItems;
}