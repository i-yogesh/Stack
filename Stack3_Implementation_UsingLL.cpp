#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // ~Node()
    // {
    //     if(this->next!=NULL)
    //     {
    //         delete next;
    //         this->next = NULL;
    //     }
    // }
};

Node *top = NULL;

void display()
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void push(int data)
{
    // Node(data);
    Node *newNode = new Node(data);
    if (newNode == NULL)
    {
        cout << "Stack Overflow\n";
        return;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void pop()
{
    if (top == NULL)
        cout << "Stack underflow\n";

    else
    {
        Node *temp = top;
        top = top->next;
        // free(temp);
        delete temp;
    }
}

bool isEmpty()
{
    if (top == NULL)
        return true;

    else
        return false;
}

int peek()
{
    if (top == NULL)
        return -1;

    else
        return top->data;
}
int main()
{
    push(5);
    push(40);
    push(9);
    display();
    pop();
    display();

    if (isEmpty())
        cout << "Stack Is Empty\n";
    else
        cout << "Stack Is Not Empty\n";

    cout << "Peek Element is " << peek() << endl;
    return 0;
}