#include <iostream>
using namespace std;

struct Node {
    int data;
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

    void addAtBeg(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    void append(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addAtPOS(int x, int pos) {
        if (pos < 1 || pos > getLength() + 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1) {
            addAtBeg(x);
        } else {
            Node* newNode = new Node();
            newNode->data = x;
            Node* temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void removeFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeLast() {
        if (head) {
            if (!head->next) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next && temp->next->next) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
            }
        }
    }

    void removePOS(int pos) {
        if (pos < 1 || pos > getLength()) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1) {
            removeFirst();
        } else {
            Node* temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayMORE() {
        Node* temp = head;
        while (temp) {
            cout << "Data: " << temp->data << ", Address: " << temp << ", Next Address: " << temp->next << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    list.addAtBeg(3);
    list.append(4);
    list.addAtPOS(7, 2);
    list.display();
    list.removeFirst();
    list.display();
    list.removeLast();
    list.display();
    list.displayMORE();
    return 0;
}
