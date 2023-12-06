#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    cout << "List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to sort the linked list using bubble sort
void bubbleSort(Node* head) {
    if (!head || !head->next) {
        return; // Empty or single-node list is already sorted
    }

    bool swapped;
    Node* temp;

    do {
        swapped = false;
        temp = head;

        while (temp->next) {
            if (temp->data > temp->next->data) {
                // Swap data if out of order
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

int main() {
    Node* head = nullptr;
    int n, num;

    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> num;
        insert(head, num);
    }

    cout << "\nBefore sorting:\n";
    printList(head);

    bubbleSort(head);

    cout << "\nAfter sorting:\n";
    printList(head);

    return 0;
}