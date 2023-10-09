#pragma once


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
    DynamicArray(int init = 10) {
        arr = new T[init]{};
        lenght = 0;
        capacity = init;
    }

    ~DynamicArray();

    void push_back(T);
    void push_front(T);
    void add(T, int);
    void remove(int);
    void reduction(int); //��������� �������� ������� �����, ���� ���� ��������� ������������, �������� ����� �� ���������� �������� ���� �������
    
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
