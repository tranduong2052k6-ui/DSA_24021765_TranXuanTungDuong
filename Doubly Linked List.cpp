#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Khai báo cấu trúc Quản lý danh sách (giữ head, tail và size)
struct DoublyLinkedList {
    Node* head;
    Node* tail;
    int size;
};

// Khởi tạo danh sách liên kết
void initList(DoublyLinkedList &list) {
    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
}

// Tạo node mới
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// 1. Duyệt xuôi: O(n)
void duyetXuoi(DoublyLinkedList list) {
    Node* curr = list.head;
    cout << "Duyet xuoi: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// 2. Duyệt ngược: O(n)
void duyetNguoc(DoublyLinkedList list) {
    Node* curr = list.tail;
    cout << "Duyet nguoc: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

// 3. Truy cập phần tử tại vị trí index (0-indexed): O(n)
int truyCap(DoublyLinkedList list, int index) {
    if (index < 0 || index >= list.size) {
        cout << "Vi tri khong hop le!" << endl;
        return -1;
    }
    Node* curr;
    if (index < list.size / 2) {
        curr = list.head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
    } else {
        curr = list.tail;
        for (int i = list.size - 1; i > index; i--) {
            curr = curr->prev;
        }
    }
    return curr->data;
}

// 4. Chèn phần tử vào đầu: O(1)
void chenDau(DoublyLinkedList &list, int val) {
    Node* newNode = createNode(val);
    if (list.head == nullptr) {
        list.head = list.tail = newNode;
    } else {
        newNode->next = list.head;
        list.head->prev = newNode;
        list.head = newNode;
    }
    list.size++;
}

// 5. Chèn phần tử vào cuối: O(1)
void chenCuoi(DoublyLinkedList &list, int val) {
    Node* newNode = createNode(val);
    if (list.tail == nullptr) {
        list.head = list.tail = newNode;
    } else {
        list.tail->next = newNode;
        newNode->prev = list.tail;
        list.tail = newNode;
    }
    list.size++;
}

// 6. Chèn vào vị trí i: O(n)
void chenViTri(DoublyLinkedList &list, int index, int val) {
    if (index < 0 || index > list.size) {
        cout << "Vi tri chen khong hop le!" << endl;
        return;
    }
    if (index == 0) {
        chenDau(list, val);
        return;
    }
    if (index == list.size) {
        chenCuoi(list, val);
        return;
    }

    Node* newNode = createNode(val);
    Node* curr = list.head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    newNode->prev = curr->prev;
    newNode->next = curr;
    curr->prev->next = newNode;
    curr->prev = newNode;
    list.size++;
}

// 7. Xóa phần tử đầu: O(1)
void xoaDau(DoublyLinkedList &list) {
    if (list.head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* temp = list.head;
    if (list.head == list.tail) {
        list.head = list.tail = nullptr;
    } else {
        list.head = list.head->next;
        list.head->prev = nullptr;
    }
    delete temp;
    list.size--;
}

// 8. Xóa phần tử cuối: O(1)
void xoaCuoi(DoublyLinkedList &list) {
    if (list.tail == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* temp = list.tail;
    if (list.head == list.tail) {
        list.head = list.tail = nullptr;
    } else {
        list.tail = list.tail->prev;
        list.tail->next = nullptr;
    }
    delete temp;
    list.size--;
}

// 9. Xóa vị trí i: O(n)
void xoaViTri(DoublyLinkedList &list, int index) {
    if (index < 0 || index >= list.size) {
        cout << "Vi tri xoa khong hop le!" << endl;
        return;
    }
    if (index == 0) {
        xoaDau(list);
        return;
    }
    if (index == list.size - 1) {
        xoaCuoi(list);
        return;
    }

    Node* curr = list.head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    list.size--;
}

int main() {
    DoublyLinkedList list;
    initList(list);
    
    chenCuoi(list, 10);
    chenCuoi(list, 20);
    chenDau(list, 5);
    duyetXuoi(list);  // Kết quả: 5 10 20
    duyetNguoc(list); // Kết quả: 20 10 5
    
    chenViTri(list, 1, 15);
    duyetXuoi(list);  // Kết quả: 5 15 10 20
    
    cout << "Truy cap vi tri 2: " << truyCap(list, 2) << endl; // Kết quả: 10
    
    xoaDau(list);
    duyetXuoi(list);  // Kết quả: 15 10 20
    
    xoaCuoi(list);
    duyetXuoi(list);  // Kết quả: 15 10
    
    xoaViTri(list, 1);
    duyetXuoi(list);  // Kết quả: 15

    return 0;
}
