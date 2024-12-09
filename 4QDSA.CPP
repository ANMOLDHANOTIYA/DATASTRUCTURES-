#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comp, int &swap) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap++;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comp, int &swap) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        comp++;
        while (j >= 0 && arr[j] > key) {
            swap++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comp, int &swap) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap++;
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comp = 0, swap = 0;

    bubbleSort(arr, n, comp, swap);
    cout << "Bubble Sort - Comparisons: " << comp << ", Swaps: " << swap << endl;
    
    comp = swap = 0;
    insertionSort(arr, n, comp, swap);
    cout << "Insertion Sort - Comparisons: " << comp << ", Swaps: " << swap << endl;
    
    comp = swap = 0;
    selectionSort(arr, n, comp, swap);
    cout << "Selection Sort - Comparisons: " << comp << ", Swaps: " << swap << endl;

    return 0;
}
