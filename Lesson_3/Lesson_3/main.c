// Коновалов А.П.

#include <stdio.h>
#include <stdbool.h>
#define ARRSIZE 15

//переставляет элементы местами
void swap (int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//печатает массив a длинной N
void print (int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf("%4i", a[i]);
    printf("\n");
}

//пузырькова сортировка массива
void bubbleSort()
{
    int a[ARRSIZE] = {2,3,7,13,8,9,45,6,103,32,1,24,8,4,10};          // Создаём массив
    puts("Array before bubble sort");
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
    puts("Array after bubble sort");
    print(ARRSIZE, a);
    printf("Count of operations %i\n",count);
}

//улучшенная пузырьковая сортировка
void bubbleSortUpgrade()
{
    int b[ARRSIZE] = {2,3,7,13,8,9,45,6,103,32,1,24,8,4,10};          // Создаём массив
    puts("Array before upgrated bubble sort");
    print(ARRSIZE, b);

    int j = 0;
    int i = 0;
    int count = 0;
    bool flag = true;
  
//  будем продолжать сортировку только если есть что менять местами. Если в цикле не было ни одного обмена, значит массив отсортирован
    while (flag)
    {
        flag = false;
//  при каждой последующей итерации будем уменьшать количество сравниваемых элементов на  i, так как в конце будут собираться уже отсротированные элементы
        for(j = 0; j < ARRSIZE - i - 1; j++)
        {
            count++;
            if (b[j] > b[j + 1])
            {
                swap(&b[j], &b[j + 1]);
                flag = true;
            }
        }
        i++;
    }
    puts("Array after upgrated bubble sort");
    print(ARRSIZE, b);
    printf("Count of operations  %i\n",count);
}






void shakerSorting()
{
   
}


int main(int argc, const char * argv[]) {

//    Задание 1
//    Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения
//    оптимизированной и неоптимизированной программы. Написать функции сортировки, которые возвращают
//    количество операций.
    
    bubbleSort();
    bubbleSortUpgrade();
    
//  Задание 2
// *Реализовать шейкерную сортировку.
    
    return 0;

}
