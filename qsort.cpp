#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int l, int r) {
    int v = arr[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (arr[i] < v) i++;
        while (arr[j] > v) j--;
        if (i >= j) break;
        std::swap(arr[i++], arr[j--]);
    }
    return j;
}

void quick_sort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int q = partition(arr, l, r);
        quick_sort(arr, l, q);
        quick_sort(arr, q + 1, r);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    quick_sort(arr, 0, n);
    for (auto i : arr) {
        std::cout << i << ' ';
    }
}