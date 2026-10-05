#include <iostream>
using namespace std;

struct Node
{
    string song;
    Node *prev;
    Node *next;
};

Node *head = NULL;

// Add at beginning
void addFirst(string s)
{
    Node *n = new Node;
    n->song = s;
    n->prev = NULL;
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
}

// Add at end
void addLast(string s)
{
    Node *n = new Node;
    n->song = s;
    n->next = NULL;

    if (head == NULL)
    {
        n->prev = NULL;
        head = n;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// Insert after a song
void insertAfter(string oldSong, string newSong)
{
    Node *temp = head;

    while (temp != NULL && temp->song != oldSong)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Song not found\n";
        return;
    }

    Node *n = new Node;
    n->song = newSong;

    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}

// Remove first song
void removeFirst()
{
    if (head == NULL)
    {
        cout << "Playlist is empty\n";
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Count songs
void countSongs()
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total songs = " << count << endl;
}

// Display playlist
void display()
{
    Node *temp = head;

    cout << "Playlist: ";

    while (temp != NULL)
    {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    addFirst("Song1");
    addLast("Song2");
    addLast("Song3");

    display();

    insertAfter("Song2", "Song4");
    display();

    countSongs();

    removeFirst();
    display();

    return 0;
}
