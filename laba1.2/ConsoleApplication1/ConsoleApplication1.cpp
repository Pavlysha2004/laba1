#include"list.h"
#include"dinMass.h"
#include<iostream>
#include"Stek.h"
#include<string>
#include <cmath>
using namespace std;

string sort(string data)
{
    DynamicArray<int> num_skob;
    
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == '(')
        {
            while (1 == 1)
            {
                bool k = 0;
                for (int g = i; g < data.size(); g++)
                {
                    
                    if (data[g] == ')')
                    {
                        int k2 = 1;
                        for (int p = 0; p < num_skob.size(0); p++)
                        {

                            if (g == num_skob[p])
                            {
                                k2 = 0;
                                break;
                            }

                        }
                        if (k2 == 1)
                        {
                            num_skob.push_back(g);
                            k = 1;
                            break;
                        }
                        
                    }
                    
                }
                
                if (k)
                {
                    break;
                }
                else
                {
                    cout << "Ошибка ввода скобок";
                    return 0;
                }
                

            }

        }
        else if (data[0] == ')')
        {
            cout << "выражение не может начинаться с закрывающей скобки";
            return 0;
        }
    }        //////////////проверили скобки
    Stek<char> fun;
    fun.push('.');
    string out_str;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] >= '0' && data[i] <= '9')
        {
            if (i != data.size())
            {

                int j = 0;
                while (data[i] != ' ')
                {
                    out_str.push_back(data[i]);
                    i++;
                    if (i == data.size())
                    {
                        break;
                    }
                }
                out_str.push_back(' ');

            }
        }
        else if (data[i] == '+' || data[i] == '-')
        {
            bool out1 = 1;
            while (out1)
            {
                if (fun[0] != '+' && fun[0] != '-' && fun[0] != '*' && fun[0] != '/'
                    && fun[0] != '^' && fun[0] != 's' && fun[0] != 'c')
                {
                    fun.push(data[i]);
                    out1 = 0;
                }
                else
                {
                    out_str.push_back(fun[0]);
                    fun.pop();
                    out_str.push_back(' ');
                }
            }
        }
        else if (data[i] == '*' || data[i] == '/')
        {
            bool out1 = 1;
            while (out1)
            {
                if (fun[0] != '*' && fun[0] != '/' && fun[0] != '^' && fun[0] != 's' && fun[0] != 'c')
                {
                    fun.push(data[i]);
                    out1 = 0;
                }
                else
                {
                    out_str.push_back(fun[0]);
                    fun.pop();
                    out_str.push_back(' ');
                }
            }
        }
        else if (data[i] == 's' || data[i] == 'c' || data[i] == '^')
        {
            fun.push(data[i]);
            if (data[i] == 's' || data[i] == 'c')
            {
                i += 2;
            }
        }
        else if (data[i] == '(')
        {
            fun.push(data[i]);
        }
        else if (data[i] == ')')
        {
            while (1 == 1)
            {
                if (fun[0] == '(')
                {
                    fun.pop();
                    break;
                }
                else
                {
                    out_str.push_back(fun[0]);
                    fun.pop();
                    out_str.push_back(' ');
                }
            }
        }
    }
    while (fun[0] != '.')
    {
        out_str.push_back(fun[0]);
        fun.pop();
        out_str.push_back(' ');
    }
    string beauti_str;
    for (int i = 0; i < out_str.size(); i++)
    {
        if (out_str[i] == 'c')
        {
            beauti_str.push_back('c');
            beauti_str.push_back('o');
            beauti_str.push_back('s');
        }
        else if (out_str[i] == 's')
        {
            beauti_str.push_back('s');
            beauti_str.push_back('i');
            beauti_str.push_back('n');
        }
        else
        {
            beauti_str.push_back(out_str[i]);
        }
    }
    return beauti_str;
}


int main()
{

    setlocale(LC_CTYPE, "Russian");
    cout << "реализация стека на примере сортировoчной станции:\n";
    cout << "Введите выражение: ";
    string expression;
    getline(cin, expression);
    cout << "Обратная польская версия: "<< sort(expression);




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





