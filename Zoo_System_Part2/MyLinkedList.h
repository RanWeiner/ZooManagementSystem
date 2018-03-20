#ifndef __MY_LINKED_LIST_H
#define __MY_LINKED_LIST_H

//	requirements
//	1. the linked list must contain pointers, and the all the elements must implement operator<< 
//	2. each element must have id value (integer)

#include <iostream>
using namespace std;

template <class T>
class Node;


template<class T>
class MyLinkedList {

private:
	Node<T>* first;
	Node<T>* last;
	int size;


public:
	MyLinkedList() : first(nullptr), last(nullptr), size(0) {}
	MyLinkedList(const MyLinkedList& other) = delete;
	~MyLinkedList();


	void insertLast(T data);
	T removeItem(int index) throw (const string&);
	void print() const;
	int getSize() const;

};


template<class T>
class Node
{
	friend class MyLinkedList<T>;

private:
	T data;
	Node<T>* next;
	
public:
	Node<T>(const T& data) : data(data), next(nullptr) {}
	
};


template<class T>
MyLinkedList<T>::~MyLinkedList()
{
	Node<T>* current = this->first;
	Node<T>* temp = nullptr;

	while (current)
	{
		temp = current->next;
		delete current;
		current = temp;
	}
}

template<class T>
void MyLinkedList<T>::insertLast(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (last == nullptr)
	{
		newNode->next = nullptr;
		last = newNode;
		first = newNode;
		size++;
		return;
	}
	last->next = newNode;
	last = last->next;
	size++;
}

template<class T>
int MyLinkedList<T>::getSize() const
{
	return size;
}

template<class T>
void MyLinkedList<T>::print() const
{
	Node<T>* current = first;

	while (current)
	{
		cout << "\n" << *(current->data)  << endl;
		current = current->next;
	}

}


template<class T>
T MyLinkedList<T>::removeItem(int id) throw (const string&)
{
	T data;
	Node<T>* current = first->next;
	Node<T>* previous = first;

	while (current != nullptr && (current->data)->getId()!= id)
	{
		previous = current;
		current = current->next;
	}
	if (current != nullptr)
	{
		data = current->data;
		previous->next = current->next;
		size--;
		free(current);
		return data;
	}

	throw string("id not found");
}


#endif //MY_LINKED_LIST_H


