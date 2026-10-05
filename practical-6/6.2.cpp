#include <iostream>
using namespace std;

struct Node
{
    int page;
    Node *next;
};

Node *top = NULL;

void visit(int page)
{
    Node *n = new Node;

    n->page = page;
    n->next = top;

    top = n;

    cout << "Visited page: " << page << endl;
}

void back()
{
    if (top == NULL)
    {
        cout << "No history\n";
        return;
    }

    cout << "Going back from page: " << top->page << endl;

    Node *temp = top;
    top = top->next;

    delete temp;
}

void display()
{
    if (top == NULL)
    {
        cout << "No page\n";
        return;
    }

    cout << "Current page: " << top->page << endl;
}

int main()
{
    visit(1);
    display();

    visit(2);
    display();

    visit(3);
    display();

    back();
    display();

    back();
    display();

    return 0;
}
