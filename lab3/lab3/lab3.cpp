#include <iostream>
#include "BinaryTreeNode.h"
#include "AVLThree.h"
#include <fstream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	BinaryThree<int> Three_lol;
	string str;

    string filename = "Для скобочной записи.txt"; 
    ifstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return 1;
    }
    string line;
    while (std::getline(file, line)) str += line;
    file.close(); 

	Three_lol.parsing(str);
    if (Three_lol.root == nullptr)
    {
        return 0;
    }
    cout << "Прямой обход полученного бинарного дерева: ";
    Three_lol.preOrderTrav_out_consol(Three_lol.root);
    AVLthree<int> AVL_lol(Three_lol);

    cout << "\nВывод всех узлов в АВЛ дереве:" << endl;
    cout << "Прямой обход: ";
    AVL_lol.preOrder(AVL_lol.root);
    cout << "\nЦентрированный обход: ";
    AVL_lol.inOrder(AVL_lol.root);
    cout << "\nОбратный обход: ";
    AVL_lol.postOrder(AVL_lol.root);
    cout << "\nОбход в ширину: ";
    AVL_lol.printLevelOrder(AVL_lol.root);

	return 0;
}

