#include <iostream>
using namespace std;

// Define the Node class
class Node{
public:
    int data;
    Node *next;
};

// Add a new Node to the beginning of the Linked List
void addToHead(Node **x, int value)
{
    Node *newNode = new Node(); // create a new Node object
    newNode->data = value;      // assign the given value to the new Node's data field
    newNode->next = *x;         // make the new Node's next pointer point to the current head
    *x = newNode;               // update the head to point to the new Node
}

int main()
{

    int A[] = {3, 5, 7, 10, 15};

    Node *head = new Node; // create a new Node object and assign it to the head pointer
                           // head now points to the first 'Node' object in the linked list

    Node *temp;
    Node *last;
    Node *first;
    head->data = A[0];    // set the first Node's data to the first element of the given array
    head->next = nullptr; // set the first Node's next pointer to null
    last = head;          // initialize the 'last' pointer to point to the first Node

    // Create the rest of the Linked List
    for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++)
    {

        // Create a temporary Node
        temp = new Node;

        // Populate the temporary Node
        temp->data = A[i];
        temp->next = nullptr;

        // Make the last Node's next pointer point to the new Node
        last->next = temp;
        last = temp; // update the 'last' pointer to point to the new Node
    }

    Node *x = NULL;

    // Add new Nodes to the beginning of the Linked List
    addToHead(&x, 5);
    addToHead(&x, 10);
    addToHead(&x, 15);

    // Display the Linked List
    Node *p = head;

    while (p != nullptr)
    {
        cout << p->data << " -> " << flush;
        p = p->next;
    }

    return 0;
}
