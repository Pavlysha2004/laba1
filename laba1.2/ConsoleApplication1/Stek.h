#pragma once
#include"node.h"


template<typename T>
class Stek
{
public:
	Stek();
	~Stek();
	
	void push(T data); // добавление певрого элемента
	void pop();
	int size();
	Node<T>* get(int index)
	{
		int counter = 0;
		Node<T>* current = this->head;
		while (counter != index)
		{
			if (current == nullptr)
			{
				return current;
			}
			current = current->pNext;
			counter++;
		}
		return current;
	}
	T& operator[](const int index);
private:


	Node<T>* head, * tail;
};



template<typename T>
Stek<T>::Stek()
{
	head = tail = nullptr;
}

template<typename T>
Stek<T>::~Stek()
{
	int size_2 = size();
	while (size_2)
	{
		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
		size_2--;
	}
}








template<typename T>
void Stek<T>::push(T data)
{
	Node<T>* new_object = new Node<T>(data);
	new_object->pNext = head;
	if (head != nullptr)
	{
		head->pPrev = new_object;
	}
	if (tail == nullptr)
	{
		tail = new_object;
	}
	head = new_object;

}

template<typename T>
inline void Stek<T>::pop()
{
	Node<T>* New_object = get(0);
	if (New_object == nullptr)
	{
		return;
	}
	if (head == nullptr)
	{
		return;
	}

	Node<T>* New_object_2 = head->pNext;
	if (New_object_2 != nullptr)
	{
		New_object_2->pPrev = nullptr;
	}
	else
	{
		tail = nullptr;
	}

	delete head;
	head = New_object_2;
	return;

	delete New_object;
}





template<typename T>
int Stek<T>::size()
{
	int counte = 0;
	Node<T>* current = head;
	while (current->pNext != nullptr)
	{
		current = current->pNext;
		counte++;
	}
	counte++;
	return counte;
}




template<typename T>
T& Stek<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
