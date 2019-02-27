// Коновалов А.П.
#include <time.h>
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

// генератор случайного числа возвращающий случайное число
int rndNumb()
{
    time_t seconds;
    seconds = time (TID_NULL);
    //берем из системного времени в секундах 2 последних числа
    int number = seconds % 100;
    //генерируем с помощью случайного числа другое число, чтобы не выдавались близкие числа при запросе за короткий интервал
    number = (45 * number + 21) % 100;
    
    return number;
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
   

    int x = rndNumb();
    int y = rndNumb();
    printf("%i %i",x,y);
 
    
    return 0;
    
}
