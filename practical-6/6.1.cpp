#include <iostream>
using namespace std;

int stack[5];
int top = -1;

void push(int tray)
{
    if (top == 4)
    {
        cout << "Stack is full\n";
        return;
    }

    top++;
    stack[top] = tray;
    cout << "Tray placed: " << tray << endl;
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Tray taken: " << stack[top] << endl;
    top--;
}

void display()
{
    if (top == -1)
    {
        cout << "No trays\n";
        return;
    }

    cout << "Top tray: " << stack[top] << endl;
}

int main()
{
    push(10);
    display();

    push(20);
    display();

    push(30);
    display();

    pop();
    display();

    pop();
    display();

    return 0;
}
