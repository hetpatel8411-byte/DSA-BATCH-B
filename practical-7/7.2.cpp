#include <iostream>
using namespace std;

struct Node
{
    int patient;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void arrive(int patient)
{
    Node *n = new Node;

    n->patient = patient;
    n->next = NULL;

    if (rear == NULL)
    {
        front = rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }

    cout << "Patient arrived: " << patient << endl;
}

void attend()
{
    if (front == NULL)
    {
        cout << "No patients waiting\n";
        return;
    }

    Node *temp = front;

    cout << "Patient attended: " << front->patient << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void display()
{
    if (front == NULL)
    {
        cout << "No patients waiting\n";
        return;
    }

    cout << "Front patient: " << front->patient << endl;
}

int main()
{
    arrive(101);
    display();

    arrive(102);
    display();

    arrive(103);
    display();

    attend();
    display();

    attend();
    display();

    attend();
    display();

    attend();

    return 0;
}
