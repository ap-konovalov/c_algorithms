//Коновалов А.П.

#include <stdio.h>

//функция переводит число number из десятичной системы счисления в двоичную
void convertToBinary(int number)
{
    if (number >= 2)
    {
        convertToBinary(number/2);
    }
    printf("%d", number % 2);
}

//Функция возведения числа number в степень degree
void powerOf(int number, int degree)
{
    int result = 1 ;
    while(degree > 0)
    {
        result *= number;
        degree--;
    }
    printf("\n%d", result);
}

//Функция возведения числа number в степень degree при помощи рекурсии
int recursionPowerOf(int number, int degree)
{
    return degree == 1 ? number : number * recursionPowerOf(number, degree - 1);
}

int main(int argc, const char * argv[]) {

    //Задание 1
    // Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
    convertToBinary(15);
    
//    Задание 2
//    Реализовать функцию возведения числа a в степень b:
//    Без рекурсии.
//    Рекурсивно.
//    *Рекурсивно, используя свойство чётности степени.

//     число в степени фунция без рекурсии
    powerOf(3, 3);
    
    // число в степени фунция с рекурсией
    int res = recursionPowerOf(3, 7);
        printf("\n%d", res);
    
    return 0;
}
