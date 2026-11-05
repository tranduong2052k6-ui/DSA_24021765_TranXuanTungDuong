
#include <iostream>
#include <algorithm>
using namespace std;

// Phan hoach mang
int partition(int a[], int l, int r) {
    int pivot = a[l];
    int i = l + 1;
    int j = r;

    while (i <= j) {
        while (i <= r && a[i] <= pivot)
            i++;

        while (j >= l + 1 && a[j] > pivot)
            j--;

        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    swap(a[l], a[j]);
    return j;
}

// Thuat toan Quick Sort
void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);

        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main() {
    int a[100]; 
    int n ;
    cin >> n;
    for(int i=0; i < n; i++) {
    	cin >> a[i];
	}

    quickSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

