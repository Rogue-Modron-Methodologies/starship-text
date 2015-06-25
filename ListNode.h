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

#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode
{
private:
	T*			data;				// Data to be stored in the list
	ListNode<T>*	next;				// Pointer to the next node
	ListNode<T>*	prev;				// Point to the previous node

public:
	ListNode() 
	{
		next = 0;
		prev = 0;
	}
	~ListNode() {}
	// Getters and Setters
	void setNext(ListNode<T>* next)
	{  this->next = next;  }
	void setPrev(ListNode<T>* prev)
	{  this->prev = prev;  }
	void setData(T* nData)
	{ this->data = nData;	}
	ListNode<T>* getNext() const
	{  return next;  }
	ListNode<T>* getPrev() const
	{  return prev;  }
	T* getData() const
	{	return data;	}

};
#endif // LISTNODE_H
