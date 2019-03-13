// Коновалов А.П.

#include <stdio.h>
#include <stdlib.h>
#define Bracket char
#define STRSIZE 6

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
    char bracketString[STRSIZE] = {'(','(','{','(',')','}'};
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
    
    return 0;
}
