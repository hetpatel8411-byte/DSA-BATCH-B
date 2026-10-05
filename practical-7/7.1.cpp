#include <iostream>
using namespace std;

int queue[5];
int front = -1;
int rear = -1;

void join(int token)
{
    if (rear == 4)
    {
        cout << "Queue is full\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = token;

    cout << "Token added: " << token << endl;
}

void serve()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Token served: " << queue[front] << endl;
    front++;
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "No tokens\n";
        return;
    }

    cout << "Front token: " << queue[front] << endl;
}

int main()
{
    join(101);
    display();

    join(102);
    display();

    join(103);
    display();

    serve();
    display();

    serve();
    display();

    return 0;
}
