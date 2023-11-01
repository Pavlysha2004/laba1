#ifndef LIST_H
#define LIST_H
#pragma once
#include"node.h"



template<typename T>
class list
{
public:
	list();
	~list();
	void push_back(T);   // ƒобавление последнего элемента     
	void push_front(T data); // добавление певрого элемента
	void add(T value, int index); // добавление по индексу
	void remove(int index);  //удаление по индексу
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
	
	
	Node<T> *head, *tail;
};



template<typename T>
list<T>::list()
{
	head = tail = nullptr;
}

template<typename T>
list<T>::~list()
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
void list<T>::push_back(T data)
{
	Node<T>* new_object = new Node<T>(data);
	new_object->pPrev = tail;
	if (tail != nullptr)
	{
		tail->pNext = new_object;
	}
	if (head == nullptr)
	{
		head = new_object;
	}
	tail = new_object;

}




template<typename T>
void list<T>::push_front(T data)
{
	Node<T> *new_object = new Node<T>(data);
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
void list<T>::add(T data, int index)
{
	Node<T>* tail_t = get(index);
	if (tail_t == nullptr)
	{
		return push_back(data);
	}
	Node<T>* head_t = tail_t->pPrev;
	if (head_t == nullptr)
	{
		return push_front(data);
	}

	Node<T>* New_object = get(index - 1);
	Node<T>* NewNode = new Node<T>(data, New_object->pNext, New_object);
	New_object->pNext = NewNode;
	

}

template<typename T>
void list<T>::remove(int index)
{
	Node<T>* New_object = get(index);
	if (New_object == nullptr)
	{
		return;
	}
	if (New_object->pPrev == nullptr)
	{
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
	}
	if (New_object->pNext == nullptr)
	{
		if (tail == nullptr)
		{
			return;
		}

		Node<T>* New_object_2 = tail->pPrev;
		if (New_object_2 != nullptr)
		{
			New_object_2->pNext = nullptr;
		}
		else
		{
			head = nullptr;
		}

		delete tail;
		tail = New_object_2;
		return;
	}
	Node<T>* head_t = New_object->pPrev;
	Node<T>* tail_t = New_object->pNext;
	head_t->pNext = tail_t;
	tail_t->pPrev = head_t;

	delete New_object;
}

template<typename T>
int list<T>::size()
{
	int counte = 0;
	Node<T>* current = this->head;
	while (current->pNext != nullptr)
	{
		current = current->pNext;
		counte++;
	}
	counte++;
	return counte;
}




template<typename T>
T& list<T>::operator[](const int index)
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

#endif