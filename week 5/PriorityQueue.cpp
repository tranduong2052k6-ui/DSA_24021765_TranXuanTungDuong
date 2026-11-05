#include <iostream>
using namespace std;

const int MAX = 100;

struct PriorityQueue {
    int data[MAX];
    int n;

    void init() {
        n = 0;
    }

    bool isempty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    void push(int val) {
        if (n == MAX) {
            cout << "Priority Queue da day!";
            return;
        }

        int i = n;
        data[n] = val;
        n++;

        while (i > 0 && data[(i - 1) / 2] < data[i]) {
            swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int top() {
        if (isempty()) {
            cout << "Priority Queue rong!";
            return -1;
        }

        return data[0];
    }

    void pop() {
        if (isempty()) {
            cout << "Priority Queue rong!";
            return;
        }

        data[0] = data[n - 1];
        n--;

        int i = 0;

        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && data[left] > data[largest])
                largest = left;

            if (right < n && data[right] > data[largest])
                largest = right;

            if (largest == i)
                break;

            swap(data[i], data[largest]);
            i = largest;
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.init();

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    cout << "Phan tu uu tien: " << pq.top() << endl;

    cout << "Cac phan tu theo thu tu uu tien: ";
    while (!pq.isempty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
