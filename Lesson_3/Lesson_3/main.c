// Коновалов А.П.

#include <stdio.h>
#define ARRSIZE 15

void swap (int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print (int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf("%4i", a[i]);
    printf("\n");
}

void bubbleSort()
{
    int a[ARRSIZE] = {2,3,7,13,8,9,45,6,103,32,1,24,8,4,10};          // Создаём массив
    puts("Array before sort");
    print(ARRSIZE, a);
    
    int i = 0;
    int j = 0;
    int count = 0;
    
    for(i = 0; i < ARRSIZE - 2 ; i++)
    {
        for(j = 0; j < ARRSIZE  - 1; j++)
        {
            count++;
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    puts("Array after sort");
    print(ARRSIZE, a);
    printf("Count of operations %i\n",count);
}

void bubbleSortUpgrade()
{
    int b[ARRSIZE] = {2,3,7,13,8,9,45,6,103,32,1,24,8,4,10};          // Создаём массив
    puts("Array before upgrated bubble sort");
    print(ARRSIZE, b);

    int i = 0;
    int j = 0;
    int count = 0;
  

    for(i = 0; i < ARRSIZE - 2 ; i++)
    {
        for(j = 0; j < ARRSIZE - i  - 1; j++)
        {
            count++;
            if (b[j] > b[j + 1])
            {
                swap(&b[j], &b[j + 1]);
            }
        }
    }
    puts("Array after upgrated bubble sort");
    print(ARRSIZE, b);
    printf("Count of operations  %i\n",count);
}

int main(int argc, const char * argv[]) {

//    Задание 1
//    Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения
//    оптимизированной и неоптимизированной программы. Написать функции сортировки, которые возвращают
//    количество операций.
    
    bubbleSort();
    bubbleSortUpgrade();
    
    return 0;

}
