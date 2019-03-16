// Коновалов А.П.


#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>
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


//================= Двоичное дерево поиска =================

typedef int T;

//структура описывающая узел дерева
typedef struct Node
{
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

//распечатка двоичного дерева в виде скобочной записи
void printTree(Node *root)
{
    if (root)
    {
        printf("%d" , root -> data);
        if (root -> left || root -> right)
        {
            printf("(");
                if(root -> left)
                {
                    printTree(root -> left);
                }
                else
                {
                    printf("NULL");
                }
                printf(",");
            
                if (root -> right)
                {
                    printTree(root -> right);
                }
                else
                {
                    printf("NULL");
                    printf(")");
                }
        }
    }
 };

// Создание нового узла
Node* getFreeNode(T value, Node *parent)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    // создаем пустой левый и правый узел
    tmp -> left = tmp -> right = NULL;
    // записываем значение в текущий узел дерева
    tmp -> data = value;
    // записываем кто узел родитель
    tmp -> parent = parent;
    return tmp;
}

// Вставка узла
void insert(Node **head, int value)
{
    Node *tmp = NULL;
    // если нет значения узла родителя head то мы сейчас в корне, создаем узел со значением, но без родителя
    if (*head == NULL)
    {
        //создаем корневой узел дерева
        *head = getFreeNode(value, NULL);
        return;
    }
    
    tmp = *head;
    // пока есть родительские узлы
    while (tmp)
    {
        // если текущее значение  больше значения в родительском узле,то создадим узел справа и запишем текущее значение в него
        if(value > tmp -> data)
        {
            // если есть правый узел, то временный узел = правому, а мы переходим к проверке условия снова
            if(tmp -> right)
            {
                tmp = tmp -> right;
                continue;
            }
            // если правый узел пуст создадим там новый узел с текущим значением
            else
            {
                tmp -> right = getFreeNode(value, tmp);
                return;
            }
        }
        // если текущее значение меньше значения в родительском узле,то создадим узел слева и запишем текущее значение в него
        else if(value < tmp -> data)
        {
             // если есть левый узел, то  временный узел = левому, а мы переходим к проверке условия снова
            if(tmp -> left)
            {
                tmp = tmp -> left;
                continue;
            }
            // если левый узел пуст создадим там новый узел с текущим значением value и родителем tmp
            else
            {
                tmp -> left = getFreeNode(value, tmp);
                return;
            }
        }
        else
        {
            exit(2);                     // Дерево построено неправильно
        }

    }
}


// Рекурсивный обход дерева. Сначала корень потом левая часть дереве потом правая (КЛП)
void preOrderTravers(Node* root)
{
    if (root)
    {
        printf("%d", root -> data);
        preOrderTravers(root -> left);
        preOrderTravers(root -> right);
    }
}

int main(int argc, const char * argv[]) {
    
//    Задание 1
//    Реализация хеш-функции Дженкинса. На вход функции подается
//    строка, на выходе хэш строки.
    
    char string[STRINGSIZE] =  {'a','3','d'};
    char *arr = string;
    printf("String hash: %i\n", hash(arr));
    
//    Задание 2
//    Переписать программу, реализующее двоичное дерево поиска:
//    Добавить в него обход дерева различными способами.
//    Реализовать поиск в нём.
//    *Добавить в программу обработку командной строки с помощью
//    которой можно указывать, из какого файла считывать данные, каким образом обходить дерево.

    Node *Tree = NULL;
    FILE* file = fopen("data.txt", "r");
    if (file == NULL)
    {
        puts("Can't open file");
        exit(1);
    }
    int count;
    fscanf(file, "%d", &count);          // Считываем количество записей
    int i;
    //вставляем каждую запись в новый узел дерева
    for(i = 0; i < count; i++)
    {
        int value;
        fscanf(file, "%d", &value);
        insert(&Tree, value);
    }
    fclose(file);
    printTree(Tree);
    printf("\nPreOrderTravers:");
    preOrderTravers(Tree);
     printf("\n");
    return 0;
}
