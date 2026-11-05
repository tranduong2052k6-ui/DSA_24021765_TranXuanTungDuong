
#include <iostream>
using namespace std;

// Tron hai mang con
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int x[100], y[100];

    for (int i = 0; i < n1; i++)
        x[i] = a[l + i];

    for (int j = 0; j < n2; j++)
        y[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (x[i] <= y[j]) {
            a[k] = x[i];
            i++;
        }
        else {
            a[k] = y[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = x[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = y[j];
        j++;
        k++;
    }
}

// Thuat toan Merge Sort
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main() {
    int a[100];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

