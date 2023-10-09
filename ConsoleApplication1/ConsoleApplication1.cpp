#include"list.h"
#include"dinMass.h"
#include<iostream>
#include"Stek.h"
using namespace std;

int main()
{

    setlocale(LC_CTYPE, "Russian");
    cout << "реализация стека:";
    Stek<int> lol;
    lol.push(5);
    lol.push(8);
    lol.push(9);
    lol.push(53);
    lol.push(12);
    lol.push(555);
    lol.push(125);
    lol.push(9999);
    cout << "\nРазмер: " << lol.size();
    cout << "\nПоложили символы в стек: ";
    for (int i = 0; i < lol.size(); i++)
    {
        cout << lol[i] << " " ;
    }
    lol.pop();
    lol.pop();
    cout << "\nsize: " << lol.size();
    cout << "\nУбрали два символа из стека: ";
    for (int i = 0; i < lol.size(); i++)
    {
        cout << lol[i] << " ";
    }

    cout << "\n\nPeaлизация списка:";
    list<int> lol2;
    lol2.push_back(5);
    lol2.push_back(8);
    lol2.push_back(9);
    lol2.push_back(53);
    lol2.push_back(12);
    lol2.push_back(555);
    lol2.push_back(125);
    lol2.push_back(9999);
    cout << "\nРазмер: " << lol2.size();
    cout << "\nПоложили символы в конец списка: ";
    for (int i = 0; i < lol2.size(); i++)
    {
        cout << lol2[i] << " ";
    }
    
    lol2.push_front(666);
    lol2.push_front(321);
    lol2.push_front(8);
    
    
    cout << "\nРазмер: " << lol2.size();
    cout << "\nПоложили символы в начало списка: ";
    for (int i = 0; i < lol2.size(); i++)
    {
        cout << lol2[i] << " ";
    }
    
    lol2.add(5598, 4);
    
    cout << "\nРазмер: " << lol2.size();
    cout << "\nПоложили символ 5598 на позицию 4: ";
    for (int i = 0; i < lol2.size(); i++)
    {
        cout << lol2[i] << " ";
    }
    
    lol2.remove(4);
    
    cout << "\nРазмер: " << lol2.size();
    cout << "\nУдалилти символ с позиции 4: ";
    for (int i = 0; i < lol2.size(); i++)
    {
        cout << lol2[i] << " ";
    }

    cout << "\n\nPeaлизация динамического массива:";
    DynamicArray<int> lol3;
    lol3.push_back(5);
    lol3.push_back(8);
    lol3.push_back(9);
    lol3.push_back(53);
    lol3.push_back(12);
    lol3.push_back(555);
    lol3.push_back(125);
    lol3.push_back(9999);

    cout << "\nРазмер общий: " << lol3.size(0);
    cout << "\nкол-во символов (lenght): " << lol3.size(1);
    cout << "\nпоместили символы в конец массива: ";
    for (int i = 0; i < lol3.size(1); i++)
    {
        cout << lol3[i] << " ";
    }

    lol3.add(12348, 6);
    lol3.add(65321, 0);
    lol3.add(8989, 15);

    cout << "\nРазмер общий: " << lol3.size(0);
    cout << "\nкол-во символов (lenght): " << lol3.size(1);
    cout << "\nпоместили символы на позиции 6 0 и 15: ";
    for (int i = 0; i < lol3.size(1); i++)
    {
        cout << lol3[i] << " ";
    }

    lol3.push_front(85);
    lol3.push_front(12);
    lol3.push_front(19);

    cout << "\nРазмер общий: " << lol3.size(0);
    cout << "\nкол-во символов (lenght): " << lol3.size(1);
    cout << "\nпоместили символы в начало массива: ";
    for (int i = 0; i < lol3.size(1); i++)
    {
        cout << lol3[i] << " ";
    }

    lol3.remove(0);
    lol3.remove(17);
    lol3.remove(35);

    cout << "\nРазмер общий: " << lol3.size(0);
    cout << "\nкол-во символов (lenght): " << lol3.size(1);
    cout << "\nУдалили символы на позициях 0, 17 и 35(ничего не произойдёт): ";
    for (int i = 0; i < lol3.size(1); i++)
    {
        cout << lol3[i] << " ";
    }
    lol3.reduction(3); //отдельная функция нужна, если вдруг разработчик захочет оставить эти нули после числа, то их можно не удалять, а если не нужны, можно просто сократить размер массива 
    cout << "\nРазмер общий: " << lol3.size(0);
    cout << "\nкол-во символов (lenght): " << lol3.size(1);
    cout << "\nТак как у нас были лишние пустые значения забитые нулями, мы сократим с помощью специальной функции длинну массива: ";
    for (int i = 0; i < lol3.size(1); i++)
    {
        cout << lol3[i] << " ";
    }

    cout << "\n\n\n";
    return 0;
}





