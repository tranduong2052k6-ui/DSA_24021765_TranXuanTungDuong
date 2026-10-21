#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Tạo node mới
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// 1. Duyệt xuôi: O(n)
void duyetXuoi(Node* head) {
    Node* curr = head;
    cout << "Duyet xuoi: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// 2. Duyệt ngược: O(n) (phải đi đến cuối rồi duyệt ngược lại bằng prev)
void duyetNguoc(Node* head) {
    if (head == nullptr) return;
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    cout << "Duyet nguoc: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

// 3. Truy cập phần tử tại vị trí index (0-indexed): O(n)
int truyCap(Node* head, int index) {
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

// 4. Chèn phần tử vào đầu: O(1)
void chenDau(Node* &head, int val) {
    Node* newNode = createNode(val);
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

// 5. Chèn phần tử vào cuối: O(n) (vì không lưu tail nên phải duyệt tìm cuối)
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
    newNode->prev = curr;
}

// 6. Chèn vào vị trí i: O(n)
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
    while (curr != nullptr && count < index) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) { // Vị trí vượt quá kích thước
        cout << "Vi tri vuot qua kich thuoc danh sach!" << endl;
        return;
    }

    Node* newNode = createNode(val);
    newNode->prev = curr->prev;
    newNode->next = curr;
    if (curr->prev != nullptr) {
        curr->prev->next = newNode;
    }
    curr->prev = newNode;
}

// 7. Xóa phần tử đầu: O(1)
void xoaDau(Node* &head) {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// 8. Xóa phần tử cuối: O(n)
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
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->prev->next = nullptr;
    delete curr;
}

// 9. Xóa vị trí i: O(n)
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
    while (curr != nullptr && count < index) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        cout << "Vi tri khong ton tai!" << endl;
        return;
    }

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }
    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }
    delete curr;
}

int main() {
    Node* head = nullptr; // Khởi tạo danh sách rỗng
    
    chenCuoi(head, 10);
    chenCuoi(head, 20);
    chenDau(head, 5);
    duyetXuoi(head);  // Kết quả: 5 10 20
    duyetNguoc(head); // Kết quả: 20 10 5
    
    chenViTri(head, 1, 15);
    duyetXuoi(head);  // Kết quả: 5 15 10 20
    
    cout << "Truy cap vi tri 2: " << truyCap(head, 2) << endl; // Kết quả: 10
    
    xoaDau(head);
    duyetXuoi(head);  // Kết quả: 15 10 20
    
    xoaCuoi(head);
    duyetXuoi(head);  // Kết quả: 15 10
    
    xoaViTri(head, 1);
    duyetXuoi(head);  // Kết quả: 15

    return 0;
}
