#include <iostream>
using namespace std;

char stack[50];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char x = stack[top];
    top--;
    return x;
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    return 0;
}

int main()
{
    char exp[50];
    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix expression: ";

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char x = exp[i];


        if (x >= '0' && x <= '9')
        {
            cout << x << " ";
        }


        else if (x == '(')
        {
            push(x);
        }


        else if (x == ')')
        {
            while (top != -1 && stack[top] != '(')
                cout << pop() << " ";

            if (top != -1)
                pop();
        }


        else
        {
            while (top != -1 &&
                   priority(stack[top]) >= priority(x))
            {
                cout << pop() << " ";
            }

            push(x);
        }
    }


    while (top != -1)
    {
        cout << pop() << " ";
    }

    return 0;
}
