#include <iostream>
using namespace std;

struct Node
{
    string name;
    Node *next;
};

Node *head = NULL;

// Add student at end
void join(string name)
{
    Node *n = new Node;
    n->name = name;

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
}

// Remove student
void leave(string name)
{
    if (head == NULL)
    {
        cout << "Circle is empty\n";
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    // If first student leaves
    if (head->name == name)
    {
        while (temp->next != head)
            temp = temp->next;

        // Only one student
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        temp->next = head->next;
        Node *del = head;
        head = head->next;
        delete del;
        return;
    }

    temp = head->next;
    prev = head;

    while (temp != head && temp->name != name)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        cout << "Student not found\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Display circle
void display()
{
    if (head == NULL)
    {
        cout << "Circle is empty\n";
        return;
    }

    Node *temp = head;

    cout << "Circle: ";

    do
    {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main()
{
    join("A");
    join("B");
    join("C");
    join("D");

    display();

    leave("C");
    display();

    join("E");
    display();

    return 0;
}
