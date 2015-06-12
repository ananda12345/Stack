#include <iostream>

struct Stack
{
    int value;
    Stack *current;
};

Stack *FirstElement(int x)
{
    Stack *First = new Stack;
    First->value = x;
    First->current = 0;
    return First;
}

void push(Stack **top, int x)
{
    Stack *Element = new Stack;
    Element->value = x;
    Element->current = *top;
    *top = Element;
}

int pop(Stack **top)
{
    int n = (*top)->value;
    Stack *Element = *top;
    *top = (*top)->current;
    free(Element);
    return n;
}

int main()
{
    Stack *top = FirstElement(0);
    for (int i=1; i<8; i++) {
        push(&top, i);
    }
    while (top) {
        std::cout<<pop(&top);
    }
    std::cin.get();
    return 0;
}

