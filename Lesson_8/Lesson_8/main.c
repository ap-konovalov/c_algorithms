// Коновалов А.


#include <stdio.h>
#define ARRSIZE 15

//функция поиска максимального элемента в массиве
int maxArrElement(int array[],int size)
{
    int i;
    int max = array[0];
    for (i = 0; i < size-1; i++)
    {
        if(array[i + 1] > max)
        {
            max = array[i+1];
        }
    }
    return max;
}

// функция заполняет все значения массива нулями
void resetArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++ )
    {
        array[i] = 0;
    }
}

//  функция печатает массив
void printArray(int array[], int size)
{
    int j;
    for(j = 0; j < size;j++)
    {
        printf("%i " , array[j]);
    }
    printf("\n");
}

void countingSort(int array[],int size)
{
    //создадим переменную для задания размерности частотного масива с максимальным числом из массива array  + 1
    int countArrSize = maxArrElement(array, size) + 1;
    // создадим массив для подсчета
    int counArray[countArrSize];
    //заполним массив для подсчета(частотный массив) нулями
    resetArray(counArray, countArrSize);

    // посчитаем сколько раз нам встречается каждая цифра из массива array
    int i,j;
    for (i = 0; i < size; i++ )
    {
        int counArrayIndex = array[i];
        counArray[counArrayIndex]++;
    }
    
    int k =0;
    // для всех элементов частотного массива
    for (i = 0; i < countArrSize; i++)
    {
        // выполнить столько раз, сколько записано в ячейке с этим индексом
        for(j = 0; j < counArray[i] ;j++)
        {
            //присваиваем элементу отсотрированного массива с индекстом k значение равное индексу частотного массива
            array[k] = i;
            // переходим к следующему элементу сортированного массива
            k++;
        }
    }
}

// ======================== Задание 2
// void swap(int *, int *);

// функция обмена местами 2х элементов
void swap(int *p, int *q)
{
    int buf;
    buf = *p;
    *p = *q;
    *q = buf;
}

// функция быыстрой сортировки
void quickSort(int array[],int first, int last)
{
    int i = first;
    int j = last;
    // определим элемент в середине массива
    int middle = array[(last + first)/2];
    
    // будем делать пока левый и правый указатель не встретятся
    do
    {
        // пока левый элемент меньше середины
        while (array[i] < middle)
        {
            // перемещаем левый указатель на следующий элемент справа
             i++;
        }
        //пока правый элемент больше середины
        while (array[j] > middle)
        {
            // перемещаем правый указатель на 1 элемент влево
            j--;
        }
        
        //если левый указатель меньши или равен правому
        if(i <= j)
        {
            // если элемент слева от середины больше чем элемент справа от середины, то их нужно поменять местами
            if (array[i] > array[j])
            {
                swap(&array[i], &array[j]);
            }
            i++;
            j--;
        }
    } while ( i <= j);
    
    //если левый указатель меньше правой границы массива
    if(i < last)
    {
        // выполним бытрую сортировку от левого указателя до правой границы массива
        quickSort(array, i, last);
    }
    // если правый указатель больше левой границы массива
    if(first < j)
    {
        // выполним сортировку от левой гранцы массива до правого указателя
        quickSort(array, first, j);
    }
}

int main(int argc, const char * argv[]) {
    
    // Задание 1
    // Реализовать сортировку подсчётом.
    
    // Условимся что есть массив целых чисел от 0 до N
    int unorderedArray[ARRSIZE] = {11,1,3,4,5,1,3,4,0,1,7,8,7,2,7};
    //отсортируем массив
    countingSort(unorderedArray, ARRSIZE);
    //распечатаем отсортированный массив
    printArray(unorderedArray, ARRSIZE);
    
    // Задание 2
    // Реализовать быструю сортировку.
    int unorderedArray2[ARRSIZE] = {7,1,2,6,7,13,3,45,0,23,76,38,7,2,7};
    quickSort(unorderedArray2, 0,ARRSIZE-1);
    printArray(unorderedArray2, ARRSIZE);
    
    return 0;
}
