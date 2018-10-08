#pragma once
#include <string>
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct Node
{
	shared_ptr<Node<T>> next;
	shared_ptr<T> value;

	Node(T item)
	{
		value = make_shared<T>(item);
		next = nullptr;
	}
};

template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void add(T value);
	void print();
	bool remove(T value);

	bool isCircle();

	void makeCircle();

private:
	shared_ptr<Node<T>> head;
};

template<typename T>
LinkedList<T>::LinkedList() { head = nullptr; }

template<typename T>
LinkedList<T>::~LinkedList() {}

template<typename T>
void LinkedList<T>::add(T value) {
	if (head == nullptr)
	{
		head = make_shared<Node<T>>(value);
	}
	else
	{
		shared_ptr<Node<T>> temp = head;

		while (temp->next)
		{
			temp = temp->next;
		}

		temp->next = make_shared<Node<T>>(value);
	}
}

template<typename T>
void LinkedList<T>::print()
{
	if (isCircle())
	{
		cout << "Circular List" << endl;
		return;
	}
	

	cout << endl << endl;

	shared_ptr<Node<T>> temp = head;

	while (temp)
	{
		cout << "\t" << (char)*(temp->value);
		temp = temp->next;
	}

	cout << endl << endl;
}

template<typename T>
bool LinkedList<T>::remove(T value)
{
	if (!head)
		return false;

	shared_ptr<Node<T>> temp = head->next;

	while (temp)
	{
		if (temp->value == value)
			return true;

		temp = temp->next;
	}

	return false;
}

template<typename T>
bool LinkedList<T>::isCircle()
{
	if (!head || !head->next)
	{
		return false;
	}

	shared_ptr<Node<T>> slow = head;
	shared_ptr<Node<T>> fast = head->next;

	while (slow && fast && fast->next)
	{
		if (fast == slow)
		{
			return true;
		}

		fast = fast->next;

		if (fast == slow)
		{
			return true;
		}

		fast = fast->next;
		slow = slow->next;
	}
	return false;
}

template<typename T>
void LinkedList<T>::makeCircle()
{
	if (isCircle()) return;

	if (!head) return;

	shared_ptr<Node<T>> temp = head;

	while (temp->next) {
		temp = temp->next;
	}

	temp->next = head;
}