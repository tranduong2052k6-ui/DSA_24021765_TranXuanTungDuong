#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

void duyet(Node* head) {
    Node* curr = head;
    cout << "Danh sach: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int truyCap(Node* head, int index) {
    if (index < 0) {
        cout << "Vi tri khong hop le!" << endl;
        return -1;
    }

    Node* curr = head;
    int count = 0;

    while (curr != nullptr) {
        if (count == index) return curr->data;
        curr = curr->next;
        count++;
    }

    cout << "Vi tri khong hop le!" << endl;
    return -1;
}

void chenDau(Node* &head, int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

void chenCuoi(Node* &head, int val) {
    Node* newNode = createNode(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
}

void chenViTri(Node* &head, int index, int val) {
    if (index < 0) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    if (index == 0) {
        chenDau(head, val);
        return;
    }

    Node* curr = head;
    int count = 0;

    while (curr != nullptr && count < index - 1) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        cout << "Vi tri vuot qua kich thuoc danh sach!" << endl;
        return;
    }

    Node* newNode = createNode(val);
    newNode->next = curr->next;
    curr->next = newNode;
}

void xoaDau(Node* &head) {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void xoaCuoi(Node* &head) {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* curr = head;

    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
}

void xoaViTri(Node* &head, int index) {
    if (head == nullptr || index < 0) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    if (index == 0) {
        xoaDau(head);
        return;
    }

    Node* curr = head;
    int count = 0;

    while (curr->next != nullptr && count < index - 1) {
        curr = curr->next;
        count++;
    }

    if (curr->next == nullptr) {
        cout << "Vi tri khong ton tai!" << endl;
        return;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

void giaiPhong(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    chenCuoi(head, 10);
    chenCuoi(head, 20);
    chenDau(head, 5);
    duyet(head);

    chenViTri(head, 1, 15);
    duyet(head);

    cout << "Truy cap vi tri 2: "
         << truyCap(head, 2) << endl;

    xoaDau(head);
    duyet(head);

    xoaCuoi(head);
    duyet(head);

    xoaViTri(head, 1);
    duyet(head);

    giaiPhong(head);

    return 0;
}
