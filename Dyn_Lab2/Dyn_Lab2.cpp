// Dyn_Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <stdexcept>

class DynArray
{
private:
    int* mas; // Указатель на массив
    int size; // Размер массива

public:
    // Конструктор по умолчанию и с параметром
    DynArray(int sz = 8)
    {
        mas = new int[sz] {};
        size = sz;
    }

    // Инициализация объекта с помощью значений из массива
    DynArray(int* P, int sz)
    {
        mas = new int[sz];
        size = sz;
        for (int i = 0; i < size; i++)
        {
            mas[i] = P[i];
        }
    }

    // Конструктор копирования
    DynArray(const DynArray& obj)
    {
        size = obj.size;
        mas = new int[size];
        for (int i = 0; i < size; i++)
        {
            mas[i] = obj.mas[i];
        }
    }

    // Деструктор
    ~DynArray()
    {
        delete[] mas;
    }

    // Оператор присвоения
    DynArray& operator=(const DynArray& obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        delete[] mas;

        size = obj.size;
        mas = new int[size];
        for (int i = 0; i < size; i++)
        {
            mas[i] = obj.mas[i];
        }

        return *this;
    }

    // Перегрузка оператора +, который выполняет объединение массивов
    DynArray operator+(const DynArray& obj)
    {
        int newSize = size + obj.size;
        DynArray result(newSize);

        for (int i = 0; i < size; i++)
        {
            result.mas[i] = mas[i];
        }

        for (int i = 0; i < obj.size; i++)
        {
            result.mas[size + i] = obj.mas[i];
        }

        return result;
    }

    // Перегрузка оператора [], который выполняет обращение к заданному элементу
    int& operator[](int ix)
    {
        if (ix < 0 || ix >= size)
        {
            throw std::out_of_range("Index out of range");
        }

        return mas[ix];
    }

    // Перегрузка потокового вывода
    friend std::ostream& operator<<(std::ostream& os, const DynArray& obj)
    {
        for (int i = 0; i < obj.size; i++)
        {
            os << obj.mas[i] << " ";
        }
        return os;
    }
};

int main()
{
    try
    {
        // Тестирование конструктора по умолчанию и с параметром
        DynArray arr1; // Создается массив размером 8 (0 0 0 0 0 0 0 0)
        DynArray arr2(5); // Создается массив размером 5 (0 0 0 0 0)

        // Тестирование инициализации объекта с помощью значений из массива
        int values[] = { 1, 2, 3, 4, 5 };
        DynArray arr3(values, 5); // Создается массив (1 2 3 4 5)

        // Тестирование конструктора копирования и оператора присвоения
        DynArray arr4(arr3); // Создается копия arr3
        DynArray arr5;
        arr5 = arr3;

        // Тестирование оператора +
        DynArray arr6 = arr3 + arr5; // Объединение массивов arr3 и arr5

        // Тестирование оператора []
        std::cout << arr6[0] << std::endl; // Выводит 1
        arr6[0] = 10; // Меняем значение элемента
        std::cout << arr6[0] << std::endl; // Выводит 10

        // Тестирование перегрузки потокового вывода
        std::cout << arr6 << std::endl; // Выводит 10 2 3 4 5 1 2 3

    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


