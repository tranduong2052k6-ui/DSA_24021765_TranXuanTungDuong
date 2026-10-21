#include <iostream>

using namespace std;

// Khai báo cấu trúc một Node trong Singly Linked List
struct Node {
    int data;
    Node* next;
};

// Tạo node mới
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
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

// 2. Duyệt ngược: O(n) (Sử dụng đệ quy để in từ cuối về đầu)
void duyetNguocRec(Node* curr) {
    if (curr == nullptr) return;
    duyetNguocRec(curr->next);
    cout << curr->data << " ";
}

void duyetNguoc(Node* head) {
    cout << "Duyet nguoc: ";
    duyetNguocRec(head);
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
    newNode->next = head;
    head = newNode;
}

// 5. Chèn phần tử vào cuối: O(n)
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
    // Tìm node đứng trước vị trí index (vị trí index - 1)
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

// 7. Xóa phần tử đầu: O(1)
void xoaDau(Node* &head) {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
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
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
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
    // Tìm node đứng trước vị trí cần xóa (index - 1)
    while (curr != nullptr && count < index - 1) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr || curr->next == nullptr) {
        cout << "Vi tri khong ton tai!" << endl;
        return;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

int main() {
    Node* head = nullptr; // Khởi tạo danh sách liên kết đơn rỗng
    
    chenCuoi(head, 10);
    chenCuoi(head, 20);
    chenDau(head, 5);
    duyetXuoi(head);  // Kết quả: 5 10 20
    duyetNguoc(head); // Kết quả: 20 10 5 (dùng đệ quy in ngược)
    
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
