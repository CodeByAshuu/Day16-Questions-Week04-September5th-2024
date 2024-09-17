//ONLY WORKS WHEN SORTED LINKED LIST IS GIVEN

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertInSortedOrder(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
  
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data < value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter number of elements in the sorted linked list: ";
    cin >> n;

    cout << "Enter the elements of the sorted linked list: " << endl;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        insertNode(head, element);
    }
    cout << "Enter the value to be inserted: ";
    cin >> value;

    insertInSortedOrder(head, value);
  
    cout << "Updated sorted linked list: ";
    displayList(head);

    return 0;
}
