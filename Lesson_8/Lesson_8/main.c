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

int main(int argc, const char * argv[]) {
    
    // Задание 1
    // Реализовать сортировку подсчётом.
    
    // Условимся что есть массив целых чисел от 0 до N
    int unorderedArray[ARRSIZE] = {9,1,3,4,5,1,3,4,0,1,7,8,7,2,7};
    //отсортируем массив
    countingSort(unorderedArray, ARRSIZE);
    //распечатаем отсортированный массив
    printArray(unorderedArray, ARRSIZE);
    
    return 0;
}
