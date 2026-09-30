#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

// 1. Chèn phần tử vào đầu
void insertHead(Node*& head, int val) {
    Node* p = new Node{val, head};
    head = p;
}

// 2. Chèn phần tử vào cuối
void insertTail(Node*& head, int val) {
    Node* p = new Node{val, nullptr};
    if (head == nullptr) {
        head = p;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = p;
}

// 3. Chèn vào vị trí index bất kì
void insertAt(Node*& head, int index, int val) {
    if (index <= 0 || head == nullptr) {
        insertHead(head, val);
        return;
    }
    Node* curr = head;
    for (int i = 0; curr->next != nullptr && i < index - 1; i++) {
        curr = curr->next;
    }
    Node* p = new Node{val, curr->next};
    curr->next = p;
}

// 4. Xóa phần tử đầu
void deleteHead(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// 5. Xóa phần tử cuối 
void deleteTail(Node*& head) {
    if (head == nullptr) return;
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

// 6. Xóa phần tử tại vị trí index bất kì
void deleteAt(Node*& head, int index) {
    if (head == nullptr || index < 0) return;
    if (index == 0) {
        deleteHead(head);
        return;
    }
    Node* curr = head;
    for (int i = 0; curr->next != nullptr && i < index - 1; i++) {
        curr = curr->next;
    }
    if (curr->next == nullptr) return;

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

// 7. Truy cập phần tử tại vị trí index
int getAt(Node* head, int index) {
    Node* curr = head;
    for (int i = 0; curr != nullptr && i < index; i++) {
        curr = curr->next;
    }
    return (curr != nullptr) ? curr->data : -1;
}

// 8. Duyệt xuôi
void printForward(Node* head) {
    cout << "Duyet xuoi: ";
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        cout << curr->data << " ";
    }
    cout << "\n";
}


void printBackwardHelper(Node* head) {
    if (head == nullptr) return;
    printBackwardHelper(head->next);
    cout << head->data << " ";
}

// 9. Duyệt ngược 
void printBackward(Node* head) {
    cout << "Duyet nguoc: ";
    printBackwardHelper(head);
    cout << "\n";
}


void clearList(Node*& head) {
    while (head != nullptr) {
        deleteHead(head);
    }
}

int main() {
    Node* head = nullptr; 


    insertHead(head, 20);    
    insertHead(head, 10);    
    insertTail(head, 40);     
    insertAt(head, 2, 30);    

  
    printForward(head);
    printBackward(head);

    cout << "Gia tri tai vi tri 2: " << getAt(head, 2) << "\n";

    deleteHead(head);
    cout << "Sau khi xoa dau: ";
    printForward(head);

    deleteTail(head);
    cout << "Sau khi xoa cuoi: ";
    printForward(head);

    deleteAt(head, 1);
    cout << "Sau khi xoa vi tri 1: ";
    printForward(head);
    clearList(head);

    return 0;
}