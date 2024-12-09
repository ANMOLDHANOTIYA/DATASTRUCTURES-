#include <iostream>
#include <cstring>
using namespace std;

struct Contact {
    char name[100];
    char number[15];
};

struct Node {
    Contact data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    void addAtBeg(Contact x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    void append(Contact x) {
        Node
