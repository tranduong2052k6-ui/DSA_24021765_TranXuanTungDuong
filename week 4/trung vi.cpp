
#include <iostream>
#include <algorithm>
using namespace std;

// Tim trung vi
int findMedian(int a[], int n) {
    sort(a, a + n);
    return a[n / 2];
}

int main() {
    int a[100];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 0 || n % 2 == 0) {
        cout << "Mang phai co so phan tu le!";
    }
    else {
        cout << "Trung vi la: " << findMedian(a, n);
    }

    return 0;
}

