// Коновалов А.П.

#include <stdio.h>
#include <stdlib.h>
#define Bracket char

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


int main(int argc, const char * argv[]) {

//    Задание 3
//    Написать программу, которая определяет, является ли введённая скобочная
//    последовательность правильной. Примеры правильных скобочных
//    выражений – (), ([])(), {}(), ([{}]),
//    неправильных – )(, ())({), (, ])}), ([(]), для скобок – [, (, {.
//    Например: (2+(2*2)) или [2/{5*(4+7)}]
    Stack.maxSize = 100;
    Stack.head = NULL;
    push('(');
    push('(');
    
    //TODO: Считываем символ из строки если это открвающая скобка - кладем в стек. Если закрывающая страниваем с тем что лежит в стэке если там открывающая пара - делаем поп если нет 
    char symb = ')';
    if(Stack.head->value == '(' && symb == ')')
    {
        pop();
    }
  
    printf("%c\n",Stack.head->value);
 //   push('b');

  //  PrintStack();
    
    return 0;
}
