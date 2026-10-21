
#include <iostream>
using namespace std;

const int MAX = 100;

// LIST BANG MANG
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

    void insertTail(int val) { // O(1)
        if (n >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }

        data[n] = val;
        n++;
    }

    int deleteHead() { // O(n)
        if (n == 0) {
            cout << "Queue rong!\n";
            return -1;
        }

        int val = data[0];

        for (int i = 0; i < n - 1; i++)
            data[i] = data[i + 1];

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

// QUEUE BANG LINKEDLIST
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

void enqueueLL(Node* &front, Node* &rear, int val) { // O(1)
    Node* p = createNode(val);

    if (rear == nullptr) {
        front = rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
}

int dequeueLL(Node* &front, Node* &rear) { // O(1)
    if (front == nullptr) {
        cout << "Queue rong!\n";
        return -1;
    }

    Node* p = front;
    int val = p->data;
    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete p;
    return val;
}

int frontLL(Node* front) { // O(1)
    if (front == nullptr) return -1;
    return front->data;
}

void duyetQueueLL(Node* front) { // O(n)
    cout << "Queue LinkedList: ";

    while (front != nullptr) {
        cout << front->data << " ";
        front = front->next;
    }

    cout << endl;
}

void giaiPhong(Node* &front, Node* &rear) { // O(n)
    while (front != nullptr) {
        Node* p = front;
        front = front->next;
        delete p;
    }

    rear = nullptr;
}

// QUEUE BANG LIST
void enqueueList(List &q, int val) { // O(1)
    q.insertTail(val);
}

int dequeueList(List &q) { // O(n)
    return q.deleteHead();
}

int frontList(List &q) { // O(1)
    if (q.isempty()) return -1;
    return q.getAt(0);
}

void duyetQueueList(List &q) { // O(n)
    cout << "Queue List: ";
    q.traverseForward();
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueueLL(front, rear, 10);
    enqueueLL(front, rear, 20);
    enqueueLL(front, rear, 30);

    duyetQueueLL(front);

    cout << "Front Queue LinkedList: "
         << frontLL(front) << endl;

    cout << "Dequeue: "
         << dequeueLL(front, rear) << endl;

    duyetQueueLL(front);
    giaiPhong(front, rear);

    cout << endl;

    List q;
    q.init();

    enqueueList(q, 10);
    enqueueList(q, 20);
    enqueueList(q, 30);

    duyetQueueList(q);

    cout << "Front Queue List: "
         << frontList(q) << endl;

    cout << "Dequeue: "
         << dequeueList(q) << endl;

    duyetQueueList(q);

    return 0;
}

