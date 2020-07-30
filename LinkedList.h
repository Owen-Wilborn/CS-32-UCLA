//LinkedList.h
// LinkedList Header
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Local Libraries
//None
//Standard Libraries
#include <string>

typedef std::string ItemType;		//Declare ItemType variable type
//typedef int ItemType;

struct Node {		//Structure Node to contain each item in the linked list
	ItemType value;
	Node* next;
};

class LinkedList {		//Class LinkedList to create a public interface for using linked list
private:
	Node* head;		//head points to first node in list
	int m_numberItems;		//number of items in the list
public:
	// NAME: LinkedList
	// INPUT: None
	// OUTPUT: None
	// DESCRIPTION: default constructor
	LinkedList();
	// NAME: LinkedList
	// INPUT: Refernce to LinkedList
	// OUTPUT: None
	// DESCRIPTION: copy constructor
	LinkedList(const LinkedList& rhs);
	// NAME: ~LinkedList
	// INPUT: None
	// OUTPUT: None
	// DESCRIPTION: Destroys all the dynamically allocated memory in the list.
	~LinkedList();
	// NAME: operator=
	// INPUT: Refernce to LinkedList
	// OUTPUT: None
	// DESCRIPTION: assignment operator
	const LinkedList& operator=(const LinkedList& rhs);

	//Mutators

	// NAME: insertToFront
	// INPUT: Refernce to item of ItemType
	// OUTPUT: None
	// DESCRIPTION: Inserts val at the front of the list
	void insertToFront(const ItemType& val);
	// NAME: reverseList
	// INPUT: None
	// OUTPUT: None
	// DESCRIPTION: Reverses the LinkedList
	void reverseList();
	// NAME: append
	// INPUT: Refernce to LinkedList
	// OUTPUT: None
	// DESCRIPTION: Appends the values of other onto the end of this LinkedList.
	void append(const LinkedList& other);
	// NAME: swap
	// INPUT: Refernce to LinkedList
	// OUTPUT: None
	// DESCRIPTION: Exchange the contents of this LinkedList with the other one.
	void swap(LinkedList& other);

	//Accessors

	// NAME: get
	// INPUT: Integer for location of item in list, reference to item of ItemType
	// OUTPUT: Bool
	// DESCRIPTION: Sets item to the value at position i in this LinkedList and return true, returns false if there is no element i, list starts numbering at zero
	bool get(int i, ItemType& item) const;
	// NAME: printList
	// INPUT: None
	// OUTPUT: None
	// DESCRIPTION: Prints the LinkedList
	void printList() const;
	// NAME: printReverse
	// INPUT: None
	// OUTPUT: None
	// DESCRIPTION: Prints the LinkedList in reverse order
	void printReverse() const;
	// NAME: size
	// INPUT: None
	// OUTPUT: integer of the size of the list
	// DESCRIPTION: Returns the number of items in the Linked List.
	int size() const;
};
#endif