#pragma once
#include "BinaryTreeNode.h"
using namespace std;

template<typename T>
class AVLNode
{
public:
	AVLNode* left;
	AVLNode* right;
	int height;
	T data;
    AVLNode(T value, AVLNode* pLeft = nullptr, AVLNode* pRight = nullptr)
	{
		this->data = value;
		this->left = pLeft;
		this->right = pRight;
        this->height = 0;
	}
};

template <typename T>
class AVLthree
{
public:
	AVLNode<T>* root;
	AVLthree() { root = nullptr; }
    AVLthree(BinaryThree<T>);

    // Прямой обход
    void preOrder(AVLNode<T>*);
    // центрированный обход
    void inOrder(AVLNode<T>*);
    // Обратный обход
    void postOrder(AVLNode<T>*);
    // Обход в ширину
    void printLevelOrder(AVLNode<T>*);

    //добавление элемента
	AVLNode<T>* insert(AVLNode<T>*, T);
    //удаление
    AVLNode<T>* delete_node(AVLNode<T>*, T);
    //поиск
    AVLNode<T>* search(AVLNode<T>*, int);




private:

    void printGivenLevel(AVLNode<T>* root, int level)
    {
        if (root == nullptr) return;
        if (level == 1)
            cout << root->data << " ";
        else if (level > 1) 
        {
            printGivenLevel(root->left, level - 1);
            printGivenLevel(root->right, level - 1);
        }
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int height(AVLNode<T>* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }
        return node->height;
    }

    int getBalance(AVLNode<T>* node)
    {
        if (node == nullptr) 
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    AVLNode<T>* rotateRight(AVLNode<T>* y) 
    {
        AVLNode<T>* x = y->left;
        AVLNode<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    AVLNode<T>* rotateLeft(AVLNode<T>* x)
    {
        AVLNode<T>* y = x->right;
        AVLNode<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    AVLNode<T>* balance_mod(AVLNode<T>* node, T key)
    {
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data) 
        {
            return rotateRight(node);
        }

        if (balance < -1 && key > node->right->data) 
        {
            return rotateLeft(node);
        }

        if (balance > 1 && key > node->left->data) 
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->data) 
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

};

template<typename T>
AVLthree<T>::AVLthree(BinaryThree<T> three)
{
    root = nullptr;
    int size_mass = 0;
    three.size(three.root, size_mass);
    T* mass = new T[size_mass];
    int p = 0;
    three.preOrderTrav_in_stek(three.root, mass, p);
    for (int i = 0; i < size_mass; i++)
    {
        root = insert(root, mass[i]);
    }

}

template<typename T>
void AVLthree<T>::preOrder(AVLNode<T>* node)
{
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template<typename T>
void AVLthree<T>::inOrder(AVLNode<T>* node)
{
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

template<typename T>
void AVLthree<T>::postOrder(AVLNode<T>* node)
{
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

template<typename T>
void AVLthree<T>::printLevelOrder(AVLNode<T>* node)
{
    int h = height(node);
    for (int i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

template<typename T>
AVLNode<T>* AVLthree<T>::insert(AVLNode<T>* node, T key)
{
    if (node == nullptr) 
    {
        AVLNode<T>* new_node = new AVLNode<T>(key);
        new_node->height = 1;
        return new_node;
    }

    if (key < node->data) node->left = insert(node->left, key); 
    else if (key > node->data) node->right = insert(node->right, key); 
    else return node; 

    node->height = 1 + max(height(node->left), height(node->right));

    return balance_mod(node, key);
}

template<typename T>
inline AVLNode<T>* AVLthree<T>::delete_node(AVLNode<T>* root_del, T key)
{
    if (root_del == nullptr) return root_del;
    //рекурсивно идём к нужному нам элементу
    else if (key < root_del->data) root_del->left = delete_node(root_del->left, key);
    else if (key > root_del->data) root_del->right = delete_node(root_del->right, key);
    // кода мы нашли нужный элемент, удаляем его согласно правилам удаления
    else
    {
        if (root_del->left == nullptr) 
        {
            AVLNode<T>* temp = root_del->right;
            delete root_del;
            return temp;
        }
        else if (root->right == nullptr) 
        {
            AVLNode<T>* temp = root_del->left;
            delete root_del;
            return temp;
        }

        AVLNode<T>* temp = root_del->right;
        while (temp->left != nullptr) 
        {
            temp = temp->left;
        }
        root_del->data = temp->data;
        root_del->right = delete_node(root_del->right, temp->data);
    }
    if (root_del == nullptr) return root_del;

    root_del->height = 1 + max(height(root_del->left), height(root_del->right));

    return balance_mod(root_del, key);
}

template<typename T>
AVLNode<T>* AVLthree<T>::search(AVLNode<T>* root, int key)
{
    if (root == nullptr || root->data == key) return root;
    if (root->data < key) return search(root->right, key);
    return search(root->left, key);
}

