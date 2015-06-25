//  The MIT License(MIT)
//
//  Copyright(c) 2015 Jamie Johnson
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files(the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions :
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.

#ifndef Linked_List_H
#define Linked_List_H

#include "ListNode.h"

template <class T>
class LinkedList
{
private:
	// Declare structure for list nodes
	ListNode<T>	data;
	ListNode<T>*	front;					// Pointer to the head sentinel node
	ListNode<T>*	rear;					// Pointer to the rear sentinel node
	ListNode<T>*	curr;					// Pointer to the current node
	int			count;					// Count of total active nodes in the list

public:

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
// Constructor                                     
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
LinkedList()
{
	front = new ListNode<T>;	// SENTINEL
	rear = new ListNode<T>;		// SENTINEL

	front->setNext(rear);
	front->setPrev(NULL);

	rear->setNext(NULL);
	rear->setPrev(front);

	count = 0;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
// Shows the number of Nodes in the list       
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
int getCount() const{
	return count;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
// Inserts a node into the first available position of the list.       
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
void insertNode(T* Card){
	ListNode<T> *newNode;             // A new node
	ListNode<T> *walker;              // To traverse the list

	// Allocate a new node and store the string.
	newNode = new ListNode<T>;
	newNode->setData(Card);
	
	// Position walker at the head of list.
	walker = front;

	// Proceed 
	while(walker->getNext() != rear){
		walker = walker->getNext();
	}
	// Insert node into the list after the walker's position.
	newNode->setNext(walker->getNext());
	newNode->setPrev(walker);
	walker->getNext()->setPrev(newNode);
	walker->setNext(newNode);
	count++;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
// The insertNodeFromRear function inserts a node into the designated      
// lineCount position, but does it from the end of the list.       
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
void insertNodeFromRear(T* Card){
	ListNode<T> *newNode;             // A new node
	ListNode<T> *walker;             // To traverse the list

	// Allocate a new node and stores the string.
	newNode = new ListNode<T>;
	newNode->setData(Card);

	// Position walker at the rear of list.
	walker = rear;

	// Skip all nodes up to the linePos.
	for (int i = count; i >= linePos; i--)
		walker = walker->getPrev();
	
	// Insert node into the list after the walker's position.
	newNode->setNext(walker);
	newNode->setPrev(walker->getPrev());
	walker->getPrev()->setNext(newNode);
	walker->setPrev(newNode);

	count++;
}


// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
//  Shows the value stored in each node of the linked list in 
//  front to rear order.                             
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
void displayListForward() const{
	ListNode<T> *walker;  // To move through the list
	int lineCount = 1;

	if (count == 0)
	{
		cout << "\nNo Planets in List\n";
		return;
	}

	// Position walker after the front sentinel.
	walker = front->getNext();

	// While walker doesn't point to rear, traverse the list.
	while (walker != rear)
	{
		// Display line count of this node.
		std::cout << lineCount << "\n";
		// Display the value in this node.
		walker->getData()->printCard();
		// Move to the next node.
		walker = walker->getNext();
		lineCount++;
	}
	cout << endl;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
//  Shows the value stored in each node of the linked list in 
//  front to rear order.                             
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
bool findColonyResources(int dieRoll, T* rtdAtry[], int& lineCount){
	ListNode<T> *walker;  // To move through the list
	lineCount = 0;
	bool flag = false;

	// Position walker after the front sentinel.
	walker = front->getNext();

	// While walker doesn't point to rear, traverse the list.
	while (walker != rear)
	{
		if (walker->getData()->getActNum() == dieRoll)
		{ 
			// Display line count of this node.
			cout << lineCount + 1 << "\n";
			// Display the value in this node.
			walker->getData()->printCard();
			rtdAtry[lineCount] = walker->getData();
			flag = true;
		}
		// Move to the next node.
		walker = walker->getNext();
		lineCount++;
	}
	cout << endl;
	return flag;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
//  Shows the value stored in each node of the linked list in 
//  front to rear order.                             
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
bool getTradeResources(T* rtdAtry[], int& lineCount)
{
	ListNode<T> *walker;  // To move through the list
	lineCount = 0;
	bool flag = false;

	// Position walker after the front sentinel.
	walker = front->getNext();

	// While walker doesn't point to rear, traverse the list.
	while (walker != rear)
	{
		// Display the value in this node.
		rtdAtry[lineCount] = walker->getData();
		// Move to the next node.
		walker = walker->getNext();
		lineCount++;
		flag = true;
	}
	cout << endl;
	return flag;
}

/*
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
//	Traverses the list and deletes the nodes in the positions 
//	that are passed to it.
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
void deleteNode(int begin, int end){
	ListNode *walker;       // To traverse the list
	ListNode *deleteFrom;	// Pointer to begin deleting
	ListNode *deleteTo;		// Point to stop deleting

	// Position walker after the first sentinel.
	walker = front->next;

	//Traverse the list until the walker gets to the beginning node to be deleted.
	for (int i = 1; i < begin; i++)
		walker = walker->next;

	// If begin and end are the same... delete the single node.
	if (begin == end){
		walker->prev->next = walker->next;
		walker->next->prev = walker->prev;
		delete walker;
		count--;
	}
	// If multiple nodes need to be deleted
	else{
		// Sets DeleteFrom's position to the requested line 
		deleteFrom = walker->prev;

		// Traverse list to end of deletion selection
		for (int i = begin; i < end; i++)
			walker = walker->next;

		// Set's DeleteTo's position to the requested line
		deleteTo = walker->next;

		// Delete the Nodes between the two pointers
		walker = deleteFrom->next;
		while (walker != deleteTo){
			walker = walker->next;
			delete walker->prev;
			count--;
		}
		//Reset the links
		deleteFrom->next = deleteTo;
		deleteTo->prev = deleteFrom;
	}
}


// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
// Destructor                                      
// This function deletes every node in the list.   
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯)
StringList::~StringList()
{
	ListNode *walker;   // To traverse the list

	// Position walker after the front sentinel.
	walker = front->next;

	// While walker is not at the end of the list...
	while (walker != rear)
	{
		// Save a pointer to the next node.
		walker = walker->next;

		// Delete the previous node.
		delete walker->prev;
	}
}
*/
};

#endif

