#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class DynamicArray {
private:
    T* arr; 
    int lenght; 
    int capacity; 
    
    
    void zamen(T* Arr_t, int capacity_arr)
    {

        if (capacity_arr == capacity)
        {
            lenght++;
            for (int i = 0; i < lenght; i++)
            {
                arr[i] = Arr_t[i];

            }
        }
        else
        {
            T* tempArr = new T[capacity * 2];
            tempArr[0] = Arr_t[0];
            lenght++;
            for (int i = 1; i < lenght; i++)
            {
                tempArr[i] = arr[i - 1];
            }

            delete[] arr;

            arr = tempArr;
            capacity *= 2;
        }
        
    }
public:
    DynamicArray(int init = 10) 
    {
        arr = new T[init]{};
        lenght = 0;
        capacity = init;
    }

    ~DynamicArray();
    
    void push_back(T);
    void push_front(T);
    void add(T, int);
    void remove(int);
    void reduction(int); //сокращает параметр размера длины, если того требуется разарботчику, например чтобы не выводились ненужные нули массива
    friend ostream& operator<< (ostream& os, DynamicArray<T>& mass)
    {
        for (int i = 0; i < mass.size(1); i++)
        {
            os << mass[i] << " ";
        }
        return os;
    }

    DynamicArray<T>& operator= (const DynamicArray<T>& mass)
    {
        if (this == &mass)
            return *this;

        delete[] arr;

        lenght = mass.lenght;
        capacity = mass.capacity;
        arr = new T[capacity];

        for (int i = 0; i < lenght; i++)
        {
            arr[i] = mass.arr[i];
        }

        return *this;
    }

    DynamicArray<T>& operator= (const string& mass)
    {
        lenght = 0;
        delete[] arr;
        int i = 2;
        capacity = 10;
        while (true)
        {
            if (mass.size() > capacity)
            {
                capacity = 10 * i++;
            }
            else
            {
                break;
            }
        }
        arr = new T[capacity];
        if (is_same<T, char>::value)
        {

            for (int i = 0; i < mass.size(); i++)
            {
                arr[i] = mass[i];
            }
            lenght = mass.size();
        }
        else if (is_same<T, int>::value)
        {
            int j = 0;
            for (int i = 0; i < mass.size(); i++)
            {
                if (mass[i] >= '0' && mass[i] <= '9')
                {
                    if (i + 1 < mass.size())
                    {
                        if (mass[i + 1] >= '0' && mass[i + 1] <= '9')
                        {
                            char* mass_t = new char[capacity];
                            int g = i;
                            int r = 0;
                            while (mass[g + 1] >= '0' && mass[g + 1] <= '9')
                            {
                                mass_t[r] = mass[g];
                                g++;
                                r++;
                                if (g + 1 >= mass.size())
                                    break;
                            }
                            mass_t[r] = mass[g];
                            arr[j] = 0;
                            for (int t = 0; t <= r; t++)
                            {
                                arr[j] = arr[j] * 10 + (mass_t[t] - '0');
                            }
                            j++;
                            lenght++;
                            i = g;
                            delete mass_t;
                        }
                        else
                        {
                            arr[j] = mass[i] - '0';
                            j++;
                            lenght++;
                        }
                    }
                    else
                    {
                        arr[j] = mass[i] - '0';
                        j++;
                        lenght++;
                    }
                }
            }
            capacity = 10;
            i = 2;
            while (true)
            {
                if (lenght > capacity)
                {
                    capacity = 10 * i++;
                }
                else
                {
                    break;
                }
            }
        }
        return *this;
    }



    int size(bool);
    T& operator[] (int const);


};

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
    delete[] arr;
}

template<typename T>
inline void DynamicArray<T>::push_back(T data) {
    if (lenght == capacity)
    {
        T* tempArr = new T[capacity * 2]{};

        for (int i = 0; i < lenght; i++)
        {
            tempArr[i] = this->arr[i];
        }

        delete[] arr;

        arr = tempArr;
        capacity *= 2;
    }

    arr[lenght] = data;

    lenght++;
}

template<typename T>
inline void DynamicArray<T>::push_front(T data)
{
    DynamicArray<T> Arr_t(capacity);
    Arr_t[0] = data;
    Arr_t.lenght++;
    for (int i = 1; i < lenght + 1; i++) 
    {
        Arr_t.push_back(arr[i - 1]);
    }
    zamen(Arr_t.arr, Arr_t.capacity);
    int sdfgdfg = 0;
    
}

template<typename T>
inline void DynamicArray<T>::add(T data, int index)
{
    DynamicArray<T> Arr_t(capacity);
    for (int i = 0; i < lenght; i++)
    {
        Arr_t[i] = arr[i];
        Arr_t.lenght++;
    }
    if (index == 0)
    {
        Arr_t.push_front(data);
        zamen(Arr_t.arr, Arr_t.capacity);
    }
    else if (index == lenght)
    {
        Arr_t.push_back(data);
        zamen(Arr_t.arr, Arr_t.capacity);
    }
    else if (index < lenght)
    {
        if (lenght + 1 < capacity)
        {
            for (int i = 0; i < index; i++)
            {
                Arr_t[i] = arr[i];
            }
            Arr_t[index] = data;
            for (int i = index; i < lenght; i++)
            {
                Arr_t[i + 1] = arr[i];
            }
            zamen(Arr_t.arr, Arr_t.capacity);
        }
        else
        {
            T* tempArr = new T[capacity * 2]{};

            for (int i = 0; i < index; i++)
            {
                tempArr[i] = this->arr[i];
            }
            tempArr[index] = data;
            for (int i = index; i < lenght; i++)
            {
                tempArr[i + 1] = this->arr[i];
            }

            delete[] arr;

            arr = tempArr;
            capacity *= 2;
            lenght++;
        }
        
        
        


    }
    else if (index > lenght)
    {
        if (index < capacity)
        {
            arr[index] = data;
            lenght = index + 1;
        }
        else
        {
            while (index >= capacity)
            {
                T* tempArr = new T[capacity * 2]{};

                for (int i = 0; i < lenght; i++)
                {
                    tempArr[i] = this->arr[i];
                }

                delete[] arr;

                arr = tempArr;
                capacity *= 2;
            }
            arr[index] = data;
            lenght = index + 1;
        }
    }

}

template<typename T>
inline void DynamicArray<T>::remove(int index)
{
    
    if (index >= lenght)
    {
        return;
    }
    else
    {
        
        T* tempArr = new T[capacity]{};
        for (int i = 0; i < lenght; i++)
        {
            if (i != index)
            {
                tempArr[i] = arr[i];
            }
            else
            {
                if (index != capacity - 1)
                {
                    for (int g = index; g < lenght; g++)
                    {
                        tempArr[g] = arr[g + 1];

                    }
                    break;
                }
                else
                {
                    break;
                }
            }
        }

        zamen(tempArr, capacity);
        lenght-= 2;
        
        
    }
}

template<typename T>
inline void DynamicArray<T>::reduction(int red)
{
    int lenght_t = lenght;
    T null_mass[1]{};
    for (int g = 0; g < red; g++)
    {
        int i = lenght_t;
        if (arr[i] == null_mass[0])
        {
            lenght--;
        }
        else
        {
            break;
        }
        i--;
    }
}

template<typename T>
inline int DynamicArray<T>::size(bool lenghtBool)
{
    if (lenghtBool)
    {
        return lenght;
    }
    else
    {
        return capacity;
    }
    
}

template<typename T>
inline T& DynamicArray<T>::operator[](int const index)
{
    return arr[index];
}
