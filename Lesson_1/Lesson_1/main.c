// Коновалов А.П.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Функция проверки числа на автоморфность
bool isAutomorphicNum(int number)
{
    int numsqrt;
    
    numsqrt = pow(number, 2);
    
    while (number > 0)
    {
        if (number % 10 == numsqrt % 10)
        {
            numsqrt /= 10;
            number /= 10;
        }
        else
        {
            return false;
        }
        
    }
    
    return true;
    
}

//Функция печати всех автоморфных чисел от 0 до number
void printAllAutomorphic(int number)
{
    for (int i = 0; i <= number; i++)
    {
        if (isAutomorphicNum(i))
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    
    // Задание 14
    // Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.Например,
    // 25 \ :sup: '2' = 625. Напишите программу, которая
    // получает на вход натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
    
    printAllAutomorphic(625);
    
    //    Задание 13
    //    Написать функцию, генерирующую случайное число от 1 до 100:
    //    a.С использованием стандартной функции rand().
    //    b.Без использования стандартной функции rand().
    
    return 0;
    
}
