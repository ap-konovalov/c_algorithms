// Коновалов А.П.


#include <stdio.h>
#define STRINGSIZE 3

//хеш-функция Дженкинса. Вычисляет хэш-функцию из строки str передаваемой в виде указателя на массив символов
int hash(char *str)
{
    int hash,i;
    for (i = hash = 0; i < STRINGSIZE;i++)
    {
        hash += (int)str[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

int main(int argc, const char * argv[]) {
    
//    Задание 1
//    Реализация хеш-функции Дженкинса. На вход функции подается
//    строка, на выходе хэш строки.
    
    char string[STRINGSIZE] =  {'a','3','d'};
    char *arr = string;
    printf("%i\n", hash(arr));
    

    return 0;
}
