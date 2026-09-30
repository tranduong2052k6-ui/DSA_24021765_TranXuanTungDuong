#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
void init(List& L) {
    L.head = nullptr;
    L.tail = nullptr;
}

Node* createNode(int val) {
    Node* p = new Node;
    p->data = val;
    p->prev = nullptr;
    p->next = nullptr;
    return p;
}
// 1. Chèn phần tử vào đầu
void insertHead(List& L, int val) {
    Node* p = createNode(val);
    if (L.head == nullptr) {
        L.head = L.tail = p;
    } else {
        p->next = L.head;
        L.head->prev = p;
        L.head = p;
    }
}
// 2. Chèn phần tử vào cuối
void insertTail(List& L, int val) {
    Node* p = createNode(val);
    if (L.tail == nullptr) {
        L.head = L.tail = p;
    } else {
        L.tail->next = p;
        p->prev = L.tail;
        L.tail = p;
    }
}
// 3. Chèn vào vị trí index
void insertAt(List& L, int index, int val) {
    if (index == 0) {
        insertHead(L, val);
        return;
    }
    Node* curr = L.head;
    for (int i = 0; curr != nullptr && i < index; i++) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        insertTail(L, val);
        return;
    }
    Node* p = createNode(val);
    p->prev = curr->prev;
    p->next = curr;
    curr->prev->next = p;
    curr->prev = p;
}
// 4. Xóa phần tử đầu
void deleteHead(List& L) {
    if (L.head == nullptr) return;
    Node* temp = L.head;
    if (L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        L.head = L.head->next;
        L.head->prev = nullptr;
    }
    delete temp;
}
// 5. Xóa phần tử cuối
void deleteTail(List& L) {
    if (L.tail == nullptr) return;
    Node* temp = L.tail;
    if (L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        L.tail = L.tail->prev;
        L.tail->next = nullptr;
    }
    delete temp;
}
// 6. Xóa vị trí index
void deleteAt(List& L, int index) {
    if (L.head == nullptr || index < 0) return;
    if (index == 0) {
        deleteHead(L);
        return;
    }
    Node* curr = L.head;
    for (int i = 0; curr != nullptr && i < index; i++) {
        curr = curr->next;
    }
    if (curr == nullptr) return;
    if (curr == L.tail) {
        deleteTail(L);
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

// 7. Truy cập phần tử tại vị trí index
int getAt(const List& L, int index) {
    Node* curr = L.head;
    for (int i = 0; curr != nullptr && i < index; i++) {
        curr = curr->next;
    }
    return (curr != nullptr) ? curr->data : -1;
}

// 8. Duyệt xuôi
void traverseForward(const List& L) {
    cout << "Duyet xuoi: ";
    for (Node* curr = L.head; curr != nullptr; curr = curr->next) {
        cout << curr->data << " ";
    }
    cout << "\n";
}
// 9. Duyệt ngược
void traverseBackward(const List& L) {
    cout << "Duyet nguoc: ";
    for (Node* curr = L.tail; curr != nullptr; curr = curr->prev) {
        cout << curr->data << " ";
    }
    cout << "\n";
}
void clearList(List& L) {
    while (L.head != nullptr) {
        deleteHead(L);
    }
}

int main() {
    List L;
    init(L); // Khởi tạo danh sách

    // 1. Chèn phần tử vào đầu
    insertHead(L, 10);
    insertHead(L, 5);  // Danh sách: 5 <-> 10
    // 2. Chèn phần tử vào cuối
    insertTail(L, 20);
    insertTail(L, 30); // Danh sách: 5 <-> 10 <-> 20 <-> 30
    // 3. Chèn vào vị trí index 2 (giá trị 15)
    insertAt(L, 2, 15); // Danh sách: 5 <-> 10 <-> 15 <-> 20 <-> 30
    // 8. Duyệt xuôi & 9. Duyệt ngược
    traverseForward(L);
    traverseBackward(L);
    // 7. Truy cập phần tử tại index
    cout << "Gia tri tai vi tri index 2: " << getAt(L, 2) << "\n";
    // 4. Xóa phần tử đầu
    deleteHead(L);     // Xóa 5 -> Còn: 10 <-> 15 <-> 20 <-> 30
    cout << "Sau khi xoa dau:\n";
    traverseForward(L);
    // 5. Xóa phần tử cuối
    deleteTail(L);
    cout << "Sau khi xoa cuoi:\n";
    traverseForward(L);
    // 6. Xóa tại vị trí index 1 (xóa số 15)
    deleteAt(L, 1);    
    cout << "Sau khi xoa tai index 1:\n";
    traverseForward(L);

    clearList(L);

    return 0;
}