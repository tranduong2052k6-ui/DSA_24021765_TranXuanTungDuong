
#include <iostream>
using namespace std;

const int MAX = 100;

struct List {
    int data[MAX];
    int n;

    void init() {
        n = 0;
    }

    int getAt(int i) {
        if (i < 0 || i >= n) {
            cout << "Vi tri khong hop le!\n";
            return -1;
        }
        return data[i];
    }

    void insertHead(int val) {
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

    void insertTail(int val) {
        if (n >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }

        data[n] = val;
        n++;
    }

    void insertAt(int i, int val) {
        if (i < 0 || i > n) {
            cout << "Vi tri them khong hop le!\n";
            return;
        }

        if (n >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }

        for (int j = n; j > i; j--) {
            data[j] = data[j - 1];
        }

        data[i] = val;
        n++;
    }

    void deleteHead() {
        if (n <= 0) {
            cout << "Danh sach rong!\n";
            return;
        }

        for (int i = 0; i < n - 1; i++) {
            data[i] = data[i + 1];
        }

        n--;
    }

    int deleteTail() {
        if (n <= 0) {
            cout << "Danh sach rong!\n";
            return -1;
        }

        return data[--n];
    }

    void deleteAt(int i) {
        if (i < 0 || i >= n) {
            cout << "Vi tri xoa khong hop le!\n";
            return;
        }

        for (int j = i; j < n - 1; j++) {
            data[j] = data[j + 1];
        }

        n--;
    }

    void traverseForward() {
        cout << "Duyet xuoi: ";

        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    void traverseBackward() {
        cout << "Duyet nguoc: ";

        for (int i = n - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    bool isempty() {
        return n == 0;
    }

    int size() {
        return n;
    }
};

int main() {
    List L;
    L.init();

    L.insertTail(10);
    L.insertTail(20);
    L.insertTail(30);
    L.traverseForward();

    L.insertHead(5);
    L.traverseForward();

    L.insertAt(2, 15);
    L.traverseForward();

    cout << "Phan tu tai vi tri 2: "
         << L.getAt(2) << endl;

    L.deleteHead();
    L.traverseForward();

    cout << "Phan tu vua xoa o cuoi: "
         << L.deleteTail() << endl;
    L.traverseForward();

    L.deleteAt(1);
    L.traverseForward();

    L.traverseBackward();

    cout << "So phan tu: " << L.size() << endl;
    cout << "Danh sach rong: "
         << (L.isempty() ? "Co" : "Khong") << endl;

    return 0;
}
