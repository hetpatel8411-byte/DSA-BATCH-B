#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node* create(char x)
{
    Node *n = new Node;
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(Node *root)
{
    if (root == NULL)
        return;

    Node *queue[20];
    int front = 0;
    int rear = 0;

    queue[rear] = root;
    rear++;

    while (front < rear)
    {
        Node *temp = queue[front];
        front++;

        cout << temp->data << " ";

        if (temp->left != NULL)
        {
            queue[rear] = temp->left;
            rear++;
        }

        if (temp->right != NULL)
        {
            queue[rear] = temp->right;
            rear++;
        }
    }
}

int main()
{
    Node *root = create('A');

    root->left = create('B');
    root->right = create('C');

    root->left->left = create('D');
    root->left->right = create('E');

    root->right->left = create('F');
    root->right->right = create('G');

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order: ";
    levelorder(root);

    return 0;
}

