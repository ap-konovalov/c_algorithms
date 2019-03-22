// Коновалов А.


#include <stdio.h>
#include <stdlib.h>
#define MATRIXSIZE 5
//задает размер массива
int matrixSize;


//==============Task 2
 //Создади м массив в который будем писать пройденные вершины 1 - вершина пройдена, 0 - нет
int used[MATRIXSIZE];

int Matrix[MATRIXSIZE][MATRIXSIZE];
Matrix[MATRIXSIZE][MATRIXSIZE] = {
    {0,1,0,0,1},
    {1,0,1,1,0},
    {0,1,0,1,0},
    {0,1,1,0,0},
    {1,0,0,0,0},
};

int visited;

void dfs(int visited)
{
    int i;
    //помечаем узел в специально созданном массиве  как пройденный
    used[visited] = 1;
    printf("Node %d visited \n",visited);
    
    for(i = 1; i <= MATRIXSIZE; i++)
    {
        // если в матрице 1 = true для выражения значит есть связь между узлами && если узел не посещен (в used[i] значение 0 = false)
        // то мы рекурсивно вызовем функцию которая посетит не посещенный узел с которым есть связь у текеущего узла
        if(Matrix[visited][i] && !used[i])
        {
            dfs(i);
        }
    }
}

// распечатаем массив
void printMatrix(int adjacencyMatrix[matrixSize][matrixSize])
{
    int i,j;
    for (i = 0; i < matrixSize; i++)
    {
        for(j=0; j < matrixSize;j++)
        {
            printf("%i ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    
//   Задание 1
//   Написать функции, которые считывают матрицу смежности из файла и выводят её на экран.
    
    int i,j;
    // считаем матрицу из файла data.txt
    FILE* file = fopen("data.txt","r");
    //если файл не найден выведем сообщение и завершим программу
    if (file == NULL)
    {
        puts("Can't open file");
        exit(1);
    }
    //считаем размер массива
    fscanf(file, "%i", &matrixSize);
    // создадим пустой массив
    int adjacencyMatrix[matrixSize][matrixSize];
    //считаем значения в массив из файла
    for (i = 0; i < matrixSize; i++)
    {
        for (j = 0; j < matrixSize; j++)
        {
            int value;
            fscanf(file, "%i" ,&value);
            adjacencyMatrix[i][j] = value;
        }
    }
    fclose(file);
    printMatrix(adjacencyMatrix);
    
//    Задание 2
//    Написать рекурсивную функцию обхода графа в глубину.
   
    // обход графа в глубину  с  вершины 0
    dfs(0);
    
    return 0;
}
