
#include <iostream>
using namespace std;

const int MAX = 100;

struct List {
    int data[MAX];
    int n;

    void init() { // O(1)
        n = 0;
    }
    bool isempty() { // O(1)
        return n == 0;
    }

    int size() { // O(1)
        return n;
    }
    void insertHead(int val) { // O(n)
        if (n >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }

        for (int i = n; i > 0; i--) {
            data[i] = data[i - 1];
        }

        data[0] = val;
        n++;
    }
    int deleteHead() { // O(n)
        if (n == 0) {
            cout << "Stack rong!\n";
            return -1;
        }

        int val = data[0];

        for (int i = 0; i < n - 1; i++) {
            data[i] = data[i + 1];
        }

        n--;
        return val;
    }

    int getAt(int i) { // O(1)
        if (i < 0 || i >= n) return -1;
        return data[i];
    }

    void traverseForward() { // O(n)
        for (int i = 0; i < n; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};
// STACK BANG LINKEDLIST
struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) { // O(1)
    Node* p = new Node;
    p->data = val;
    p->next = nullptr;
    return p;
}

void pushLL(Node* &top, int val) { // O(1)
    Node* p = createNode(val);
    p->next = top;
    top = p;
}

int popLL(Node* &top) { // O(1)
    if (top == nullptr) {
        cout << "Stack rong!\n";
        return -1;
    }

    Node* p = top;
    int val = p->data;
    top = top->next;
    delete p;
    return val;
}

int peekLL(Node* top) { // O(1)
    if (top == nullptr) return -1;
    return top->data;
}

void duyetStackLL(Node* top) { // O(n)
    cout << "Stack LinkedList: ";
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

void giaiPhong(Node* &top) { // O(n)
    while (top != nullptr) {
        Node* p = top;
        top = top->next;
        delete p;
    }
}

// STACK BANG LIST
void pushList(List &s, int val) { // O(n)
    s.insertHead(val);
}

int popList(List &s) { // O(n)
    return s.deleteHead();
}

int peekList(List &s) { // O(1)
    if (s.isempty()) return -1;
    return s.getAt(0);
}

void duyetStackList(List &s) { // O(n)
    cout << "Stack List: ";
    s.traverseForward();
}

int main() {
    Node* top = nullptr;

    pushLL(top, 10);
    pushLL(top, 20);
    pushLL(top, 30);

    duyetStackLL(top);
    cout << "Top Stack LinkedList: " << peekLL(top) << endl;
    cout << "Pop: " << popLL(top) << endl;
    duyetStackLL(top);
    giaiPhong(top);

    cout << endl;
    List s;
    s.init();

    pushList(s, 10);
    pushList(s, 20);
    pushList(s, 30);

    duyetStackList(s);
    cout << "Top Stack List: " << peekList(s) << endl;
    cout << "Pop: " << popList(s) << endl;
    duyetStackList(s);

    return 0;
}

