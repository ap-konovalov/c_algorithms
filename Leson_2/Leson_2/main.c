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




int main(int argc, const char * argv[]) {

    //Задание 1
    // Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
    convertToBinary(15);

    return 0;
}
