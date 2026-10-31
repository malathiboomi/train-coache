#include <iostream>
using namespace std;

struct Node {
    int coach;
    Node* next;
};

Node* head = NULL;

void addBegin(int x) {
    head = new Node{x, head};
}

void addEnd(int x) {
    Node* p = new Node{x, NULL};

    if (!head) {
        head = p;
        return;
    }

    Node* t = head;
    while (t->next)
        t = t->next;

    t->next = p;
}

void removeCoach(int x) {
    Node *t = head, *prev = NULL;

    while (t && t->coach != x) {
        prev = t;
        t = t->next;
    }

    if (!t) {
        cout << "Coach not found\n";
        return;
    }

    if (!prev)
        head = t->next;
    else
        prev->next = t->next;

    delete t;
    cout << "Coach removed\n";
}

void display() {
    Node* t = head;

    while (t) {
        cout << "Coach" << t->coach << " -> ";
        t = t->next;
    }

    cout << "NULL\n";
}

int main() {
    int ch, x;

    do {
        cout << "\n1.Add beginning 2.Add end 3.Remove 4.Display 5.Exit\nChoice: ";
        cin >> ch;

        if (ch == 1 || ch == 2) {
            cout << "Coach number: ";
            cin >> x;

            if (ch == 1)
                addBegin(x);
            else
                addEnd(x);
        }
        else if (ch == 3) {
            cout << "Remove coach: ";
            cin >> x;
            removeCoach(x);
        }
        else if (ch == 4) {
            display();
        }

    } while (ch != 5);

    return 0;
}
