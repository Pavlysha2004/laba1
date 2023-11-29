#pragma once
#include <iostream>
#include <string>
#include "Stek.h"
using namespace std;

template<typename T>
class NodeThree {
public:
	NodeThree* left;
	NodeThree* right;

	T data;
	NodeThree(T value, NodeThree* pLeft = nullptr, NodeThree* pRight = nullptr)
	{
		this->data = value;
		this->left = pLeft;
		this->right = pRight;
	}
};

template<typename T>
class BinaryThree {
public: 
	NodeThree<T>* root;
	BinaryThree(){root = nullptr;}
	void get(bool, T, NodeThree<T>*);

	void size(NodeThree<T>* root_three, int& razmer)
	{
		if (root_three != nullptr)
		{
			razmer++;
			size(root_three->left, razmer);
			size(root_three->right, razmer);
		}
	}
	void preOrderTrav_out_consol(NodeThree<T>* root_three)
	{
		if (root_three != nullptr)
		{
			cout << root_three->data << " ";
			preOrderTrav_out_consol(root_three->left);
			preOrderTrav_out_consol(root_three->right);
		}
	}
	void preOrderTrav_in_stek(NodeThree<T>* root_three, T* mass_for_per_in_AVL, int& i)
	{
		if (root_three != nullptr)
		{
			mass_for_per_in_AVL[i] = root_three->data;
			i++;
			preOrderTrav_in_stek(root_three->left, mass_for_per_in_AVL, i);
			preOrderTrav_in_stek(root_three->right, mass_for_per_in_AVL, i);
		}
	}
	void parsing(string);
};


template<typename T>
void BinaryThree<T>::parsing(string bracket_entry)
{
	bool first_bracket = 1;
	int bracket_counter = 0;
    for (int i = 0; i < bracket_entry.size(); i++)
    {
		if (bracket_entry[i] == '(')
		{
			first_bracket = 0;
			bracket_counter++;
		}
		else if (bracket_entry[i] == ')' && first_bracket == 0)
		{
			bracket_counter--;
		}
		else if (bracket_entry[i] == ')' && first_bracket == 1)
		{
			cout << "выражение не может начинаться с закрывающей скобки";
			return;
		}
		if (bracket_counter < 0)
		{
			cout << "Не верное выражение";
			return;
		}
		if (bracket_entry[i] < '(' && bracket_entry[i] > 'z')
		{
			cout << "Не верное выражение";
			return;
		}
    } 
	if (bracket_counter != 0)
	{
		cout << "Не верное выражение";
		return;
	}                                           //скобки проверены 
	
	if (bracket_entry.empty()) 
	{
		return;
	}

	Stek<NodeThree<T>*> st;
	int index = 0;
	T num = 0;
	while (index < bracket_entry.size())
	{
		if (bracket_entry[index] == '(')
		{
			index++; 
			while (bracket_entry[index] == ' ') { index++; }
			while (bracket_entry[index] >= '0' && bracket_entry[index] <= 'z')
			{
				if (isdigit(bracket_entry[index]))
				{
					num = num * 10 + (bracket_entry[index] - '0');
				}
				else if (bracket_entry[index] >= 'A' && bracket_entry[index] <= 'z')
				{
					num = bracket_entry[index];
				}
				index++;
			}
			index--;
			NodeThree<T>* node = new NodeThree<T>(num);
			if (st.size() != 0) 
			{
				NodeThree<T>* parent = st.rec();
				if (!parent->left) 
				{
					parent->left = node;
				}
				else 
				{
					parent->right = node;
				}
			}
			st.push(node);
			num = 0;
		}
		else if (bracket_entry[index] == ')')
		{
			if (st.size() > 1) { st.pop(); }
		}
		index++;
	}
	root = st.rec();
}


template<typename T>
void BinaryThree<T>::get(bool left_sun, T value, NodeThree<T>* point_get)
{
	if (left_sun)
	{
		point_get->left = new NodeThree<T>(value);
	}
	else
	{
		point_get->right = new NodeThree<T>(value);
	}
}
