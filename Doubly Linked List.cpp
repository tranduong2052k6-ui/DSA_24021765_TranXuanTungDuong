#include <iostream>
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList() {
        while (head != nullptr) {
            deleteHead();
        }
    }
    // 1. Chèn phần tử vào đầu
    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    // 2. Chèn phần tử vào cuối
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    // 3. Chèn vào vị trí i (chỉ số tính từ 0 đến size)
    void insertAt(int i, int val) {
        if (i < 0 || i > size) {
            std::cout << "Vi tri chen khong hop le!\n";
            return;
        }
        if (i == 0) {
            insertHead(val);
            return;
        }
        if (i == size) {
            insertTail(val);
            return;
        }

        Node* curr = head;
        for (int idx = 0; idx < i; ++idx) {
            curr = curr->next;
        }
        Node* newNode = new Node(val);
        newNode->prev = curr->prev;
        newNode->next = curr;
        curr->prev->next = newNode;
        curr->prev = newNode;
        size++;
    }

    // 4. Xóa phần tử đầu
    void deleteHead() {
        if (head == nullptr) return;

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // 5. Xóa phần tử cuối
    void deleteTail() {
        if (tail == nullptr) return;

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    // 6. Xóa vị trí i
    void deleteAt(int i) {
        if (i < 0 || i >= size) {
            std::cout << "Vi tri xoa khong hop le!\n";
            return;
        }
        if (i == 0) {
            deleteHead();
            return;
        }
        if (i == size - 1) {
            deleteTail();
            return;
        }

        Node* curr = head;
        for (int idx = 0; idx < i; ++idx) {
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
    }

    // 7. Truy cập phần tử ở vị trí i
    int get(int i) const {
        if (i < 0 || i >= size) {
            std::cerr << "Chi so nam ngoai pham vi!\n";
            return -1;
        }

        Node* curr = head;
        for (int idx = 0; idx < i; ++idx) {
            curr = curr->next;
        }
        return curr->data;
    }

    // 8. Duyệt xuôi
    void traverseForward() const {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }

    // 9. Duyệt ngược
    void traverseBackward() const {
        Node* curr = tail;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->prev;
        }
        std::cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertHead(20);
    dll.insertHead(10);
    dll.insertTail(40);
    dll.insertAt(2, 30); 

    std::cout << "Duyet xuoi: ";
    dll.traverseForward();

    std::cout << "Duyet nguoc: ";
    dll.traverseBackward();

    // Truy cập phần tử
    std::cout << "Phan tu o vi tri 2: " << dll.get(2) << "\n";

    // Xóa phần tử
    dll.deleteHead();
    dll.deleteTail(); 
    dll.deleteAt(0); 

    std::cout << "Sau khi xoa: ";
    dll.traverseForward();

    return 0;
}