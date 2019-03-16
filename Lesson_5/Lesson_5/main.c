// Коновалов А.П.

#include <stdio.h>
#include <stdlib.h>
#define Bracket char
#define STRSIZE 6
#define TurnSize 10

struct TNode
{
    Bracket value;
    struct TNode *next;
};

//Чтобы не писать в программе struct TNode, дадим этой структуре имя Node
typedef struct TNode Node;

struct Stack
{
    Node *head;
    int size;
    int maxSize;
};
struct Stack Stack;

void push(Bracket value)
{
    if(Stack.size >= Stack.maxSize)
    {
        printf("Error. Stack is full");
        return;
    }
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = Stack.head;
    Stack.head = tmp;
    Stack.size++;
}

Bracket pop()
{
    if(Stack.size == 0)
    {
        printf("Stack is empty");
        return 0;
    }
    // Временный указатель
    Node *next = NULL;
    // Значение «наверху» списка
    Bracket value;
    value = Stack.head -> value;
    next = Stack.head;
    Stack.head = Stack.head -> next;
    // Запись, на которую указывала «голова», удаляем, освобождая память
    free(next);
    // Возвращаем значение, которое было в «голове»
    Stack.size--;
    return value;
}

void PrintStack()
{
    Node *current = Stack.head;
    while(current != NULL)
    {
        printf("%c ", current->value);
        current = current->next;
    }
}

// сравниваем пару символов: firstPairSymb - открывающая скобка к нему ищем закрывающую secondPairSym
void PairCheck(char firstPairSymb,char secondPairSym)
{
    //если в стэке пусто пары к закрывающей скобке не будет, можно завершать программу
    if( Stack.size == 0)
    {
        // Выведем сообщение о лишнем символе
        printf("Wrong sequence. First extra symbol is: \"%c\"\n", secondPairSym);
        _Exit (EXIT_SUCCESS);
    }
    //если в стэке сверху лежит открывающая скобка-пара к нашей закрывающей, то уберем ее из стека
    else if(Stack.head->value == firstPairSymb)
    {
        pop();
    }
    // если пара не нашлась положим символ в стэк и ищем пары дальше
    else
    {
        push(secondPairSym);
    }
}

// Добавляем в массив-очереь "arr" элемент value на позицию rear потом двигаем rear на 1 чтобы добавлять следующий элемент
void turnAdd(char *arr, int *rear, char value)
{
    if (*rear > TurnSize - 1)
    {
        *rear = *rear % TurnSize;
    }
    arr[*rear] = value;
    *rear = *rear + 1;
}

// Извлекаем из массива-очереди "arr"  элемент с индексом front-1 и увеличиваем значение front чтобы извлечь следующий элемент
char turnExtract(char *arr, int *front)
{
    if (*front > TurnSize - 1)
    {
        *front = *front % TurnSize;
    }
    *front = *front + 1;
    return  arr[*front - 1];
};


int main(int argc, const char * argv[]) {

//    Задание 3
//    Написать программу, которая определяет, является ли введённая скобочная
//    последовательность правильной. Примеры правильных скобочных
//    выражений – (), ([])(), {}(), ([{}]),
//    неправильных – )(, ())({), (, ])}), ([(]), для скобок – [, (, {.
//    Например: (2+(2*2)) или [2/{5*(4+7)}]
    
    Stack.maxSize = 100;
    Stack.head = NULL;
// зададим массив со скробочной последовательностью
    char bracketString[STRSIZE] = {'(','(','+','2',')',')'};
    int i;
    //пройдемся по массиву и проверим все скобки на наличие пары
    for (i=0; i < STRSIZE; i++)
    {
        char symb = bracketString[i];
        switch (symb) {
                //открывающие скобки положим в стэк
            case '(':
                push(symb);
                break;
                //закрывающую скобку будем проверять на наличие пары и на ее позицию. Если она единственная первая в стэке, то пары для нее мы не найдем, программу можно завершать
            case ')':
                PairCheck('(', symb);
                break;
            case '[':
                push(symb);
                break;
            case ']':
                PairCheck('[', symb);
                break;
            case '{':
                push(symb);
                break;
            case '}':
                PairCheck('{', symb);
                break;
            default:
                break;
        }
    }
    if(Stack.size == 0)
    {
         printf("The sequence is correct\n");
    }
    else
    {
        printf("The sequence is not correct\n");
    }
    PrintStack();
    
//    Задание 6
//    Реализовать очередь:
//    1. С использованием массива.
//    2. *С использованием односвязного списка.
    
    char turn[TurnSize];
    //в frontIndex храним индекс элемента который будем излекать в rearIndex индекс элемента который бодавим в массив
    int frontIndex = 0;
    int rearIndex = 0;
    // создаем указатели чтобы передать значения переменных в функции для работы с очередью
    char *arr = turn;
    int *rIndex = &rearIndex;
    int *fIndex = &frontIndex;
    // добавляем элементы в массив
    turnAdd(arr, rIndex, '0');
    turnAdd(arr, rIndex, '2');
    turnAdd(arr, rIndex, '3');
    turnAdd(arr, rIndex, '4');
    turnAdd(arr, rIndex, '5');
    turnAdd(arr, rIndex, '6');
    turnAdd(arr, rIndex, '7');
    turnAdd(arr, rIndex, '8');
    turnAdd(arr, rIndex, '9');
    turnAdd(arr, rIndex, 'a');
    // распечатаем нашу очередь
    printf("Turn:\n");
    for (int i=0; i < TurnSize; i++) {
        printf("%c ",turn[i]);
    }
    printf("\n");
    
    // извлечем элемент из очереди и распечатаем его значение
    printf("Extracted value = %c\n",turnExtract(arr, fIndex));
    printf("Extracted value = %c\n",turnExtract(arr, fIndex));
         
    return 0;
}
