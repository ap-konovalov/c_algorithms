// Коновалов А.П.

#include <time.h>
#include <stdlib.h>
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

// генератор случайного числа без использования стандартной функции rand()
int rndNumb()
{
    clock_t t1, t2;
    //записываем тик в переменную со временем
    t1 = clock();
    int i;
    //производим вычисления чтобы прошло время и записалась другая переменная с временным тиком
    for(i = 0; i < 1000000; i++)
    {
        int x = 90;
    }
    t2 = clock();
    int result = ((int)(t2 - t1));
    result = result %100;
    
    return result;
}

// Написать функцию нахождения максимального из трёх чисел.
// найдем максимум из 2х чисел
int maxNumb(int a,int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
//теперь запустим сравнение 2 раза и получим максиму для 3х
int maxFromThree(int a, int b, int c)
{
    int max = maxNumb(a, b);
    max = maxNumb(max, c);
    return max;
}

// Подсчитать среднее арифметическое всех положительных чётных чисел, оканчивающихся на 8
//проерим что течное
bool isEven(int x)
{
    return x % 2 == 0;
}
//проверим что больше 0
bool isPositive(int x)
{
    return x > 0;
}
//проверим что оканчивается на 8
bool endsAtEight(int x)
{
    if (x % 10 == 8 ||  x == 8)
    {
        return 1;
    }
    return 0;
}
//Подсчитаем среднее арифметическое всех положительных чётных чисел, оканчивающихся на 8
void averegOfEvenNumer()
{
    int x;
    int sum = 0;
    int counter = 0;
    printf("\nInsert numbers (to exit insert 0):\n ");
    do
    {
    scanf("%i", &x);
    if(isPositive(x) && isEven(x) && endsAtEight(x))
    {
        sum = sum + x;
        counter++;
    }
    }while (x != 0);
    printf("\n%i ", sum/counter);
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
    //    b.Без использования стандартной функции rand().
    
    // выведем на экран 10 случайных чисел, сгенерированных функцией rndNumb()
    for(int i =0 ; i < 10; i++)
    {
    printf("\n%i ",rndNumb());
    }
    
    // Задание 12
    // Написать функцию нахождения максимального из трёх чисел.
    printf("\nMax number = %i ",maxFromThree(32,1,4));
    
    // Задание 11
    // С клавиатуры вводятся числа, пока не будет введён 0.
    // Подсчитать среднее арифметическое всех положительных чётных чисел, оканчивающихся на 8
    averegOfEvenNumer();
    
    return 0;

}
